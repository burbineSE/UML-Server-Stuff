#lang racket/gui

(require sgl/gl)

(define (resize w h)
  ;sets the view port of the program
  ;http://msdn.microsoft.com/en-us/library/windows/desktop/dd374202(v=vs.85).aspx
  (glViewport 0 0 w h))

(define (draw-gl)
  ;clears color buffers
  (glClearColor 0.0 0.0 0.0 0.0)
  (glClear GL_COLOR_BUFFER_BIT)
  
  ;sets type of shading. either GL_FLAT or GL_SMOOTH
  (glShadeModel GL_SMOOTH)
  
  ;specifies which matrix is the current matrix
  ;GL_PROJECTION applies subsequent matric ops to the projection matrix stack
  (glMatrixMode GL_PROJECTION)
  ;replaces the current matrix with the identity matrix 
  (glLoadIdentity)
  ;multiplies the current matrix by an orthographic marix
  ;params are as follows: left, right, bottom, top, zNear and zFar
  (glOrtho -1.0 1.0 -1.0 1.0 -1.0 1.0)
  ;swaps current matrix to model view
  (glMatrixMode GL_MODELVIEW)
  (glLoadIdentity)
  
  ;glBegin and glEnd delimit the vertices of a primitive or 
  ;group of like primitives, in this case we treat the triplet of
  (glBegin GL_TRIANGLES)
  ;sets triangle's color (red)
  (glColor3f 1 0 0)
  ;each of the following specifies a vertex with (x, y, z) corrdinates
  (glVertex3d -0.75 -0.5 0.0)
  (glVertex3d  0.75 0.5 0.0)
  (glVertex3d -0.75 0.5 0.0)
  (glEnd)
  
  (glBegin GL_TRIANGLES)
  (glColor3f 0 0 1)
  (glVertex3d -0.75 -0.5 0.0)
  (glVertex3d 0.75 0.5 0.0)
  (glVertex3d 0.75 -0.5 0.0)
  (glEnd))

;the remainder are window bulding function for the triangle to be drawn in
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

(define window (new frame% (label "Racket OpenGL Rectangle") (min-width 300) (min-height 300)))
(define gl (new test-canvas% (parent window)))

(send window show #t)
    
    
  
  