all: user worker

user: user.o
	gcc -o user user.o

user.o: user.c
	gcc -c user.c

worker: worker.o
	gcc -o worker worker.o

worker.o: worker.c
	gcc -c worker.c