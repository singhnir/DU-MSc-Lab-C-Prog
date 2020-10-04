# this script is require to have datasheet prob5.txt in same directory
set grid
set time
set xlabel "value of z" font ",14"
set ylabel "function f(z,n)" font ",14"
set title "another crazy function" font ",14"

plot "prob5.txt" u 1:2 w l lc rgb "red" t "n=2"

pause -1 "Hit Enter key to continue"