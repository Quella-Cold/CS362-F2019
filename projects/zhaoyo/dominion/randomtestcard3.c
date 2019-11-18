#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define NUM_TESTS 100
#define MAX_NUM_PLAYER 8
#define SEED_VAL 1000

int main(int argc, char const *argv[]) {

  srand(time(NULL));

  struct gameState G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
               sea_hag, tribute, smithy
              };
  int tributeRevealedCards[2];
  int currentPlayer;
  int nextPlayer;
  int num_player;
  int seed;
  int init_coins;
  int coins;
  int new_numAction;
  int new_numhandcount;
  int i;

  for(i=0;i<NUM_TESTS;i++){

    printf("<<<<<<<<<< tribute test %d>>>>>>>>>>>\n", i+1);

    num_player = rand()%(MAX_NUM_PLAYER -1) + 2;
    seed = rand()%SEED_VAL+1;
    currentPlayer = rand()%num_player;
    new_numAction = 0;
    coins = 0;
    nextPlayer = currentPlayer + 1;
    new_numhandcount = 0;

    initializeGame(num_player, k, seed, &G);
    card_tribute(&G,nextPlayer,tributeRevealedCards,currentPlayer);

    init_coins = G.coins;

    for (i = 0; i <= 1; i ++) {     //The second card have no effect
        printf("________Check it is Treasure card_________\n");
        if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold) { //Treasure cards
          if(coins == (init_coins+2))
            printf("Pass coin number check!!!!!!!!\n");
          else
            printf("Failed coin number check > ^ <\n");
        }
        else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall) { //Victory Card Found
            printf("________Check it is Victory card_________\n");
            if(new_numhandcount = (G.handCount[currentPlayer]+2))
              printf("Pass num actions check!!!!!\n");
            else
              printf("Faired num actions check!!!!\n");
        }
        else{
          printf("________Check it is Action card_________\n");
          if(new_numAction = (G.numActions+2))
            printf("Pass num actions check!!!!!\n");
          else
            printf("Faired num actions check!!!!\n");
        }
    }
  }
  printf("Test finish..\n");

  return 0;
}
