objects = main.o genBoard.o dataMgmt.o


edit : $(objects)
	cc -o edit $(objects) -lm
main.o : main.c genBoard.h dataMgmt.h
	cc -c main.c
genBoard.o : genBoard.c  characters.h

dataMgmt.o : dataMgmt.c 

clean :
	rm edit $(objects)


testObj = test.o


test : $(testObj)
	cc -o test $(testObj)
test.o : test.c
	cc -c test.c