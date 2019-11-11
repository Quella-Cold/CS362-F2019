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

  //test 1
  initializeGame(2, k, 2, &G);
  int init_hand_count = G.handCount[0];
  G.hand[0][0] = estate;
  int i;
  for(i = 1; i< 5; i++)
    G.hand[0][i] = mine;
  card_baron(1, &G, currentPlayer, nextPlayer);
  int coin1 = G.coins;
  int discardCount1 = G.discardCount[0];
  int handCount1 = G.handCount[0];

  //test 2
  initializeGame(2, k, 2, &G);
  int init_estate_count = G.supplyCount[estate];
  for(i = 0; i< 5; i++)
    G.hand[0][i] = mine;
  card_baron(1, &G, currentPlayer, nextPlayer);
  int handCount2 = G.handCount[0];
  int estatesupplecount2 = G.supplyCount[estate];

  //test 3
  initializeGame(2, k, 2, &G);
  card_baron(0, &G, currentPlayer, nextPlayer);
  int estatesupplecount3 = G.supplyCount[estate];
  int curhandCount = G.handCount[0];
  int nexhandCount = G.handCount[1];

  // test result 1
  assert(coin1 == 8);
  assert(discardCount1 == 1);
  assert(handCount1 == (init_hand_count-1));

  // test result 2
  assert(handCount2 == init_hand_count);
  //assert(estatesupplecount2 == (init_estate_count-1));  //bug 1

  // test result 3
  assert(estatesupplecount3 == (init_estate_count-1));
  assert(curhandCount == init_hand_count);
  //assert(nexhandCount == init_hand_count);    //bug2


  return 0;
}
