0:mar := pc; rd;                                { main loop  }
1:pc := 1 + pc; rd;                             { increment pc }
2:ir := mbr; if n then goto 28;                 { save, decode mbr }
3:tir := lshift(ir + ir); if n then goto 19;
4:tir := lshift(tir); if n then goto 11;        { 000x or 001x? }
5:alu := tir; if n then goto 9;                 { 0000 or 0001? }
6:mar := ir; rd;                                { 0000 = LODD }
7:rd;
8:ac := mbr; goto 0;
9:mar := ir; mbr := ac; wr;                     { 0001 = STOD }
10:wr; goto 0;
11:alu := tir; if n then goto 15;               { 0010 or 0011? }
12:mar := ir; rd;                               { 0010 = ADDD }
13:rd;
14:ac := ac + mbr; goto 0;
15:mar := ir; rd;                               { 0011 = SUBD }
16:ac := 1 + ac; rd;                            { Note: x - y = x + 1 + not y }
17:a := inv(mbr);
18:ac := a + ac; goto 0;
19:tir := lshift(tir); if n then goto 25;       { 010x or 011x? }
20:alu := tir; if n then goto 23;               { 0100 or 0101? }
21:alu := ac; if n then goto 0;                 { 0100 = JPOS }
22:pc := band(ir, amask); goto 0;               { perform the jump }
23:alu := ac; if z then goto 22;                { 0101 = JZER }
24:goto 0;                                      { jump failed }
25:alu := tir; if n then goto 27;               { 0110 or 0111? }
26:pc := band(ir, amask); goto 0;               { 0110 = JUMP }
27:ac := band(ir, amask); goto 0;               { 0111 = LOCO }
28:tir := lshift(ir + ir); if n then goto 40;   { 10xx or 11xx? }
29:tir := lshift(tir); if n then goto 35;       { 100x or 101x? }
30:alu := tir; if n then goto 33;               { 1000 or 1001? }
31:a := sp + ir;                                { 1000 = LODL }
32:mar := a; rd; goto 7;
33:a := sp + ir;                                { 1001 = STOL }
34:mar := a; mbr := ac; wr; goto 10;
35:alu := tir; if n then goto 38;               { 1010 or 1011? }
36:a := sp + ir;                                { 1010 = ADDL }
37:mar := a; rd; goto 13;
38:a := sp + ir;                                { 1011 = SUBL }
39:mar := a; rd; goto 16;
40:tir := lshift(tir); if n then goto 46;       { 110x or 111x? }
41:alu := tir; if n then goto 44;               { 1100 or 1101? }
42:alu := ac; if n then goto 22;                { 1100 = JNEG }
43:goto 0;
44:alu := ac; if z then goto 0;                 { 1101 = JNZE }
45:pc := band(ir, amask); goto 0;
46:tir := lshift(tir); if n then goto 50;
47:sp := sp + (-1);                             { 1110 = CALL }
48:mar := sp; mbr := pc; wr;
49:pc := band(ir, amask); wr; goto 0;
50:tir := lshift(tir); if n then goto 65;       { 1111, examine addr }
51:tir := lshift(tir); if n then goto 59;
52:alu := tir; if n then goto 56;
53:mar := ac; rd;                               { 1111000 = PSHI }
54:sp := sp + (-1); rd;
55:mar := sp; wr; goto 10;
56:mar := sp; sp := sp + 1; rd;                 { 1111001 = POPI }
57:rd;
58:mar := ac; wr; goto 10;
59:alu := tir; if n then goto 62;
60:sp := sp + (-1);                             { 1111010 = PUSH }
61:mar := sp; mbr := ac; wr; goto 10;
62:mar := sp; sp := sp + 1; rd;                 { 1111011 = POP }
63:rd;
64:ac := mbr; goto 0;
65:tir := lshift(tir); if n then goto 73;
66:alu := tir; if n then goto 70;
67:mar := sp; sp := sp + 1; rd;                 { 1111100 = RETN }
68:rd;
69:pc := mbr; goto 0;
70:a := ac;                                     { 1111101 = SWAP }
71:ac := sp;
72:sp := a; goto 0;
73:alu := tir; if n then goto 76;
74:a := band(ir, smask);                        { 1111110 = INSP }
75:sp := sp + a; goto 0;
76:tir := tir + tir; if n then goto 80;
77:a := band(ir, smask);                        { 11111110 = DESP }
78:a := inv(a);
79:a := a + 1; goto 75;
80:tir := tir + tir; if n then goto 112;        { if 1111 1111 1x }
81:alu := tir + tir; if n then goto 104;        { 1111 1111 01 = RSHIFT }
82:f := rshift(smask);                          { 1111 1111 00 = MULT }
83:f := rshift(f);                              { f is now a 6 bit mask }
84:a := band(f, ir); if n then goto 89;         { a is now has the mult value 0-63, checks if neg }
85:mar := sp; b := 0; rd;                       { getting value from top of stack }
86:d := 0;  rd;
87:c := mbr; if n then goto 91;                 { c has value from stack, checks if neg }
88:goto 93;
89:a := inv(a);                                 { if a is neg inverts and cont. }
90:d := d + 1; goto 85;                         { d used as a check, if = 0 result is pos else neg }
91:c := inv(c);                                 { if c is neg inv and cont. }
92:d := d + (-1);
93:b := b + c;                                  { we add c to b }
94:a := a + (-1);                               { we add a times }
95:alu := a; if z then goto 97;                 { when a = 0 we jump out of the loop }
96:goto 93;                                     { otherwise we continue the loop }
97:alu := b; if n then goto 103;                { when we have the product, we check for overflow (neg) }
98:alu := d; if z then goto 100;                { we check to see if d = 0, if so then our product is pos }
99:b := inv(b);                                 { only comes here is d is not = 0 }
100:mar := sp; mbr := b; wr;                    { at this point b is valid, either pos or neg }
101:wr;                                         { we do not move the sp, over rides orginal value on stack }
102:ac := 0; goto 0;                            { ac set to 0 and we jump to top of main loop }
103:ac := -1; goto 0;                           { only get here if b OV, ac set to -1, jump to top of main loop }
104:a := lshift(1);                             { 1111 1111 01 = RSHIFT }
105:a := lshift(a + 1);
106:a := lshift(a + 1);
107:a := a + 1;
108:b := band(ir, a);
109:b := b + (-1); if n then goto 111;
110:ac := rshift(ac); goto 109;
111:goto 0;
112:tir := tir + tir; if n then goto 157;       { 1111 1111 10 or 1111 1111 11? }
113:mar := sp; a := sp + 1; rd;                 { 1111 1111 10 = DIV }
114:f := 0; rd;                                 { 113 gets numerator, a is set to next val }
115:mar := a; b := mbr; rd;                     { gets denominator, b set to numerator }
116:rd;
117:c := mbr; if z then goto 134;               { c set to denominator, if 0 jumps }
118:alu := b; if n then goto 121;               { lines 118 ans 119 check for negs }
119:alu := c; if n then goto 123;
120:goto 125;                                   { jumps if neither neg }
121:b := inv(b);                                { inverts b if neg, jumps to c neg check }
122:f := f + 1; goto 119;                       { f used as quotient neg check, 0 if pos else neg }
123:c := inv(c);                                { inverts c if neg }
124:f := f + (-1);
125:e := b + 1;                                 { x - y = x + 1 + inv(y), if result if neg numer < denom }
126:d := inv(c);
127:e := e + d; if n then goto 129;
128:goto 139;                                   { jumps over denom > numer and denom = 0 results }
129:sp := sp + (-1);                            { sp now pointing to denom val }
130:mar := sp; mbr := b; wr;                    { sets denom spot to numer }
131:ac := 0; wr;
132:sp := sp + (-1);                            { sp now pointing at old numer spot }
133:mar := sp; mbr := 0; wr; goto 10;           { sets numer set to 0, jumps to 10 which jumps to main loop }
134:sp := sp + (-1);                            { sp now pointing to denom val }
135:mar := sp; mbr := -1; wr;                   { denom spot set to -1, denom = 0 in this case }
136:ac := -1; wr;
137:sp := sp + (-1);
138:mar := sp; mbr := 0; wr; goto 10;
139:a := 0;                                     { resets a to 0, a will be the quotient }
140:d := b;                                     { sets d to b, d will be the remainder }
141:e := 0;                                     { resets e to 0 }
142:ac := f;                                    { ac is set to f so f can be set to inv of c }
143:f := inv(c);
144:e := d + f; if n then goto 148;             { jumps if the reminder > the denom }
145:a := a + 1;                                 { add 1 to the quotien if d > or = c }
146:d := d + f;                                 { remainder has the denom subed from it }
147:goto 144;
148:alu := ac; if z then goto 150;               { if f = 0 quot is pos else neg }
149:a := inv(a);
150:sp := sp + (-1);                            { moves sp up 1 for remainder }
151:mar := sp; mbr := d; wr;
152:wr;
153:sp := sp + (-1);                            { moves sp up 1 again for quot }
154:mar := sp; mbr := a; wr;
155:wr;
156:ac := 0; goto 0;                            { sets ac to 0 jumps to top of main loop }
157:rd; wr;                                     { 1111 1111 11 = HALT }
