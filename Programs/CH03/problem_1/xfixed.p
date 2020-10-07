# this script is require to have datasheet xfixed.txt in same directory
set grid
set time
set yrange [0:160]
set xlabel "value of n" font ",14"
set ylabel "exponential function" font ",14"
set title "for fixed x=5" font ",14"

plot "xfixed.txt" u 1:2 w lp lc rgb "red" t "exp"

pause -1 "Hit Enter key to continue"