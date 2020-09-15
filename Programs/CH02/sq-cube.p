#plot of the square and cube of integers
set grid
set time
set xlabel "value of n"
set ylabel "value of n^2 and n^3"
set title "Plot of datasheet of square and cube numbers"
#set xrange [-1:12]
#set yrange [-10:1100]
plot "sq-cube.txt" u 1:2 w lp lc rgb "green" pt 4, "sq-cube.txt" u 1:3 w lp lc rgb "red" dt "-" pt 6

pause -1 "Hit Enter key to continue"
