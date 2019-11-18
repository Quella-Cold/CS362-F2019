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

  int choice1;
  int currentPlayer;
  int nextPlayer;
  int num_player;
  int seed;
  int init_coins;
  int init_num_estate;
  int coins;
  int num_estate;
  int i;
  int j;

  for(i=0;i<NUM_TESTS;i++){

    printf("<<<<<<<<<<Baron test %d>>>>>>>>>>>\n", i+1);

    num_player = rand()%(MAX_NUM_PLAYER -1) + 2;
    seed = rand()%SEED_VAL;

    initializeGame(num_player, k, seed, &G);

    choice1 = rand()%2;
    currentPlayer = rand()%num_player;
    nextPlayer = (currentPlayer + 1)%num_player;

    init_coins = G.coins;

    init_num_estate = 0;
    for(j = 0; j < G.handCount[currentPlayer] ; j++)
      if(G.hand[currentPlayer][j] == estate)
        init_num_estate++;

    card_baron(choice1, &G, currentPlayer, nextPlayer);

    coins = G.coins;
    for(j = 0; j < G.handCount[currentPlayer] ; j++)
      if(G.hand[currentPlayer][j] == estate)
        num_estate++;

    // case choice1 = 1
    if(choice1 == 1){
      printf("^^^^^^^^^^choice1 = 1^^^^^^^^^^^^\n");
      if(num_estate > 0){
        if(coins == (init_coins + 4))
          printf("Pass coin number check!!!!!!!!\n");
        else
          printf("Failed coin number check > ^ <\n");

        if(num_estate == (init_num_estate -1))
          printf("Pass estate card number check!!!!!!!!\n");
        else
          printf("Failed estate card number check >> _ <<\n" );
      }
      else{
        if(coins == init_coins)
          printf("Pass coin number check!!!!!!!!\n");
        else
          printf("Failed coin number check > ^ <\n");

        if(num_estate == 1)
          printf("Pass estate card number check!!!!!!!!\n");
        else
          printf("Failed estate card number check >> _ <<\n" );
      }
    }
    else{
    //case choice1 = 0
      printf("^^^^^^^^^^choice1 = 0^^^^^^^^^^^^\n");
      if(coins == init_coins)
        printf("Pass coin number check!!!!!!!!\n");
      else
        printf("Failed coin number check > ^ <\n");

      if(num_estate == (init_num_estate - 1))
        printf("Pass estate card number check!!!!!!!!\n");
      else
        printf("Failed estate card number check >> _ <<\n" );
    }
  }

  printf("Test finish..\n");


  return 0;
}
