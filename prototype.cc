//A base for our prototype

#include <stdio.h>
#include <limits.h>
#include <math.h>

//initializes end, a variable that will tell us if the game is over or if it has ended
int end = 0;

//initalizes the stones in each hole for player and computer                  
//0-5 are holes, 6 is the end hole                                               //initalize the array to hold tokens and score
  int score_array[14];
 
  for (int i = 0; i < 15; i++) {
    if (i == 6 || i == 13) {
      score_array[i] = 0;
    }
    else {
      score_array[i] = 4;
    }
  }

void next_turn(int position){
  int tokens = score_array[position];
  int turn = -1;
  score_array[position] = 0;
  //if we're starting on player turn, turn = 0
  if (position < 6) {
    turn = 0;
  }
  //if we're starting on computer turn, turn = 1 
  if (position > 6) {
    turn = 1;
  }
  while(tokens != 0){
    position = position + 1;
    if (position > 13){
      position = 0;
    }
    if ((position==6 && turn==1)||(position==13 && turn==0)){
      position = position + 1;
    }
    score_array[position] = score_array[position]+1;
    tokens = tokens - 1;
  }
  if (turn==0){
    if(score_array[position]==1 && score_array[position+7]!=0){
      score_array[6] = score_array[6] + score_array[position+7] + 1;
      score_array[position+7] = 0;
      score_array[position] = 0;
  }
    if(position==6){
      //Player goes again - add code once function is complete
  }
  }
  if (turn==1){
    //if we're starting on computer turn, turn = 1 
  if (position > 6) {
    turn = 1;
  }
  while(tokens != 0){
    position = position + 1;
    if (position > 13){
      position = 0;
    }
    if ((position==6 && turn==1)||(position==13 && turn==0)){
      position = position + 1;
    }
    score_array[position] = score_array[position]+1;
    tokens = tokens - 1;
  }
  if (turn==0){
    if(score_array[position]==1 && score_array[position+7]!=0){
      score_array[6] = score_array[6] + score_array[position+7] + 1;
      score_array[position+7] = 0;
      score_array[position] = 0;
  }
    if(position==6){
      //Player goes again - add code once function is complete
  }
  }
  if (turn==1){
    //if we're starting on computer turn, turn = 1 
  if (position > 6) {
    turn = 1;
  }
  while(tokens != 0){
    position = position + 1;
    if (position > 13){
      position = 0;
    }
    if ((position==6 && turn==1)||(position==13 && turn==0)){
      position = position + 1;
    }
    score_array[position] = score_array[position]+1;
    tokens = tokens - 1;
  }
  if (turn==0){
    if(score_array[position]==1 && score_array[position+7]!=0){
      score_array[6] = score_array[6] + score_array[position+7] + 1;
      score_array[position+7] = 0;
      score_array[position] = 0;
  }
    if(position==6){
      //Player goes again - add code once function is complete
  }
  }
  if (turn==1){
   if(score_array[position]==1 && score_array[position-7]!=0){
      score_array[13] = score_array[13] + score_array[position-7] + 1;
      score_array[position-7] = 0;
      score_array[position] = 0;
  }
    if(position==13){
      //Computer goes again - add code once function is complete                  
  }
  } 
  else{
    if(turn==1){
      turn = 0;
      //Player turn
    }
    if(turn==0){
      turn = 1;
      //Computer turn
    }
  }
}


while (end == 0) {
  //player moves

  //if game is over, break
  
  //computer checks if it can get an extra turn
  for(int i=0;i<6;i++){
    if(c[i] == i){
      for(int n=i;n>=0;n++){
	c[n] = c[n] + 1;
      }
      next = 1;
      break;
    }
  }
  if(next==1){
    continue;
  }
  //computer checks if it can steal through empty space
  for(int i=0;i<5;i++){
    for(int n=6;n>i;n--){
      if(c[i]==0&&c[n]==(n-i)){
	next_turn(n);
      }
    }
  }
		
  //if not extra turn or steal, computer picks random hole and moves
  int r = 1 + rand()%6;
  next_turn(r);
  //if game is over, break
  if(end==1){
    break;
  }
 }

//print final scores
printf("%s%d%s%d","Player Score: ",pgoal," Computer Score: ",cgoal);
if(pgoal>cgoal){
  printf("%s","Player wins!");
 }
if(cgoal>pgoal){
  printf("%s","Computer wins!");
 }
if(cgoal==pgoal){
  printf("%s","It's a tie!");
 }
