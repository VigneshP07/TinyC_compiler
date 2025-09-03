test: a.out
	./a.out < test.c

a.out: lex.yy.c
	gcc tinyC1.c -o a.out

lex.yy.c: tinyC1.l
	lex tinyC1.l

clean:
	rm -f lex.yy.c a.out