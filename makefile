all: bin/Alphabet

test: bin/unit_test
	./bin/unit_test

bin/unit_test: build/test/main.o build/test/text.o build/test/main_test.o build/test/list_element.o
	g++ -Wall -Werror build/test/main_test.o build/test/main.o build/test/text.o build/tests.o -o bin/test_app build/test/list_element.o

build/test/main_test.o: test/main.cpp
	g++ -Wall -Werror -I thirdparty -I src -c test/main.cpp -o build/test/main_test.o 

build/test/main.o: src/main.cpp
	g++ -Wall -Werror -I thirdparty -I src -c src/main.cpp -o build/test/main.o

build/test/text.o: src/text.cpp
	g++ -Wall -Werror -I thirdparty -I src -c src/text.cpp -o build/test/text.o

build/test/list_element.o: src/list_element.cpp
	g++ -Wall -Werror -I thirdparty -I src -c src/list_element.cpp -o build/test/list_element.o


bin/Alphabet: build/main.o build/text.o build/list_element.o
	g++ -Wall -Werror build/src/main.o build/src/text.o build/src/list_element.o -o bin/Alphabet

build/list_element.o: src/list_element.cpp
	g++ -Wall -Werror -c src/list_element.cpp -o build/src/list_element.o 

build/text.o: src/text.cpp
	g++ -Wall -Werror -c src/text.cpp -o build/src/text.o 

build/main.o: src/main.cpp
	g++ -Wall -Werror -c src/main.cpp -o build/src/main.o 

clean:
	rm -rf build/src/*.o build/test/*.o bin/Alphabet bin/unit_test

.PHONY: all clean test
