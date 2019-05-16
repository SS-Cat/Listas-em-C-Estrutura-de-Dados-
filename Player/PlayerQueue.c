#include "PlayerQueue.h"

void initPlayerQueue(PlayersQueue *queue, int quantJogadores)
{
    queue->end = 0;
    queue->size = quantJogadores;
    queue->jogadores = (Player *)malloc(sizeof(Player) * quantJogadores);
}

void enqueue(PlayersQueue *queue, Player jogador)
{
    queue->jogadores[queue->end] = jogador;
    queue->end++;
}

void dequeue(PlayersQueue *queue, Player *jogador)
{
    *jogador = queue->jogadores[0];
    for (int i = 0; i < queue->end - 1; i++)
    {
        queue->jogadores[i] = queue->jogadores[i + 1];
    }
    queue->end--;
}

void nextPlayer(PlayersQueue *queue)
{
    Player jogador;
    dequeue(queue, &jogador);
    enqueue(queue, jogador);
}