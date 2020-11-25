# keep 'prob4.txt' in the same directory.
set grid
set time
set xzeroaxis
set xlabel "majoraxis" font ",14"
set ylabel "minoraxis" font ",14"
set title "Kepler's orbit (omega=1,e=0.8,a=2)" font ",14"
plot "prob4.txt" t ""

pause -1 "Hit Enter key to continue"