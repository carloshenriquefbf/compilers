all: mini_js codigo
	echo "=== Execução ==="
	./mdp/interpretador < codigo

codigo: mini_js entrada.txt
	./mini_js < entrada.txt > codigo
	echo "=== Codigo ==="
	cat codigo

mini_js: lex.yy.c y.tab.c
	g++-9 y.tab.c -o mini_js -lfl

lex.yy.c: mini_js.l
	lex mini_js.l

y.tab.c: mini_js.y
	yacc mini_js.y

clean:
	rm -f lex.yy.c y.tab.c mini_js