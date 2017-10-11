all: finalq3

finalq3: main.o key_val.o RedBlacktree.o node.o
	g++ main.o key_val.o RedBlacktree.o node.o -o finalq3

main.o: main.cpp
	g++ -c main.cpp

key_val.o: key_val.cpp
	g++ -c key_val.cpp

RedBlacktree.o: RedBlacktree.cpp
	g++ -c RedBlacktree.cpp

node.o: node.cpp
	g++ -c node.cpp

clean:
	 rm *.o finalq3
