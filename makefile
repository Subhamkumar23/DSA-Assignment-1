make: exe
	./exe

exe : main.o functions.o
	gcc main.o functions.o -o exe

main.o : main.c functions.h
	gcc -c main.c

functions.o : functions.c functions.h
	gcc -c functions.c

clean:
	rm *.o exe