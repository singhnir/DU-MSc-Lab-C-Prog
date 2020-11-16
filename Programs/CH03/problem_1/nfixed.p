# this script is require to have datasheet nfixed.txt in same directory
set grid
set time
set xlabel "value of x" font ",14"
set ylabel "exponential function" font ",14"
set title "for fixed n=20" font ",14"

plot "nfixed.txt" u 1:2 w lp lc rgb "red" t "exp"

pause -1 "Hit Enter key to continue"