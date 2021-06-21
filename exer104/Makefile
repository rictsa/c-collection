setting=-g -O4 -Wall -lm
file:testStackQueue.c mystruct.o list.o queue.o stack.o
	gcc testStackQueue.c mystruct.o list.o queue.o stack.o -o a.out
mystruct.o list.o queue.o stack.o:mystruct.c list.c queue.c stack.c
	gcc mystruct.c -c $(setting) -o mystruct.o
	gcc list.c -c $(setting) -o list.o
	gcc queue.c -c $(setting) -o queue.o
	gcc stack.c -c $(setting) -o stack.o
