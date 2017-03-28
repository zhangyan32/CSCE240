CC= g++
CCFLAGS= -g -w
exec: PQ.o main.o makefile
	$(CC) $(CCFLAGS) -o test PQ.o main.o
main.o: main.C
	$(CC) $(CCFLAGS) -c main.C
PQ.o: PQ.C 
	$(CC) $(CCFLAGS) -c PQ.C
clean:
	rm -rf *.o