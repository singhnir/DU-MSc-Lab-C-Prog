# this script will multiplot
# this script is require to have datasheet P_2a.txt in same directory
set multiplot layout 2,2 title "Lissajous figure for case: 2a" font ",14"
set tmargin 2
set grid
set time

set title "delta=pi/4 A=1 n=2"
plot "P_2a.txt" u 1:2 w l lc rgb "red" title ""

set title "delta=pi/4 A=1 n=2.5"
plot "P_2a.txt" u 1:3 w l lc rgb "orange" title ""

set title "delta=pi/4 A=1 n=3"
plot "P_2a.txt" u 1:4 w l lc rgb "blue" title ""

set title "delta=pi/4 A=1 n=2,2.5,3"
plot "P_2a.txt" u 1:2 w l lc rgb "red" title "","P_2a.txt" u 1:3 w l lc rgb "orange" title "","P_2a.txt" u 1:4 w l lc rgb "blue" title ""

unset multiplot

pause -1 "Hit Enter key to continue"
