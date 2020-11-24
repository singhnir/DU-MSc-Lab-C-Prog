# keep 'prob6.txt' in the same directory.
set grid
set time
set ylabel "value of x" font ",14"
set xlabel "value of alpha" font ",14"
set title "Bifurcation Diagram for the Logistic Map" font ",14"
plot "prob6.txt" t ""

pause -1 "Hit Enter key to continue"