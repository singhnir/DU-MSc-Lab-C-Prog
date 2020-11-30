# keep 'prob3b.txt' in the same directory.
set grid
set time
set xzeroaxis
set yzeroaxis
set xlabel "value of x" font ",14"
set ylabel "value of y" font ",14"
set title "finding the roots" font ",14"
plot "prob3b.txt" u 1:2 t ""

pause -1 "Hit Enter key to continue"