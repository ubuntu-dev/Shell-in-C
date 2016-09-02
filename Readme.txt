README
_______________________________________________________
_______________________________________________________

FEATURES SUPPORTED
-------------------------------------------------------
The shell supports cd,pwd,echo,exit and other built in commands.
Errors are handled properly using perror.
Echo command is not the same as in the bash shell.


HOW TO COMPILE
-------------------------------------------------------

to compile run the command:-   make

HOW TO RUN
-------------------------------------------------------
run the command:- ./main
FILES
-------------------------------------------------------
cd.c:- the function to execute cd command
launch.c:- the function to execute built in commands other than pwd,cd,echo
echo.c:- the function to execute echo command
pwd.c:- the function to execute pwd command
exit.c:- to exit the shell
exec.c:- to execute any command
dirpath.c:- to change the dirpath to print in the shell as the initial signature each time  
readline.c:- the function to parse the given string of commands properly
split.c:- to split the content of the string parsed.
loop.c:- the function to print the initials in shell and to run the read,split,execute cycle again and again.
main.c:- has the main function

