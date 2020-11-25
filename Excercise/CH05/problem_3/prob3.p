# keep 'prob3.txt' in the same directory.
set grid
set time
set xlabel "prey population x(t)" font ",14"
set ylabel "predator population y(t)" font ",14"
set title "Phase Space for Prey-Predator System" font ",14"
plot "prob3.txt" u 1:2 t ""

pause -1 "Hit Enter key to continue"