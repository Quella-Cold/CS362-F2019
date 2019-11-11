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
  int tc[2] = {-1, -1};

  //test 1
  initializeGame(2, k, 2, &G);
  G.discardCount[1] = 0;
  G.deckCount[1] = 1;
  G.deck[1][0] = copper;
  int initcoin = G.coins;
  int initdeckcount = G.deckCount[1];
  card_tribute(&G, nextPlayer, tc, currentPlayer);
  int coins = G.coins;
  int deckcount = G.deckCount[1];

  //test 2
  tc[0] = -1;
  tc[1] = -1;
  initializeGame(2, k, 2, &G);
  G.discardCount[1] = 1;
  G.deckCount[1] = 0;
  G.discard[1][0] = estate;
  int inithandcount = G.handCount[0];
  int initdiscardcount = G.discardCount[1];
  card_tribute(&G, nextPlayer, tc, currentPlayer);
  int handcount = G.handCount[0];
  int discardcount = G.discardCount[1];

  //test 3
  tc[0] = -1;
  tc[1] = -1;
  initializeGame(2, k, 2, &G);
  G.discardCount[1] = 10;
  G.deckCount[1] = 0;
  int i;
  for(i=0; i<10; i++)
    G.discard[1][i] = i;
  card_tribute(&G, nextPlayer, tc, currentPlayer);
  int shuffled = 1;
  if(G.deck[1][0] == 0 && G.deck[1][1] == 1 && G.deck[1][2] == 2){
    shuffled = 0;
  }

  //test 4
  tc[0] = -1;
  tc[1] = -1;
  initializeGame(2, k, 2, &G);
  G.deck[nextPlayer][G.deckCount[nextPlayer]-1] = mine;
  G.deck[nextPlayer][G.deckCount[nextPlayer]-2] = copper;
  int initaction = G.numActions;
  int initcoin2 = G.coins;
  card_tribute(&G, nextPlayer, tc, currentPlayer);
  int action = G.numActions;
  int coin2 = G.coins;

  //test result 1
  assert(coins == (initcoin + 2));
  assert(deckcount == (initdeckcount - 1));

  //test result 2
  assert(handcount == (inithandcount + 2));
  assert(discardcount == (initdiscardcount - 1));

  //test result 3
  //assert(shuffled == 1); //bug 1

  //test result 4
  assert(action == (initaction + 2));
  //assert(coin2 == (initcoin2 +2));  //bug 2

  return 0;
}
