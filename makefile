#My own makefile for ML lab 3

#Declare variables
CC=g++
LIBS=-lm

#First create ".exe" called finds
pca: PCA.o
	$(CC) PCA.o -o pca $(LIBS)

#Need to make Audio.o file though
PCA.o: PCA.cpp
	$(CC) -c PCA.cpp


#Other rules

#Clean .o and exe
clean:
	@rm -f *.o
	@rm -f pca

#To run program
run:
	./pca
