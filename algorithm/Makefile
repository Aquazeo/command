hsort: heapsort.o hsort.o
	gcc -o bin/hsort heapsort.o hsort.o

heapsort.o: src/heapsort.c include/core.h include/heapsort.h
	gcc -c src/heapsort.c -I include

hsort.o: src/hsort.c include/heapsort.h
	gcc -c src/hsort.c -I include

.PHONY: clean

clean:
	rm *.o
