//A base for our prototype

#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <iostream>

using namespace std;
 

//initializes end, a variable that will tell us if the game is over or if it has ended
int end = 0;

//initalizes the stones in each hole for player and computer                  
//0-5 are holes, 6 is the end hole                                             //initalize the array to hold tokens and score
int score_array[14];
 
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
    if(turn == 1){
      turn = 0;
      //Player turn
    }
    if(turn == 0){
      turn = 1;
      //Computer turn
    }
  }
  }
  }
}

bool gameover_check() {
  
  if ((score_array[6] + score_array[13]) == 48) {

    if (score_array[6] > score_array[13]) {
      cout << "Player one wins!" << endl;
      cout  << "P1 score: " << score_array[6]<< " | P2 score: " << score_array[13] << endl;
      return true;
    }

    else if (score_array[6] < score_array[13]) {
      cout << "Player two wins!" << endl;
      cout  << "P1 score: " << score_array[6]<< " | P2 score: " << score_array[13] << endl;
      return true;
    }

    else {
      cout << "It's a tie!" << endl;
      cout  << "P1 score: " << score_array[6]<< " | P2 score: " << score_array[13] << endl;
      return true;
    }  
  }

  else {
    return false;
  }
}


  int main(void) {
    for (int i = 0; i < 15; i++) {
      if (i == 6 || i == 13) {
        score_array[i] = 0;
      }
      else {
        score_array[i] = 4;
      }
    }
  
    while (end == 0) {
      //player moves BAD FIX IT
      for (int i = 0; i < 14; i++) {
	printf("%s", "Player side: ");
	if (i < 5) {
	  printf("%s%d%s", " ", score_array[i], " ");
	printf("/n%s", "Computer side: ");
	if (i > 6) {
          printf("%s%d%s", " ", score_array[i], " ");
        }

      }
      printf("%s/n", "Pick a number from 1 to 6: ");
      int player_input = -1;
      player_input = getchar();
      player_input = (int) player_input;
      next_turn(player_input);

      //if game is over, break
      if (gameover_check()) {
        break;
      }
  
      //computer checks if it can get an extra turn
      for (int i = 7; i < 13; i++){
	if (score_array[i] == 13-i){
	  next_turn(i);
	}
      }
      //computer checks if it can steal through empty space
      for (int i = 8; i < 13; i++){
	if (score_array[i] == 0){
	  for(int n = 7; n < i; n++){
	    if(score_array[n] == (i - n)){
	      next_turn(n);
	  }
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
    printf("%s%d%s%d","Player Score: ",score_array[6]," Computer Score: ",score_array[13]);
    if(score_array[6] > score_array[13]){
      printf("%s", "Player wins!");
    }
    if(score_array[6] < score_array[13]){
      printf("%s", "Computer wins!");
    }
    if(score_array[6] == score_array[13]){
      printf("%s","It's a tie!");
    }
  }
