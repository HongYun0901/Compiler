all: parser

parser: lex.yy.cpp y.tab.cpp main.cpp main.h
	g++ y.tab.cpp main.cpp -o parser -ll -ly  -std=c++11 -lstdc++ -Wno-deprecated-register

lex.yy.cpp: lex.l
	lex -o lex.yy.cpp lex.l

y.tab.cpp: yacc.y
	yacc -d yacc.y -o y.tab.cpp

clean:
	rm parser lex.yy.cpp lex.yy.c y.tab.*
