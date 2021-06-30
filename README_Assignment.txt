1. Windows is used for execution of this assignment and command prompt is used.
2. To run the assignment please use make command on cmd.
3. Type make on terminal after it finishes type output to run the actual game.
4. exit the program using command ctrl+c.

/* MAKEFILE */
-output: assignment_CC.tab.cpp lex.yy.cpp header_CC.h main.cpp
	g++ main.cpp assignment_CC.tab.cpp lex.yy.cpp -o output

-lex.yy.cpp: assignment_CC.tab.hpp
	flex -olex.yy.cpp assignment_CC.lpp

-assignment_CC.tab.hpp: assignment_CC.ypp
	bison -d assignment_CC.ypp

-assignment_CC.tab.cpp: assignment_CC.ypp
	bison -d assignment_CC.ypp

-clean:
	rm -f *.o output *tab.* lex.yy.cpp

/* MAKEFILE */
PS:-> If make command is not working type following commands in given order:
 
     bison -d assignment_CC.ypp

     flex -olex.yy.cpp assignment_CC.lpp

     g++ main.cpp assignment_CC.tab.cpp lex.yy.cpp -o output

     output