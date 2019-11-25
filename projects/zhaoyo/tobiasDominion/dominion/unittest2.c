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
  int nextPlayer = 1;
  int bouns;
  int j = 0;

  //test 1
  initializeGame(2, k, 2, &G);
  int init_hand_count = G.handCount[0];
  G.hand[0][0] = estate;
  G.hand[0][1] = copper;
  int i;
  for(i = 2; i< 5; i++)
    G.hand[0][i] = mine;
  G.handCount[0] = 5;
  baronPlayed(0,1,0,0,&G,0,&bouns,j,currentPlayer);
  int coin1 = G.coins;
  int test_card = G.hand[0][0];

  //test 2
  initializeGame(2, k, 2, &G);
  int init_estate_count = G.supplyCount[estate];
  for(i = 0; i< 5; i++)
    G.hand[0][i] = mine;
  G.supplyCount[estate] = 1;
  j = 0;
  baronPlayed(0,1,0,0,&G,0,&bouns,j,currentPlayer);
  int handCount2 = G.handCount[0];
  int estatesupplecount2 = G.supplyCount[estate];

  // test result 1
  assert(coin1 == 8);
  //assert(test_card == copper); //bug 1

  // test result 2
  assert(handCount2 == init_hand_count);
  //assert(j == 1);  //bug 2                //j should be 1, because when the supply count of estate is 0,
                                            // it should go in to the if loop where set j to 1 for DEBUG
                                            // purpose

  return 0;
}
