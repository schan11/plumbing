all: processor controller

processor: processor.c
	gcc -o processor processor.c

controller: controller.c
	gcc -o controller controller.c

clear:
	rm *.o
	rm processor controller
