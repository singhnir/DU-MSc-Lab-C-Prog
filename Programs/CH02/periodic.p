# this script is require to have datasheet periodic.txt in same directory
set grid
set time
set yrange [-2:2]
set title "Periodic Step Function" font ",14"

plot "ex.txt" u 1:2 w l lw 2 lc rgb "red" title "Step Function"

pause -1 "Hit Enter key to continue"
