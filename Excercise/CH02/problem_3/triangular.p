# this script is require to have datasheet triangular.txt in same directory
set grid
set time
set title "Periodic Function: Triangular Wave" font ",14"

plot "triangular.txt" u 1:2 w l lw 2 lc rgb "red" title "Triangular Wave"

pause -1 "Hit Enter key to continue"
