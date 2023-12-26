#GM Counting Statics for preset time 20 seconds
set grid
set time
set xrange [0:21]
set xlabel "X" font ",14"
set ylabel "Probability Curves" font ",14"
set title "GM Counting Statistics: Experimental, Poisson, Gaussian" font ",14"
plot "gmcounter.txt" u 1:3:4 w yerrorbars lc rgb "black" dt 3 t "exp prob points", "gmcounter.txt" u 1:2 smooth csplines lc rgb "black" dt 2 t "poisson prob curve", "gmcounter.txt" u 1:5 smooth csplines lc rgb "black" dt 3 t "gaussian prob curve"

pause -1 "Hit Enter key to continue"
