#include "Player.h"

void initPlayer(Player *player, int id)
{
	CardStack stack;
	initStack(&stack);
	player->cardStack = stack;
	player->handCount = 0;
	player->id = id;
}

void printHand(Player player)
{
	printf("Mão:\n");
	for (int i = 0; i < player.handCount; i++)
	{
		printCard(player.hand[i]);
	}
}

bool addToHand(Player *player, Card card)
{
	if (player->handCount == 4)
		return false;
	int i;
	for (i = player->handCount - 1; i >= 0 && player->hand[i].faceNumber > card.faceNumber; i--)
		player->hand[i + 1] = player->hand[i];

	player->hand[i + 1] = card;
	player->handCount++;
	return true;
}

bool removeOfHand(Player *player, Card *card)
{
	if (player->handCount == 0)
		return false;

	int result = searchCard(*player, *card);

	if (result == -1)
		return false;

	int i;
	*card = player->hand[result];
	for (i = result; i < player->handCount; i++)
		player->hand[i] = player->hand[i + 1];

	player->handCount--;

	return true;
}

int searchCard(Player player, Card card)
{
	int left = 0;
	int right = player.handCount;
	int mid;
	int result = -1;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (player.hand[mid].faceNumber == card.faceNumber)
		{
			result = mid;
			break;
		}
		else if (card.faceNumber > player.hand[mid].faceNumber)
			left = mid + 1;
		else
			right = mid - 1;
	}
	
	return result;
}


Card cardTop(Player player)
{
    return player.cardStack.top->card;
}
