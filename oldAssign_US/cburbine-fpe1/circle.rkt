#lang racket/gui

(require 
  sgl/gl)

(define (resize w h)
  (glViewport 0 0 w h))

(define ballRadius 0.5)
(define ballX 0.0)
(define ballY 0.0)
(define xSpeed 0.02)
(define ySpeed 0.007)
(define refreshMills 30)
(define angle 0.0)

(define (circle-loop numSegments i)
  (if ( >= i numSegments)
      (glVertex2f (* (cos angle) ballRadius) (* (sin angle) ballRadius))
      ;0
      (else-call numSegments i)))

(define (else-call numSegments i)
  (set! angle (/ (* i 2 pi) numSegments))
  (glVertex2f (* (cos angle) ballRadius) (* (sin angle) ballRadius))
  (circle-loop numSegments (+ i 1)))

(define (draw-gl)
  (glClearColor 0.0 0.0 0.0 0.0)
  (glClear GL_COLOR_BUFFER_BIT)
  
  (glShadeModel GL_SMOOTH)
  
  (glMatrixMode GL_PROJECTION)
  (glLoadIdentity)
  (glOrtho -1.0 1.0 -1.0 1.0 -1.0 1.0)
  (glMatrixMode GL_MODELVIEW)
  (glLoadIdentity)
  
  (glBegin GL_TRIANGLE_FAN)
  (glColor3f 0 1 0)
  (glVertex2f 0.0 0.0)
  (circle-loop 1000 0)
  (glEnd))



(define test-canvas%
  (class* canvas% ()
    (inherit with-gl-context swap-gl-buffers)
    
    (define/override (on-paint)
      (with-gl-context
      (lambda ()
        (draw-gl)
        (swap-gl-buffers))))
  
  (define/override (on-size width height)
    (with-gl-context
     (lambda ()
       (resize width height))))
  
  (super-instantiate () (style '(gl)))))

(define window (new frame% (label "Racket OpenGL my-test2") (min-width 300) (min-height 300)))
(define gl (new test-canvas% (parent window)))

(send window show #t)
