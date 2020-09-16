# this script will multiplot
# this script is require to have datasheet P_2b.txt in same directory
set multiplot layout 2,2 title "Lissajous figure for case: 2b" font ",14"
set tmargin 2
set grid
set time

set title "delta=pi/4 n=2 A=0.5"
plot "P_2b.txt" u 1:2 w l lc rgb "red" title ""

set title "delta=pi/4 n=2 A=1"
plot "P_2b.txt" u 1:3 w l lc rgb "orange" title ""

set title "delta=pi/4 n=2 A=2"
plot "P_2b.txt" u 1:4 w l lc rgb "blue" title ""

set title "delta=pi/4 n=2 A=0.5,1,2"
plot "P_2b.txt" u 1:2 w l lc rgb "red" title "","P_2b.txt" u 1:3 w l lc rgb "orange" title "","P_2b.txt" u 1:4 w l lc rgb "blue" title ""

unset multiplot

pause -1 "Hit Enter key to continue"
