all: mymatrix

mymatrix: main.o datatype.o bstree.o matrix.o
	g++ main.o datatype.o bstree.o matrix.o -o mymatrix

main.o: main.c
	g++ -c main.c

datatype.o: datatype.c
	g++ -c datatype.c

bstree.o: bstree.c
	g++ -c bstree.c

matrix.o: matrix.c
	g++ -c matrix.c

clean:
	rm *o mymatrix