# this script is require to have datasheet prob1.txt in same directory
set grid
set time
set xlabel "value of x" font ",14"
set ylabel "function series on logarithmic scale" font ",14"
set title "for n=20 and 0<=x<=2" font ",14"

plot "prob1.txt" u 1:3 w lp t "series"

pause -1 "Hit Enter key to continue"