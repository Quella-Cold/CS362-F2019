#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

int main(int argc, char const *argv[]) {

  struct gameState G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
               sea_hag, tribute, smithy
              };

  int currentPlayer = 0;
  int bouns;

  //test 1
  initializeGame(2, k, 2, &G);
  G.hand[0][0] = copper;
  G.hand[0][1] = mine;
  int j = 0;
  int choice1 = 0;
  int choice2 = treasure_map;
  int handPos = 1;
  int retrnvalue1 = minePlayed(0,choice1,choice2,0,&G,handPos,&bouns,j,currentPlayer);

  //test 2
  initializeGame(2, k, 2, &G);
  G.hand[0][0] = silver;
  G.hand[0][1] = mine;
  choice1 = 0;
  choice2 = treasure_map + 1;
  handPos = 1;
  int retrnvalue2 = minePlayed(0,choice1,choice2,0,&G,handPos,&bouns,j,currentPlayer);

  //test 3
  initializeGame(2, k, 2, &G);
  G.hand[0][0] = gold;
  G.hand[0][1] = mine;
  choice1 = 0;
  choice2 = treasure_map;
  handPos = 1;
  int retrnvalue3 = minePlayed(0,choice1,choice2,0,&G,handPos,&bouns,j,currentPlayer);

  //test 4
  initializeGame(2, k, 2, &G);
  G.hand[0][1] = mine;
  G.hand[0][4] = silver;
  int inithandcount = G.handCount[0];
  choice1 = 4;
  choice2 = treasure_map;
  handPos = 1;
  int retrnvalue4 =minePlayed(0,choice1,choice2,0,&G,handPos,&bouns,j,currentPlayer);
  int handcount = G.handCount[0];


  //test result 1
  //assert(retrnvalue1 == 0);  //bug 1

  //test result 2
  assert(retrnvalue2 == -1);

  //test result 3
  assert(retrnvalue3 == -1);

  //test result 4
  assert(handcount == (inithandcount -1));  //bug 2

  return 0;
}
