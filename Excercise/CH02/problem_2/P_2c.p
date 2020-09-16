# this script will multiplot
# this script is require to have datasheet P_2b.txt in same directory
set multiplot layout 2,2 title "Lissajous figure for case: 2c" font ",14"
set tmargin 2
set grid
set time

set title "n=2 A=1 delta=pi/4"
plot "P_2c.txt" u 1:2 w l lc rgb "red" title ""

set title "n=2 A=1 delta=pi/2"
plot "P_2c.txt" u 1:3 w l lc rgb "orange" title ""

set title "n=2 A=1 delta=pi"
plot "P_2c.txt" u 1:4 w l lc rgb "blue" title ""

set title "n=2 A=1 delta = pi/4, pi/2, pi"
plot "P_2c.txt" u 1:2 w l lc rgb "red" title "", "P_2c.txt" u 1:3 w l lc rgb "orange" title "","P_2c.txt" u 1:4 w l lc rgb "blue" title ""

unset multiplot

pause -1 "Hit Enter key to continue"
