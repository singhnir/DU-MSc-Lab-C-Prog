# this script is require to have datasheet l3m0.txt in same directory
set grid
set time
set title "Orbital Wave Function for l=3 m=0" font ",14"
plot "l3m0.txt" u 1:2 w l lc rgb "red" title ""

pause -1 "Hit Enter key to continue"
