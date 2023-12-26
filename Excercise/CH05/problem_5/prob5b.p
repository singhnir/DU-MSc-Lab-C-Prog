# multiplot  all in one screen

set grid 
set size 1,1

set xrange [*:*]
set yrange [*:*]

set multiplot layout 3,3 columnsfirst title "Evolution of Coordinates" spacing 5 
set lmargin 5

set xlabel "x"
set ylabel "y"
plot "ex5.txt" using 2:3 with lines  title "x vs y"

set xlabel "x"
set ylabel "z"
plot "ex5.txt" using 2:4 with lines  title "x vs z" 

set xlabel "y"
set ylabel "z"
plot "ex5.txt" using 3:4 with lines  title "y vs z" 

set ylabel "x"
set xlabel "t"
plot "ex5.txt" using 1:2 with lines title "x(t)" 

set ylabel "y"
plot "ex5.txt" using 1:3 with lines title "y(t)" 

set ylabel "z"
plot "ex5.txt" using 1:4 with lines title "z(t)" 
unset multiplot
