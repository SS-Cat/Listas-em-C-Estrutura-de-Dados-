// DeckOfCards deck;
// initDeck(&deck);
// shuffle(&deck);

/* teste para monte
	CardStack stack1;
	CardStack stack2;
	initStack(&stack1);
	initStack(&stack2);
	for (int i = 0; i < 10; i++)
		pushCardNode(&stack1, deck.cards[i]);
	for (int i = 0; i < 10; i++)
		pushCardNode(&stack2, deck.cards[i + 11]);

	mergeStacks(&stack1, &stack2);

	printCard(stack1.bottom->card);
	*/
/* teste para Jogador
	Player jogador1;
	jogador1.handCount = 0;
	Card card;
	dealCard(&deck, &card);
	addToHand(&jogador1, card);
	dealCard(&deck, &card);
	addToHand(&jogador1, card);
	dealCard(&deck, &card);
	addToHand(&jogador1, card);
	dealCard(&deck, &card);
	addToHand(&jogador1, card);

	printHand(jogador1);

	removeOfHand(&jogador1, card);
	removeOfHand(&jogador1, card);

	printHand(jogador1);
	*/
/*
	* teste para o comando dealCard
	for (int i = 0; i < deck.numberOfCards + 1; i++)
	{
		Card card;
		dealCard(&deck, &card);
		printCard(card);
	}
	*/
/*
	* teste para vê se deck foi preenxido corretamente
	for (int i = 0; i < deck.numberOfCards; i++)
	{
		if (i % 2 == 0)
			printf(GRN BGYEL "%s of %s\n" RESET, deck.cards[i].faceName, deck.cards[i].suit);
		else
			printf(YEL BGGRN "%s of %s\n" RESET, deck.cards[i].faceName, deck.cards[i].suit);
	}
	*/
