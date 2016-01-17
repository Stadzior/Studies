from pyx import *
c = canvas.canvas()
circle = path.circle(0, 0, 2)
line = path.line(-1.5, 2, -1.5, -2)
c.stroke(circle, [style.linewidth.Thick])
c.stroke(line, [style.linewidth.Thin])
isects_circle, isects_line = circle.intersect(line)
for isect in isects_circle:
    isectx, isecty = circle.at(isect)
    c.stroke(path.line(0, 0, isectx, isecty))
triangle = path.path(path.moveto(0, 0),
              path.lineto(isectx, -isecty),
              path.lineto(isectx, isecty),
              path.closepath())            
c.fill(triangle, [color.rgb(0.5,0.5,0.5)])
c.writePDFfile("rysunek.pdf")

