all: cmdif codigo
	echo "=== Execução ==="
	./mdp/interpretador < codigo

codigo: cmdif entrada.txt
	./cmdif < entrada.txt > codigo
	echo "=== Codigo ==="
	cat codigo

cmdif: lex.yy.c y.tab.c
	g++-9 y.tab.c -o cmdif -lfl

lex.yy.c: cmdif.l
	lex cmdif.l

y.tab.c: cmdif.y
	yacc cmdif.y

clean:
	rm -f lex.yy.c y.tab.c cmdif