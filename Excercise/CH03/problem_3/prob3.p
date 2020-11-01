# this script is require to have datasheet jx0.txt in same directory
set grid
set time
set xzeroaxis
set xlabel "value of x" font ",14"
set ylabel "Bessel Function" font ",14"
set title "Bessel Function J(x)" font ",14"

# change filename for other plots
plot "jx0.txt" u 1:2 w lp lc rgb "red" t "J0 (n=0)"

pause -1 "Hit Enter key to continue"
