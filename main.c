#include <stdio.h>
#include <stdlib.h>
#include "Cards/DeckofCards.h"
#include "Player/CardStack.h"
#include "Player/Player.h"
#include "Board/Board.h"
#include "Player/PlayerQueue.h"

void initGame(DeckOfCards *deck, GameBoard *board, PlayersQueue *queue, int quantidade);

int quantidadeJogadores();

void createPlayers(PlayersQueue *queue, int quantJogadores);

bool fillHand(Player *player, DeckOfCards *deck);

int continuaGame();

int main(void)
{
	bool ingame = true, end = false;
	DeckOfCards deck;
	GameBoard board;
	PlayersQueue queue;
	while (!end)
	{
		initDeck(&deck);
		shuffle(&deck);

		int quantidade = quantidadeJogadores();

		// deck Baralho
		// board Mesa
		// queue Jogadores

		initGame(&deck, &board, &queue, quantidade);
		int final = 0;
		while (ingame)
		{
			int entrada;
			printf("Vez do Jogador %s\n", queue.jogadores[0].nome);
			printHand(queue.jogadores[0]);
			printList(board);
			printf("Topos:\n");
			for (int i = 0; i < quantidade; i++)
			{
				if (queue.jogadores[i].cardStack.size > 0)
				{
					printf("Selecione %d |", i + board.size);
					printCard(cardTop(queue.jogadores[i]));
					printf("^Carta do %s\n",queue.jogadores[i].nome);
					
				}
			}
			printf("Qual carta? (-1 se não tiver nenhuma carta): ");
			scanf("%d", &entrada);

			CardNode *retirarCarta;
			Card *retirado;
			Card tempCard;
			int estado = 0;
			int escolha;

			while (true)
			{
				if (entrada == -1)
				{
					if (entrada < board.size)
					{
						for (int i = 0; i < queue.jogadores[0].handCount; i++)
						{
							if (searchCardBoard(board, queue.jogadores[0].hand[i]) == true)
							{
								printf("Existe carta par na mesa, tente denovo: ");
								scanf("%d", &entrada);
								continue;
							}
						}
					}
					else
					{
						for (int i = 0; i < quantidade; i++)
						{
							if (searchCard(queue.jogadores[0], cardTop(queue.jogadores[i])) > -1)
							{
								printf("Existe carta par em algum topo, tente denovo: ");
								scanf("%d", &entrada);
								continue;
							}
						}
					}
					estado = 0;
				}
				else if (entrada < board.size + 1)
				{
					retirarCarta = pickIndex(board, entrada);
					tempCard = retirarCarta->card;
					bool selecao = removeOfHand(&queue.jogadores[0], &tempCard);
					if (selecao == false)
					{
						printf("Não tem essa Carta na mão\n");
						printf("Entre com outro numero: ");
						scanf("%d", &entrada);
						continue;
					}

					retirado = removeListNode(&board, retirarCarta->card);
					if (retirado == NULL)
					{
						printf("Carta não tem na lista\n");
						printf("Entre com outro numero: ");
						scanf("%d", &entrada);
						continue;
					}
					estado = 1;
				}
				else
				{
					escolha = entrada - board.size + 1;
					Card top;
					if (queue.jogadores[escolha].cardStack.size > 0)
						top = cardTop(queue.jogadores[escolha]);
					tempCard = top;
					bool selecao = removeOfHand(&queue.jogadores[0], &tempCard);
					if (selecao == false)
					{
						printf("Não tem essa Carta na mão\n");
						printf("Entre com outro numero: ");
						scanf("%d", &entrada);
						continue;
					}

					if (searchCard(queue.jogadores[0], top) > -1)
					{
						estado = 2;
					}
					else
					{
						printf("Essa carta não faz par\n");
						printf("Entre com outro numero: ");
						scanf("%d", &entrada);
						continue;
					}
				}
				break;
			}


			if (estado == 0)
			{
				removeOfHand(&queue.jogadores[0], &tempCard);
				addListNode(&board, tempCard);
			}
			else if (estado = 1)
			{
				pushCardNode(&queue.jogadores[0].cardStack, tempCard);
				pushCardNode(&queue.jogadores[0].cardStack, *retirado);
			}
			else if (estado == 2)
			{
				mergeStacks(&queue.jogadores[0].cardStack, &queue.jogadores[escolha].cardStack);
			}

			for (int i = 0; i < quantidade; i++)
			{
				if (queue.jogadores[i].handCount == 0)
				{
					for (int i = 0; i < 4; i++)
					{
						dealCard(&deck, &tempCard);
						addToHand(&queue.jogadores[i], tempCard);
					}
				}
			}
			if (board.size == 0)
			{
				for (int i = 0; i < 6; i++)
				{
					dealCard(&deck, &tempCard);
					addListNode(&board, tempCard);
				}
			}

			nextPlayer(&queue);

			if (deck.numberOfCards <= 0)
			{
				final++;
			}
			if (final == 3)
			{
				int maior[] = {0, 0};
				for (int i = 0; i < quantidade; i++)
				{
					if (queue.jogadores[i].cardStack.size > maior[0])
					{
						maior[0] = queue.jogadores[i].cardStack.size;
						maior[1] = i;
					}
				}
				printf("Parabens %s", queue.jogadores[maior[1]].nome);
				ingame = false;
			}
		}

		if (continuaGame() == 0)
			end = true;
	}

	return 0;
}

void initGame(DeckOfCards *deck, GameBoard *board, PlayersQueue *queue, int quantidade)
{

	Card temp;
	initBoard(board);
	initPlayerQueue(queue, quantidade);
	createPlayers(queue, quantidade);

	int QuantDeCartasParaJogadores = 4 * quantidade;
	for (int i = 0; i < QuantDeCartasParaJogadores; i++)
	{
		dealCard(deck, &temp);
		int contaParaTrocaAlternada = i % quantidade;
		addToHand(&queue->jogadores[contaParaTrocaAlternada], temp);
	}
	for (int i = 0; i < 6; i++)
	{
		dealCard(deck, &temp);
		addListNode(board, temp);
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

void createPlayers(PlayersQueue *queue, int quantJogadores)
{
	int JogadorInicial = rand() % quantJogadores;
	for (int i = 0; i < quantJogadores; i++)
	{
		char *nome = (char *)malloc(sizeof(char) * 10);
		printf("Digite o nome do jogador %d (max 10 char): ", i + 1);
		scanf("%s", nome);
		Player jogador;
		jogador.nome = nome;
		initPlayer(&jogador, i + 1);
		enqueue(queue, jogador);
	}

	while (JogadorInicial != 0)
	{
		nextPlayer(queue);
		JogadorInicial--;
	}
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