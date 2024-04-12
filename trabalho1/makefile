all: saida entrada.txt
	./saida < entrada.txt

lex.yy.c: scan.l
	lex scan.l

saida: lex.yy.c main.cc
	g++ -Wall -std=c++17 main.cc -ll -o saida

clean:
	rm saida lex.yy.c
