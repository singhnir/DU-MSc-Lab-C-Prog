# keep 'prob5.txt' in the same directory.
set grid
set time
set xzeroaxis
set yzeroaxis
set xlabel "value of x" font ",14"
set ylabel "function f(x,y)" font ",14"
set title "f(x,y): -1.5<x<1.5 and -2<y<2" font ",14"
plot "prob3a.txt" u 1:3 t ""

pause -1 "Hit Enter key to continue"