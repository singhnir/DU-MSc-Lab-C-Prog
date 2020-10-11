#plotting a right angled triangle with vertices at (0,0);(4,0) and (4,3).
#make sure "triangle.txt" file is in same directory.
set grid
set time
set title "Triangle with vertices at (0,0) (4,0) and (4,3)" font ",14"
set xrange [0:5]
set yrange [0:4]
plot "triangle.txt" w lp lc rgb "red" title "Right Angle Triangle"

pause -1 "Hit Enter key to continue"
