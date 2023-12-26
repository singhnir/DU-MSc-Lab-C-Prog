set term postscript   
set output  "ex2.eps"
plot "ex2.txt" using 1:2 with lines title  "simpsons", \
 "ex2.txt" using 1:3 with lines title  "approximation", \
 "ex2.txt" using 1:4 with lines title  "error"
