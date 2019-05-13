all: main.c Cards/card.c Cards/DeckofCards.c
	gcc -g ./*.c ./Cards/*.c ./Player/*.c -o main

run:
	main.exe

clean:
	rm *.o