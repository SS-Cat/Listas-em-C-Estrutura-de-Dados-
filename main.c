#include <stdio.h>
#include <stdlib.h>
#include "Cards/DeckofCards.h"
#include "Player/CardStack.h"
#include "Player/Player.h"
#include "Board/Board.h"

void initGame(DeckOfCards *deck, GameBoard *board, int quantidade);

int quantidadeJogadores();

bool fillHand(Player *player, DeckOfCards *deck);

int continuaGame();

int main(void)
{
	bool ingame = true, end = false;
	DeckOfCards deck;
	GameBoard board;
	Card tempCard;
	while (!end)
	{
		initDeck(&deck);
		shuffle(&deck);

		int quantidade = quantidadeJogadores();

		initGame(&deck, &board, quantidade);

		if (continuaGame() == 0)
			end = true;
	}
	return 0;
}

void initGame(DeckOfCards *deck, GameBoard *board, int quantidade)
{
	Card tempCard;
	initBoard(board, quantidade);
	int QuantDeCartasParaJogadores = 4 * quantidade;
	for (int i = 0; i < QuantDeCartasParaJogadores; i++)
	{
		dealCard(deck, &tempCard);
		int contaParaTrocaAlternada = i % quantidade;
		addToHand(&board->jogadores[contaParaTrocaAlternada], tempCard);
	}
	for (int i = 0; i < 6; i++)
	{
		dealCard(deck, &tempCard);
		addListNode(board, tempCard);
	}
}

int quantidadeJogadores()
{
	printf("Bem Vindo ao Roba Monte\nQuantos Jogadores?\nEntre um numero de 2 a 4: ");
	int quantidade = -1;
	scanf("%d", &quantidade);
	while (quantidade < 2 || quantidade > 4)
	{
		printf("Numero invalido,\ndigite novamente: ");
		scanf("%d", &quantidade);
	}
	return quantidade;
}

bool fillHand(Player *player, DeckOfCards *deck)
{
	Card card;
	if (player->handCount > 0)
		return false;

	while (player->handCount < 4)
	{
		bool result = dealCard(deck, &card);
		if (result == false)
			return false;

		addToHand(player, card);
	}
}

int continuaGame()
{
	int resposta;
	printf("Deseja jogar novamente? ( 0 para responder nao ): ");
	scanf("%d", &resposta);
	return resposta;
}