#include "Player.h"
#include <stdlib.h>

typedef struct players
{
    int end;
    int size;
    Player *jogadores;
} PlayersQueue;

void initPlayerQueue(PlayersQueue *queue, int quantJogadores);

void enqueue(PlayersQueue *queue, Player jogador);

void dequeue(PlayersQueue *queue, Player *jogador);

void nextPlayer(PlayersQueue *queue);
