# this script is require to have datasheet periodic.txt in same directory
set grid
set time
# Draw a horizontal centreline.
set xzeroaxis
set yrange [-2:2]
set title "Periodic Square Wave" font ",14"

plot "periodic.txt" u 1:2 w l lw 2 lc rgb "red" title "Square Wave"

pause -1 "Hit Enter key to continue"
