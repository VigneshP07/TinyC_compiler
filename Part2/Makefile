all :
	lex tinyC2.l
	yacc -d tinyC2.y
	gcc -o a.out lex.yy.c tinyC2.c

run :
	./a.out < input.c > output.txt

clean :
	rm -f a.out output.txt lex.yy.c y.tab.h y.tab.c