all: project1

clean:
	rm project1

project1_class: project1.c
	gcc -Wall -o project1 project1.c
