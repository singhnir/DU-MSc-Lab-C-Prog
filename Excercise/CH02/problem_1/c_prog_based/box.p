#plotting a box with vertices at (1,1);(5,1);(5,5) and (1,5).
#make sure "box.txt" file is in same directory.
set grid
set time
set size square
set title "Box with vertices at (1,1) (5,1) (5,5) and (1,5)" font ",14"
set xrange [0:6]
set yrange [0:6]
plot "box.txt" lc rgb "red" title "Rectangular Box"

pause -1 "Hit Enter key to continue"
