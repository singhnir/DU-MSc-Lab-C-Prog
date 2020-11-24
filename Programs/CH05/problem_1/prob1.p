# keep 'exact.txt', 'euler.txt' and 'rk4.txt' in same directory.
set grid
set time
set xlabel "value of t" font ",14"
set ylabel "function x(t)" font ",14"
set title "Exact, Euler and RK4 Solutions" font ",14"
#plot "exact.txt" w lp t "exact","euler.txt" w lp t "euler","rk4.txt" w lp t "rk4"
plot "exact.txt" w lp t "exact","rk4.txt" w lp t "rk4"

pause -1 "Hit Enter key to continue"