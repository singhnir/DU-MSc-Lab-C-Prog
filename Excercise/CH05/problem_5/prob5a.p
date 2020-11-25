# keep 'prob5-alpha100.txt' in the same directory.
set grid
set time
#set xlabel "value of x(t)" font ",14"
set xlabel "value of y(t)" font ",14"
#set ylabel "value of y(t)" font ",14"
set ylabel "value of z(t)" font ",14"
#set title "Lorenz equations:fixed point solution(alpha=5)" font ",14"
#set title "Lorenz equations:chaotic motion(alpha=50)" font ",14"
set title "Lorenz equations:periodic motion(alpha=100)" font ",14"

#plot "prob5-alpha100.txt" u 2:3 t "XY plane"
#plot "prob5-alpha100.txt" u 2:4 t "XZ plane"
plot "prob5-alpha100.txt" u 3:4 t "YZ plane"

pause -1 "Hit Enter key to continue"