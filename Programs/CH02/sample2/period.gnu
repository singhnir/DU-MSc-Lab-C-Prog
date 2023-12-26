set terminal png
set output "period1.png"
set xrange [0:8]
set yrange [0:2]
plot "period.txt" index 0 using 1:2 with lines title "triangle", "period.txt" index 1 using 1:2 with points title "half circle"

