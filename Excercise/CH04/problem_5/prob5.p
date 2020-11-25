# keep 'prob5.txt' in the same directory.
set grid
set time
set xzeroaxis
set xlabel "value of x" font ",14"
set ylabel "function U4(x,4)" font ",14"
set title "Chebyshev polynomial U4(x,4)" font ",14"
plot "prob5-U4.txt" t ""

pause -1 "Hit Enter key to continue"