clean:
	rm -rf *.o *.gch bin

bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp
