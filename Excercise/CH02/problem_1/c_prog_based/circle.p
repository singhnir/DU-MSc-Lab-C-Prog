# plotting a circle of radius 3 centered at (5,5).
# this script is require to have datasheet circle.txt in same directory

set grid
set time
set title "A circle of radius 3, centered at (5,5)" font ",14"
set size square
set xrange [0:9]
set yrange [0:9]
plot "circle.txt" u 1:2 w l title "Circle" lc rgb "red"

pause -1 "Hit Enter key to continue"