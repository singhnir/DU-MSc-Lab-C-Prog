# this script is require to have datasheet bessel.txt in same directory
set grid
set time
set xlabel "Z" font ",14"
set ylabel "Different Bessel Functions" font ",14"
set title "Bessel Functions Jo, J1, J2, J3, J4, J5" font ",14"

plot "bessel.txt" u 1:2 w l lw 2 t "Jo(z)", "bessel.txt" u 1:3 w l lw 2 t "J1(z)", "bessel.txt" u 1:4 w l lw 2 t "J2(z)", "bessel.txt" u 1:5 w l lw 2 t "J3(z)", "bessel.txt" u 1:6 w l lw 2 t "J4(z)", "bessel.txt" u 1:7 w l lw 2 t "J5(z)"

pause -1 "Hit Enter key to continue"