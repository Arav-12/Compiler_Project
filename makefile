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