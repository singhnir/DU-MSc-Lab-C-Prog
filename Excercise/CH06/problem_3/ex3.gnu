set terminal postscript
set output "e0.eps"
plot "ex3.txt" using 1:2 with lines title "trapezoidal", "ex3.txt" using 1:3 with lines title "simpson", "ex3.txt" using 1:4 with lines title "gauss quadrature" 
