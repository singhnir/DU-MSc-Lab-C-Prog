# Intention of This fork

My goal is to write  Readable, self contained solutions that let's one to learn the logic, not taylor piece of jumbling codes for getting output - that's what
I felt when I looked into manual linked and I tried too hard to learn from it with vain. 

I suggest the starting points as the directory Programs, Each chapter (atleast the One I have modified) have notes + templates that's used for solving excersise
as of now,

<ul>
<li><a href="Programs/CH02/README.md"> Receipe for periodic plots using in-built functions</a></li>
<li><a href="Excercise/CH04/problem_1/prob1.c"> A general template for Root finding of function without bracketing roots</a></li>
<li><a href="Programs/CH05/problem_1/prob1.c"> Explains solving ode with numerical techniques Euler, RK2 and RK4 methods</a></li>
<li><a href="Programs/CH05/problem_2/prob2.c"> Extending previous for higher dimensionality </a></li>
<li><a href="Programs/CH06/notes.txt"> Receipe for solving Integration and root finding problems </a></li>

</ul>




For curiosity - I'm following [Kernal source file style](https://man.openbsd.org/style.9)

I'm satisfied with how these templates, piece of codes turned out and I was able to explain to myself+my friends, 
but I would be very happy if someone can dumb it down even further keeping the same essence of learning. Cheers!

finally thanks to [musubiie](https://github.com/musubiiie) for chapter 2 periodic question and motivation to
make templates ;)


# Computational Physics (Lab) - M.Sc. Physics University of Delhi

## Semester: III Course Code: PH-CL502

### Manual by : Professor Shobhit Mahajan [>Profile<](http://people.du.ac.in/~sm/)
### Course Instructor : Professor Jyoti Rajput [>Profile<](http://du.ac.in/du/uploads/Faculty%20Profiles/Physics/Physics_Jyoti_Rajput.pdf)
As per our university syllabus, "This course is intended to be an Introduction to a **Programming Language C** as well as application for Numerical Analysis. The course would impart training in the structure of the programming language as well as train the students in using programs to numerically solve problems in various areas. In addition, it will also familiarize the students to the Unix environment."

We have been given a **[MANUAL](https://drive.google.com/file/d/10ZzmHsvMVDVspZUY6VBRm5HezVoqkNAQ/view?usp=sharing)** to practice the problems and here I'll commit the programs as I successfully compile and get the desired output.<br>
***This repository is under progress.***
## Table of Contents
### Programs

<details>
<summary>Chapter 01 Practice Problems.</summary>
<ul>
<li><a href="Programs/CH01/First.c">1. My First C Programme.</a></li>
<li><a href="Programs/CH01/sinx.c">2. Evaluating trigonometric function sin(x).</a></li>
<li><a href="Programs/CH01/sinxtab.c">3.1. Tabulates values of sin(x) using for loop.</a></li>
<li><a href="Programs/CH01/sinxtab-loops.c">3.2. Tabulates values of sin(x) using all the three loops.</a></li>
<li><a href="Programs/CH01/functionx.c">4.1 Evaluating a function having one variable.</a></li>
<li><a href="Programs/CH01/functionxn.c">4.2 Evaluating a function having two variable.</a></li>
<li><a href="Programs/CH01/storetxt.c">5. Evaluating a function and storing the results.</a></li>
<li><a href="Programs/CH01/palindrome.c">6. To cheack whether a given number is a Palindrome number.</a></li>
<li><a href="Programs/CH01/leapyear.c">7. To cheack whether a given year is a leap year.</a></li>
<li><a href="Programs/CH01/hcf.c">8.1. To find the HCF or GCD of two numbers using the defination.</a></li>
<li><a href="Programs/CH01/hcfrecur.c">8.2. To find the HCF or GCD of two numbers using the recursion.</a></li>
<li><a href="Programs/CH01/prime.c">9.1. Program to generate prime numbers upto n.</a></li>
<li><a href="Programs/CH01/primerange.c">9.2. Program to generate prime numbers in given range.</a></li>
</ul>
</details>

<details>
<summary>Chapter 02 Practice Problems.</summary>
<ul>
<li><a href="Programs/CH02/sinx.p">1.1. Plot of trigonometric function sin(x).</a></li>
<li><a href="Programs/CH02/function.p">1.2. Plot of Example 1.4 function</a></li>
<li><a href="Programs/CH02/sq-cube.p">2.1. Plot from datasheet "sq-cube.txt".</a></li>
<li><a href="Programs/CH02/gmcounter.p">2.2. Plot of GM counter counting Statics "gmcounter.txt".</a></li>
<li><a href="Programs/CH02/epsfile.p">3.1. Saving the plot in eps filetype.</a></li>
<li><a href="Programs/CH02/pngfile.p">3.4. Saving the plot in png filetype.</a></li>
<li><a href="Programs/CH02/periodic.c">4.1. Generating the datasheet for given step function.</a></li>
<li><a href="Programs/CH02/periodic.p">4.2. Plotting the datasheet "periodic.txt" of square wave.</a></li>
</ul>
</details>

<details>
<summary>Chapter 03 Practice Problems.</summary>
<ul>
<li><a href="Programs/CH03/problem_1/">Example 01 : Exponential series</a></li>
<li><a href="Programs/CH03/problem_2/">Example 02 : Sine series</a></li>
<li><a href="Programs/CH03/problem_3/">Example 03 : Cosine series</a></li>
</ul>
</details>

<details>
<summary>Chapter 04 Practice Problems.</summary>
<ul>
<li><a href="Programs/CH04/problem_1/">Example 01 : Bisection Method</a></li>
<li><a href="Programs/CH04/problem_2/">Example 02 : Secant Method</a></li>
<li><a href="Programs/CH04/problem_3/">Example 03 : Newton-Raphson Method</a></li>
</ul>
</details>

<details>
<summary>Chapter 05 Practice Problems.</summary>
<ul>
<li><a href="Programs/CH05/problem_1/">Example 01 : Euler, RK2 and RK4 methods</a></li>
<li><a href="Programs/CH05/problem_2/">Example 02 : 2nd order differential system</a></li>
</ul>
</details>

<details>
<summary>Chapter 06 Practice Problems.</summary>
<ul>

</ul>
</details>

<details>
<summary>Chapter 07 Practice Problems.</summary>
<ul>
<li><a href="Programs/CH07/fibonacci.c">Example 01 : Generating the first 10 Fibonacci numbers</a></li>
<li><a href="Programs/CH07/matrix.c">Example 02 : To print and add 2x3 matrices</a></li>
<li><a href="Programs/CH07/matalloc.c">Example 03 : Using matalloc function</a></li>
</ul>
</details>

### Excercise
<details>
<summary>Chapter 01 Excercise Problems.</summary>
<ul>
<li><a href="Excercise/CH01/trigtable.c">1. Table of the trigonometric functions sin(x), cos(x) and tan(x).</a></li>
<li><a href="Excercise/CH01/absfun.c">2. Make a table of the function f(x,y).</a></li>
<li><a href="Excercise/CH01/pythagorean.c">3. Program to find Pythagorean numbers less than 100.</a></li>
<li><a href="Excercise/CH01/harshad.c">4. Program to find Harshad numbers between 50 and 70 both inclusive.</a></li>
<li><a href="Excercise/CH01/fibonacci1.c">5.1. Program to generate Fibonacci numbers till 200.</a></li>
<li><a href="Excercise/CH01/fibonacci2.c">5.2. Program to generate Fibonacci numbers till any integer.</a></li>
<li><a href="Excercise/CH01/factorial.c">6. Program to calculate the factorial of a given integer.</a></li>
<li><a href="Excercise/CH01/PermuCombi.c">7. Program which calculates <sup>n</sup>C<sub>r</sub> and <sup>n</sup>P<sub>r</sub> for given values of n and r.</a></li>
<li><a href="Excercise/CH01/determinant.c">8. Program to determine the roots of a quadratic equation.</a></li>
</ul>
</details>

<details>
<summary>Chapter 02 Excercise Problems.</summary>
<ul>
<li><a href="Excercise/CH02/problem_1/c_prog_based/">Problem 01 : C program based</a></li>
<li><a href="Excercise/CH02/problem_1/">Problem 01 : Gnuplot script based</a></li>
<li><a href="Excercise/CH02/problem_2/">Problem 02 : Lissajous Figures</a></li>
<li><a href="Excercise/CH02/problem_3/">Problem 03 : Triangular wave function</a></li>
<li><a href="Excercise/CH02/problem_4/">Problem 04 : Orbital wave functions</a></li>
<li><a href="Excercise/CH02/problem_5/">Problem 05 : Bessel functions</a></li>
</ul>
</details>

<details>
<summary>Chapter 03 Excercise Problems.</summary>
<ul>
<li><a href="Excercise/CH03/problem_1/">Problem 01 : Simple series</a></li>
<li><a href="Excercise/CH03/problem_2/">Problem 02 : Cosine series</a></li>
<li><a href="Excercise/CH03/problem_3/">Problem 03 : Bessel series</a></li>
<li><a href="Excercise/CH03/problem_4/">Problem 04 : Series F(z)</a></li>
<li><a href="Excercise/CH03/problem_5/">Problem 05 : Series f(z,n)</a></li>
<li><a href="Excercise/CH03/problem_6/">Problem 06 : Series f(z)</a></li>
</ul>
</details>

<details>
<summary>Chapter 04 Excercise Problems.</summary>
<ul>
<li><a href="Excercise/CH04/problem_1/">Problem 01 : Simple polynomial</a></li>
<li><a href="Excercise/CH04/problem_2/">Problem 02 : Bessel function J0(x)</a></li>
<li><a href="Excercise/CH04/problem_3/">Problem 03 : Tricky function f(x,y)</a></li>
<li><a href="Excercise/CH04/problem_4/">Problem 04 : Kepler's orbit</a></li>
<li><a href="Excercise/CH04/problem_5/">Problem 05 : Chebyshev polynomial U4(x)</a></li>
</ul>
</details>

<details>
<summary>Chapter 05 Excercise Problems.</summary>
<ul>
<li><a href="Excercise/CH05/problem_1/">Problem 01 : Simple ODE</a></li>
<li><a href="Excercise/CH05/problem_2/">Problem 02 : Motion of simple pendulam</a></li>
<li><a href="Excercise/CH05/problem_3/">Problem 03 : Prey-Predator system</a></li>
<li><a href="Excercise/CH05/problem_4/">Problem 04 : Tricky differential equation</a></li>
<li><a href="Excercise/CH05/problem_5/">Problem 05 : Lorenz equations</a></li>
<li><a href="Excercise/CH05/problem_6/">Problem 06 : Bifurcation diagram</a></li>
</ul>
</details>

<details>
<summary>Chapter 06 Excercise Problems.</summary>
<ul>
<li><a href="Excercise/CH06/chapter-6-excercise-sol-all-in-one.pdf/">ALL IN ONE (PDF)</a></li>
<li><a href="Excercise/CH06/prob1.c">Problem 01 : Using trapezoidal and simpson</a></li>
<li><a href="Excercise/CH06/prob2.c/">Problem 02 : Time period of a pendulum</a></li>
<li><a href="Excercise/CH06/prob3.c/">Problem 03 : Particle moving under central force</a></li>
<li><a href="Excercise/CH06/prob4.c/">Problem 04 : Root of the function F(x)</a></li>
<li><a href="Excercise/CH06/prob5.c/">Problem 05 : Bessel function J0</a></li>
<li><a href="Excercise/CH06/prob6.c/">Problem 06 : Bessel function J2</a></li>
</ul>
</details>

<details>
<summary>Chapter 07 Excercise Problems.</summary>
<ul>
<li><a href="Excercise/CH07/prob1.c">Problem 01 : Creating functions for matrix operations</a></li>
<li><a href="Excercise/CH07/prob2.c">Problem 02 : Finding the commutator</a></li>
</ul>
</details>

### To Do List

|Chapters|Examples|Excercise|
|:-:|:-:|:-:|
|01|:heavy_check_mark:|:heavy_check_mark:|
|02|:heavy_check_mark:|:heavy_check_mark:|
|03|:heavy_check_mark:|:heavy_check_mark:|
|04|:heavy_check_mark:|:heavy_check_mark:|
|05|:heavy_check_mark:|:heavy_check_mark:|
|06|          |:heavy_check_mark:|
|07|:heavy_check_mark:|:heavy_check_mark:|

## How to use GNUPLOT scripts?
It's better to write a gnuplot script with extension `filename.p`, rather than writing the commands on gnuplot terminal. This way we can save our gnuplot codes for future needs.<br/>

If you've saved a gnuplot script named `lissajous.p` in the current working directory:<br/>
**For Linux user:** `gnuplot ./lissajous.p`<br/>
**For Windows user:** `load "lissajous.p"`<br/>

*Note: If we use `load "lissajous.p"` in **gnuplot terminal**, it will work both in linux and windows.*

## Do you want to download all the codes at once?
### For Linux user:
All the linux distributers have git installed in their system so they simply paste the following code to get a local copy in your system.<br/>
`git clone https://github.com/singhnir/DU-MSc-Lab-C-Prog.git`
### For Windows user:
Normally no windows has git preinstalled so previous command doesn't work on it but again you can download a zip copy of the codes clicking [**here**](https://github.com/singhnir/DU-MSc-Lab-C-Prog/archive/master.zip).

## Requirements
* Text Editor (Atom/Sublime/emacs...) - vim.tiny is aliased as vi in lab boxes
* GCC Compiler
* Gnuplot

## Contact
If you've any doubt or suggestions regarding the project, please feel free to reach out by filing an issue here on github or you can simply email me at [nirsingh124@gmail.com](mailto:nirsingh124@gmail.com). You can also drop a message to my [Telegram](https://t.me/singhnirmal) account.

## Acknowledgements

## Licence
[MIT License](https://github.com/singhnir/DU-MSc-Lab-C-Prog/blob/master/LICENSE)
