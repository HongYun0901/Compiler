ifeq ($(shell uname -s), Darwin)
	javaa := ./javaa_mac
else
	javaa := ./javaa
endif



all: parser

parser: lex.yy.cpp y.tab.cpp main.cpp main.h
	g++ y.tab.cpp main.cpp -o compiler -ll -ly  -std=c++11  -Wno-deprecated-register

lex.yy.cpp: lex.l
	lex -o lex.yy.cpp lex.l

y.tab.cpp: yacc.y
	yacc -d yacc.y -o y.tab.cpp

clean:
	rm parser lex.yy.cpp lex.yy.c y.tab.* y.output output.txt *.jasm *.class

run:
	./compiler $(file).scala
	$(javaa) $(file).scala.jasm
	java $(file)
