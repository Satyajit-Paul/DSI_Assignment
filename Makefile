output: main.o instruction.o
	g++ main.o instruction.o -o output

main.o: main.cpp
	g++ main.cpp -c

instruction.o: instruction.cpp instruction.h
	g++ instruction.cpp -c

clean:
	rm *.o output
