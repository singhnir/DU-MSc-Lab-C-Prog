#plotting a circle of radius 3 centered at (5,5).
# plotting using the parametric equation
# x=h+r*cos(t) ; y=k+r*cos(t) ; (h,k) is centre and r is radii
set grid
set time
set title "A circle of 3 centered at (5,5)" font ",14"
set parametric
set size square
set xrange [0:9]
set yrange [0:9]
plot [0:2*pi] 5+3*sin(t),5+3*cos(t) title "Circle" lc rgb "red"

pause -1 "Hit Enter key to continue"
