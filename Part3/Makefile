a.out: translator.cpp tinyC3.tab.c lex.yy.c
	g++ translator.cpp tinyC3.tab.c lex.yy.c

tinyC3.tab.c: tinyC3.y
	bison -d tinyC3.y

lex.yy.c: tinyC3.l tinyC3.tab.h
	flex tinyC3.l

tinyC3.tab.h: tinyC3.y
	bison -d tinyC3.y

clean: 
	rm a.out tinyC3.tab.c lex.yy.c tinyC3.tab.h
	rm ./output/*.out
	rmdir output

test: a.out
	mkdir -p output
	./a.out<./input/test1.c>./output/quads1.out
	./a.out<./input/test2.c>./output/quads2.out
	./a.out<./input/test3.c>./output/quads3.out
	./a.out<./input/test4.c>./output/quads4.out
	./a.out<./input/test5.c>./output/quads5.out