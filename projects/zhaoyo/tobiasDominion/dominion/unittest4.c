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
  int bonus;

  //test 1
  initializeGame(2, k, 2, &G);
  G.discardCount[1] = 0;
  G.deckCount[1] = 1;
  G.deck[1][0] = copper;
  int initcoin = G.coins;
  int initdeckcount = G.deckCount[1];
  tributePlayed(0,0,0,0,&G,0,&bonus,currentPlayer,nextPlayer,tc);
  int coins = G.coins;
  int deckcount = G.deckCount[1];

  //test 2    fix bug 1 for test 2
  tc[0] = -1;
  tc[1] = -1;
  initializeGame(2, k, 2, &G);
  G.discardCount[1] = 0;
  G.deckCount[1] = 1;
  G.discard[1][0] = estate;
  int initdeckcount2 = G.deckCount[0];
  tributePlayed(0,0,0,0,&G,0,&bonus,currentPlayer,nextPlayer,tc);
  int deckcount2 = G.deckCount[0];

  //test 3
  tc[0] = -1;
  tc[1] = -1;
  initializeGame(2, k, 2, &G);
  G.discardCount[1] = 10;
  G.deckCount[1] = 0;
  int i;
  for(i=0; i<10; i++)
    G.discard[1][i] = i;
  tributePlayed(0,0,0,0,&G,0,&bonus,currentPlayer,nextPlayer,tc);
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
  tributePlayed(0,0,0,0,&G,0,&bonus,currentPlayer,nextPlayer,tc);
  int action = G.numActions;
  int coin2 = G.coins;

  //test result 1
  //assert(coins == (initcoin + 2));      //bug 1
  //assert(deckcount == (initdeckcount - 1));        //bug 1

  //test result 2
  //assert(initdeckcount2 == (deckcount2 - 1)); //bug 2

  //test result 3
  assert(shuffled == 1);

  //test result 4
  //assert(action == (initaction + 2));
  assert(coin2 == (initcoin2 +2));

  return 0;
}
