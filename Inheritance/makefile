CC= g++
CCFLAGS= -g -w
exec: shape.o main.o makefile
	$(CC) $(CCFLAGS) -o test shape.o main.o
main.o: main.C
	$(CC) $(CCFLAGS) -c main.C
shape.o: shape.C 
	$(CC) $(CCFLAGS) -c shape.C
clean:
	rm -rf *.o