set term png   
set output  "ex2.png"
plot "ex2.txt" using 1:2 with lines title  "simpsons", \
 "ex2.txt" using 1:3 with lines title  "approximation", \
 "ex2.txt" using 1:4 with lines title  "error"
