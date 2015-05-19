email:christopher_burbine@student.uml.edu

I used the OpenGL Library for my exploration can be found here: 
http://docs.racket-lang.org/sgl/index.html 

Over all most of what I have done with this library is create shapes using 
OpenGL functions. My first file "rectangle.rkt" builds a rectangle from two 
triangles. OpenGL is very good at drawing triangles and many of the objects 
it creates are simply a bunch of triangles stuck together. My next file is 
something of a similar concept. The file "circle.rkt" creates a circle by 
folding together many small triangles.

As a note I have been attempting to get some amount of animation with these 
examples but with not luck. It looks as though the drawn object has to be built 
in a certain way, but I am unsure what that way is because there is not a lot 
of OpenGL in Racket documentation or examples. That being said there are a lot 
of OpenGL C/C++ examples, but these use newer OpenGL functions not included in 
the racket version. 
