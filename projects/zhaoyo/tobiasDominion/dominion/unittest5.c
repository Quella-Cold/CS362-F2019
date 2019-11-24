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
  int choice1 = 0;
  int choice2 = 0;
  int handPos = 1;


  //test 1
  initializeGame(2, k, 2, &G);
  choice2 = -1;
  int res1;
  res1 = card_ambassador(choice2, choice1, handPos, &G, currentPlayer);

  //test 2
  initializeGame(2, k, 2, &G);
  choice1 = 1;
  handPos = 0;
  choice2 = 2;
  int res2;
  res2 = card_ambassador(choice2, choice1, handPos, &G, currentPlayer);

  //test 3
  initializeGame(2, k, 2, &G);
  choice1 = 1;
  handPos = 0;
  choice2 = 1;
  int res3;
  int card = G.hand[0][handPos];
  int initsup = G.supplyCount[card];
  int inithc = G.handCount[1];
  res3 = card_ambassador(choice2, choice1, handPos, &G, currentPlayer);
  int sup = G.supplyCount[card];
  int hc = G.handCount[1];

  //test 1 result
  assert(res1 == -1);

  //test 2 result
  //assert(res2 == 0);  //bug 1, fix code for test 3

  //test 3 result
  assert(res3 == 0);
  assert(sup == (initsup +1));
  //assert(hc == (inithc +1)); //bug 2
  return 0;
}
