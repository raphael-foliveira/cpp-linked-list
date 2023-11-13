build:
	clang++ ./main.cpp -o ./main

run: build
	./main
	rm ./main