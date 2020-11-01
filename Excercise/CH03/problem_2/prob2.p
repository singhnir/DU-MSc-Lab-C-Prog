# this script is require to have datasheet prob2.txt in same directory
set grid
set time
set xzeroaxis
set xlabel "value of x in radian" font ",14"
set ylabel "cosine series" font ",14"
set title "for 0<=x<=pi" font ",14"

plot "prob2.txt" u 1:2 w lp lc rgb "red" t "cosine"

pause -1 "Hit Enter key to continue"
