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
  int choice1 = 0;
  int choice2 = 0;
  int choice3 = 0;
  int handPos = 0;
  int bonus;


  //test 1
  initializeGame(2, k, 2, &G);
  choice1 = 1;
  handPos = 1;
  int res1;
  res1 = ambassadorPlayed(0,choice1,choice2,choice3,&G,handPos,&bonus,0,currentPlayer,nextPlayer);

  //test 2
  initializeGame(2, k, 2, &G);
  choice1 = 1;
  handPos = 0;
  choice2 = 0;
  int init_dis = G.discardCount[0];
  ambassadorPlayed(0,choice1,choice2,choice3,&G,handPos,&bonus,0,currentPlayer,nextPlayer);
  int dis = G.discardCount[0];


  // //test 3
  // initializeGame(2, k, 2, &G);
  // choice1 = 1;
  // handPos = 0;
  // choice2 = 1;
  // int res3;
  // int card = G.hand[0][handPos];
  // int initsup = G.supplyCount[card];
  // int inithc = G.handCount[1];
  // res3 = ambassadorPlayed(0,choice1,choice2,choice3,&G,handPos,&bonus,0,currentPlayer,nextPlayer);
  // int sup = G.supplyCount[card];
  // int hc = G.handCount[1];

  //test 1 result
  //assert(res1 == -1); //bug 1        when choice1 equals handPos, should return -1

  //test 2 result
  //assert(init_dis == (dis - 1));     The current player should discard one card


  // //test 3 result
  // assert(res3 == 0);
  // assert(sup == (initsup +1));
  // //assert(hc == (inithc +1));
  return 0;
}
