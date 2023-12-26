#plot of function given in example 1.4
f(x)=x*x*x+sin(x)+log(x)
set grid
set time
set xlabel "value of x"
set ylabel "value of function"
set title "Plot of function given in example 1.4"
set xrange [-1:12]
set yrange [-100:1500]
plot f(x)

pause -1 "Hit Enter key to continue"
