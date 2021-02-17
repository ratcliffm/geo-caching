lab5: main.cpp coordinates.cpp test.cpp coordinates.h
	g++ -Wall -Werror -lgtest -std=c++11 main.cpp coordinates.cpp test.cpp -o lab5

test: lab5
		g++ -Wall -Werror -lgtest -std=c++11 test.cpp -o test