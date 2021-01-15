# keep 'prob3.txt' in same directory.
set grid
set time
set xlabel "R varying from r0=0.6 to rm=3.4" font ",14"
#set xlabel "R varying from r0=0.5 to rm=5" font ",14"
set ylabel "theta(R)" font ",14"
set title "particle moving under a central force E=-0.25" font ",14"
plot "prob3.txt" t ""
pause -1 "Hit Enter key to continue"