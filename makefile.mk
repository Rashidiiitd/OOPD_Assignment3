 # Makefile for compiling Indian_Bank and Spain_Bank

# Compile Indian_Bank
all: compile link

compile: Main.cpp Non_premitive.cpp
	g++ -c Main.cpp
	g++ -c Non_premitive.cpp

link: 
	g++ -o Main Main.o
	g++ -o Non_premitive Non_premitive.o

run:
	./Main
	./Non_premitive

clean: 
	rm -f Main.o
	rm -f Non_premitive.o

n_debug: Main.cpp Non_premitive.cpp
