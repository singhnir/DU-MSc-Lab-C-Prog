# this script is require to have datasheet prob6.txt in same directory
set grid
set time
set xlabel "value of z" font ",14"
set ylabel "function f(z)" font ",14"
set title "for -10<=z<=0" font ",14"

plot "prob6.txt" u 1:2 w lp lc rgb "red" t "C=0.35503"

pause -1 "Hit Enter key to continue"