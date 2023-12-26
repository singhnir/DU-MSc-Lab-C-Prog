set terminal png
set output "period.png"
plot "period.txt" index 0 using 1:2 with lines title "triangle", "period.txt" index 1 using 1:2 with points title "circle"
