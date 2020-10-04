# this script is require to have datasheet prob4.txt in same directory
set grid
set time
set xlabel "value of z" font ",14"
set ylabel "function F(z)" font ",14"
set title "crazy function" font ",14"

plot "prob4.txt" u 1:2 smooth csplines lc rgb "red" t "function"

pause -1 "Hit Enter key to continue"