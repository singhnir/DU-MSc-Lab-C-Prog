#plot the graphic of sin(x)
set grid
set time
set xlabel "value of x"
set ylabel "value of function sin(x)"
set title "Plot of sin(x)"
set xrange [-12:12]
set yrange [-1.5:1.5]
plot sin(x)

pause -1 "Hit Enter key to continue"
