run: build
	./main
	rm ./main

build:
	clang++ ./main.cpp -o ./main