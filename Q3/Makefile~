all: finalq2

finalq2: main.o Iterator.o key_val.o AVLtree.o node.o
	g++ main.o Iterator.o key_val.o AVLtree.o node.o -o finalq2

main.o: main.cpp
	g++ -c main.cpp

Iterator.o: Iterator.cpp
	g++ -c Iterator.cpp

key_val.o: key_val.cpp
	g++ -c key_val.cpp

AVLtree.o: AVLtree.cpp
	g++ -c AVLtree.cpp

node.o: node.cpp
	g++ -c node.cpp

clean:
	 rm *.o finalq2
