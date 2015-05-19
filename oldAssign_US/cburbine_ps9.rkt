#lang racket

;; Allow name nil to be used for the empty list.
(define nil '()) 			

;; Some other constants with non-traditional names:
(define true #t)
(define false #f)

;; For stream programming section 3.5
;; We use a force and delay which are slightly
;; different from the force and delay defined in the book:
;; delay (aka make-promise) handles recursive forcing.

(define the-empty-stream '())

(define stream-null? null?)

(define stream-car car)

(define (stream-cdr s)
  (force (cdr s)))

(define-syntax cons-stream
  (syntax-rules ()
    ((_ head tail)
     (cons head (delay tail)))))


(define (stream-ref a n)
  (if (= n 0)
      (stream-car a)
      (stream-ref (stream-cdr a) (- n 1))))

(define (stream-map proc s)
  (if (stream-null? s)
      the-empty-stream
      (cons-stream (proc (stream-car s))
                   (stream-map proc (stream-cdr s)))))

(define (stream-for-each proc s)
  (if (stream-null? s)
      'done
      (begin (proc (stream-car s))
             (stream-for-each proc (stream-cdr s)))))

(define (display-stream s)
  (stream-for-each display-line s))

(define (display-line x)
  (newline)
  (display x))

(define (stream-enumerate-interval low high)
  (if (> low high)
      the-empty-stream
      (cons-stream
       low
       (stream-enumerate-interval (+ low 1) high))))

(define (stream-filter pred stream)
  (cond ((stream-null? stream) the-empty-stream)
        ((pred (stream-car stream))
         (cons-stream (stream-car stream)
                      (stream-filter pred
                                     (stream-cdr stream))))
        (else (stream-filter pred (stream-cdr stream)))))

(define (integers-starting-from n)
  (cons-stream n (integers-starting-from (+ n 1))))

(define integers (integers-starting-from 1))

(define (sum-primes-iter a b)
  (define (iter count accum)
    (cond ((> count b) accum)
          ((prime? count) (iter (+ count 1) (+ count accum)))
          (else (iter (+ count 1) accum))))
  (iter a 0))

(define (sum-primes a b)
  (accum + 
         0
         (filter prime? (enumerate-interval a b))))

(define (accum op base lst)
  (if (null? lst) base
      (op (car lst)
          (accum op base (cdr lst)))))

(define (enumerate-interval low high)
  (if (> low high) '()
      (cons low (enumerate-interval (+ low 1) high))))

(define (stream-sum-primes a b)
  (stream-accum +
                0
                (stream-filter prime? (stream-enumerate-interval a b))))

(define (stream-accum op base stream)
  (if (stream-null? stream) base
      (op (stream-car stream)
          (stream-accum op base (stream-cdr stream)))))
  

(define (smallest-divisor n)
  (find-divisor n 2))
(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
        ((divides? test-divisor n) test-divisor)
        (else (find-divisor n (+ test-divisor 1)))))
(define (divides? a b)
  (= (remainder b a) 0))

(define (prime? n)
  (= n (smallest-divisor n)))

(define (square n)
  (* n n))

(define (fibgen a b)
  (cons-stream a (fibgen b (+ a b))))
(define fibs (fibgen 0 1))

(define (divisible? x y) (= (remainder x y) 0))
(define no-sevens
  (stream-filter (lambda (x) (not (divisible? x 7)))
                 integers))

(define (sieve stream)
  (cons-stream
   (stream-car stream)
   (sieve (stream-filter
           (lambda (x)
             (not (divisible? x (stream-car stream))))
           (stream-cdr stream)))))

(define primes (sieve (integers-starting-from 2)))

;----------------------------------------------------------------------

;Problem 1: Exercise 3.1
(define (make-accum init)
  (let ((accum init))
    (lambda (add)
      (set! accum (+ accum add))
      accum)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Problem 2: Exercise 3.2
(define (make-monit proc)
  (let ((call-count 0))
    (lambda (m)
      (cond ((eq? m 'how-many-calls?) call-count)
            ((eq? m 'reset-count) (set! call-count 0))
            (else (set! call-count (+ 1 call-count)) (proc m))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Problem 3: Exercise 3.3 
; make-account as seen in the book

;(define (make-account balance)
;  (define (withdraw amount)
;    (if (>= balance amount)
;        (begin (set! balance (- balance amount))
;               balance)
;        "Insufficient funds"))
;  (define (deposit amount)
;    (set! balance (+ balance amount))
;    balance)
;  (define (dispatch m)
;    (cond ((eq? m 'withdraw) withdraw)
;          ((eq? m 'deposit) deposit)
;          (else (error "Unknown request -- MAKE-ACCOUNT"
;                       m))))
;  dispatch)
(define (make-account balance password)
  (define (withdraw amount)
    (if (>= balance amount)
        (begin (set! balance (- balance amount))
               balance)
        "Insufficient funds"))
  (define (deposit amount)
    (set! balance (+ balance amount))
    balance)
  (define (dispatch pass m)
    (if (eq? pass password)
        (cond ((eq? m 'withdraw) withdraw)
              ((eq? m 'deposit) deposit)
              (else (error "Unknown request -- MAKE-ACCOUNT"
                           m)))
        (display "Incorrect password "))
    (lambda (x) #f)) ;line fixes error issue with proc calls
  dispatch)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Problem 4: Exercise 3.4
(define (new-make-account balance password)
  (define (withdraw amount)
    (if (>= balance amount)
        (begin (set! balance (- balance amount))
               balance)
        "Insufficient funds"))
  (define (deposit amount)
    (set! balance (+ balance amount))
    balance)
  (let ((bps-count 0))
  (define (dispatch pass m)
    (if (eq? pass password)
        (begin ;found a way to make multiple calls within each case of 
               ;the if statement
          (set! bps-count 0)
          (cond ((eq? m 'withdraw) withdraw)
                ((eq? m 'deposit) deposit)
                (else (error "Unknown request -- MAKE-ACCOUNT"
                           m))))
        (begin
          (set! bps-count (+ bps-count 1))
          (when (> bps-count 7)
            (display "!!!CALLING THE COPS!!! \n"))
          (display "Incorrect password ")
          (lambda (x) #f))))
    dispatch))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Problem 5
(define (FtoC f-temp)
  (* (/ 5.0 9.0) (- f-temp 32.0)))

(define (convert-temps stream)
  (stream-map FtoC stream))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Problem 6  
(define (filter-s stream)
  (cons-stream
   (stream-car stream)
   (filter-s (stream-filter
              (lambda (x)
                (or (divisible? x 2)
                    (divisible? x 3)
                    (divisible? x 5)))
              (stream-cdr stream)))))

(define s-235 (filter-s (integers-starting-from 2)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Problem 7
(define my-ints (cons-stream 1 (stream-map add1 my-ints)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Problem 8: Exercise 3.51 
(define (show x)
  (display-line x)
  x)

(define x (stream-map show (stream-enumerate-interval 0 10)))

;Would look like this:
;> (stream-ref x 5)
;
;1
;2
;3
;4
;5
;> (stream-ref x 7)
;
;6
;7
;>
;Second call to stream-ref only prints 2 numbers due the first call
;to stream-ref

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Problem 9: Exercise 3.52
(define sum 0)
(define (sum-accum x)
  (set! sum (+ x sum))
  sum)
;sum is 0
(define seq (stream-map sum-accum (stream-enumerate-interval 1 20)))
;sum is 1
(define y (stream-filter even? seq))
;sum is 6
(define z (stream-filter (lambda (x) (= (remainder x 5) 0))
                         seq))
;sum is 10
;> (stream-ref y 7)
;136
;sum is 136

;> (display-stream z)

;10
;15
;45
;55
;105
;120
;190
;210'done
;sum is 210

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Problem 10: Exercise 3.53
;By the defintion s is a stream begining with1 with the next element being 
;the promise to compute the sum of s and s. So when we call (stream-cdr s)
;we get back 2 or the sum of s and itself. Asking for the thrid element 
;would yeild 4 or ((1 + 1) + (1 + 1)), a sum of sums, and so on.

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Problem 11: Exercise 3.54
;general stream-map for multiple stream arguments
;used in mul-stream
(define (gen-stream-map proc . argstreams)
  (if (stream-null? (car argstreams))
      the-empty-stream
      (cons-stream
       (apply proc (map stream-car argstreams))
       (apply gen-stream-map
              (cons proc (map stream-cdr argstreams))))))

(define (mul-streams s1 s2) 
  (gen-stream-map * s1 s2))

(define factorials (cons-stream 1 (mul-streams 
                                   factorials
                                   (integers-starting-from 2))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Problem 12: Exercise 3.57
;With memo-ization n-1 addtions would be preformed through computing the
;nth fib number because each force call on the stream returned by 
;add-streams recomputes the fibs stream only once. Without it will grow 
;exponentialy.