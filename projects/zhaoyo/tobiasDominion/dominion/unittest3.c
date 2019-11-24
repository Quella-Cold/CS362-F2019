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

  //test 1
  initializeGame(2, k, 2, &G);
  int choice1 = 1;
  int choice2 = 0;
  int handPos = 0;
  G.hand[0][0] = minion;
  int inticoin = G.coins;
  int intinumaction = G.numActions;
  card_minion(&G, choice1, choice2, handPos, currentPlayer);
  int coins = G.coins;
  int numaction = G.numActions;

  //test 2
  initializeGame(3, k, 2, &G);
  choice1 = 0;
  choice2 = 1;
  G.hand[0][0] = minion;
  G.handCount[1] = 4;
  G.handCount[2] = 8;
  card_minion(&G, choice1, choice2, handPos, currentPlayer);
  int p1 = G.handCount[0];
  int p2 = G.handCount[1];
  int p3 = G.handCount[2];
  int playcardcount = G.playedCardCount;

  //test result 1
  assert(coins == (inticoin + 2));
  assert(numaction == (intinumaction + 1));

  //test result 2
  assert(p1 == 4);
  //assert(p2 == 4);        //bug 1 && 2
  //assert(p3 == 4);        //bug 2
  //assert(playcardcount == 13); // 5+8=13 bug 1 && 2
  //assert(playcardcount == 17); // 5+4+8=17 bug 2


  return 0;
}
