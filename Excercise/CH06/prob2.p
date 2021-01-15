# keep 'prob2.txt' in same directory.
set grid
set time
set xlabel "A: 0<A<pi" font ",14"
set ylabel "time periods and error" font ",14"
set title "Plot of time periods of a pendulum" font ",14"
plot "prob2.txt"  w lp t "intgrated",'' u 1:3 w lp t "approximated", '' u 1:4 w lp t "% Error"

pause -1 "Hit Enter key to continue"