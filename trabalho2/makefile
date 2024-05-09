all: saida entrada.txt
	./saida < entrada.txt

lex.yy.c: code.l
	lex code.l

saida: lex.yy.c
	g++ -Wall -std=c++17 lex.yy.c -ll -o saida

clean:
	rm saida lex.yy.c
