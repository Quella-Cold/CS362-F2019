#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define NUM_TESTS 100
#define MAX_NUM_PLAYER 8
#define MAX_NUM_HAND 8
#define SEED_VAL 1000

int main(int argc, char const *argv[]) {

  srand(time(NULL));

  struct gameState G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
               sea_hag, tribute, smithy
              };

  int choice1;
  int choice2;
  int handPos;
  int currentPlayer;
  int num_player;
  int seed;
  int init_coins;
  int coins;
  int i;
  int j;
  int new_numaction;

  for(i=0;i<NUM_TESTS;i++){
    printf("<<<<<<<<<< minion test %d>>>>>>>>>>>\n", i+1);
    num_player = rand()%(MAX_NUM_PLAYER -1) + 2;
    seed = rand()%SEED_VAL;
    choice2 = 0;
    handPos = 0;
    coins = 0;
    initializeGame(num_player, k, seed, &G);

    choice1 = rand()%2 + 1;
    currentPlayer = rand()%num_player;
    init_coins = G.coins;


    card_minion(&G, choice1, choice2, handPos,currentPlayer);
    if(new_numaction == (G.numActions+1))
      printf("Pass numActions check!!!!!!!!\n");
    else
      printf("Failed numActions check!!!!!!\n");

    // case choice1 = 1
    if(choice1 == 1){
      printf("^^^^^^^^^^choice1 = 1^^^^^^^^^^^^\n");
        if(coins == (init_coins + 2))
          printf("Pass coin number check!!!!!!!!\n");
        else
          printf("Failed coin number check > ^ <\n");
    }
    //case choice1 = 0
      printf("^^^^^^^^^^ choice1 = 2 ^^^^^^^^^^^^\n");
    if(choice1 == 2){
      for(j=0;j<num_player;j++){
        if(G.handCount[num_player]==4)
          printf("Pass handCount check!!!!!\n");
        else
          printf("Failed handCount check!!!!!\n");
      }
    }
}
  printf("Test finish..\n");


  return 0;
}
