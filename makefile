objects = main.o genBoard.o dataMgmt.o characters.o ant.o


edit : $(objects)

	cc -o edit $(objects) -lm

main.o : main.c genBoard.h dataMgmt.h characters.h
	cc -c main.c
genBoard.o : genBoard.c  characters.h

dataMgmt.o : dataMgmt.c 

characters.o : characters.c

ant.o : ant.c characters.h

clean :
	rm edit $(objects)
	rm -r output_files/*


testObj = test.o

outclean:
	rm -r output_files/*

test : $(testObj)
	cc -o test $(testObj)
test.o : test.c
	cc -c test.c


