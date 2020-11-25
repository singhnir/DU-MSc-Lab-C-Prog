# keep 'prob5-alpha100.txt' in the same directory.
set grid
set time
set xlabel "value of t" font ",14"
set ylabel "x(t),y(t),z(t)" font ",14"
#set title "Lorenz equations:fixed point solution(alpha=5)" font ",14"
#set title "Lorenz equations:chaotic motion(alpha=50)" font ",14"
set title "Lorenz equations:periodic motion(alpha=100)" font ",14"

plot "prob5-alpha100.txt" u 1:2 w l lw 1.5 t "x(t)","prob5-alpha100.txt" u 1:3 w l lw 1.5 t "y(t)","prob5-alpha100.txt" u 1:4 w l lw 1.5 t "z(t)"

pause -1 "Hit Enter key to continue"