# keep 'exact.txt' and 'rk4.txt' in same directory.
set grid
set time
set xzeroaxis
set xlabel "value of t" font ",14"
set ylabel "function y(t)" font ",14"
set title "Motion via Spring (A=m=k=1)" font ",14"
plot "exact.txt" w lp t "exact","rk4.txt" w lp t "rk4"

pause -1 "Hit Enter key to continue"