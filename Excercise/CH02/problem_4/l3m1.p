# this script is require to have datasheet l3m1.txt in same directory
set grid
set time
set title "Orbital Wave Function for l=3 m=±1" font ",14"
plot "l3m1.txt" u 1:2 w l lc rgb "red" title ""

pause -1 "Hit Enter key to continue"
