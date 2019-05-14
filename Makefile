all: main.c Cards/card.c Cards/DeckofCards.c
	gcc -g ./main.c ./Cards/*.c ./Player/*.c ./Board/*.c -o play

start: all run

run:
	play

clear:
	rm *.o *.ghc play