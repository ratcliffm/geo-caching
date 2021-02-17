lab5: main.cpp coordinates.cpp test.cpp coordinates.h
	g++ -Wall -Werror -lgtest -std=c++11 main.cpp coordinates.cpp test.cpp -o lab5

test: test.cpp coordinates.cpp
		g++ -Wall -Werror -lgtest -std=c++11 coordinates.cpp test.cpp -o test