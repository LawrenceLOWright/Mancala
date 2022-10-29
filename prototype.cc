//A base for our prototype

#include <stdio.h>
#include <limits.h>
#include <math.h>

//initializes end, a variable that will tell us if the game is over or if it has ended
int end = 0;
int next = 0;

//initalizes variables to hold computer (c) and player (p) # of points
int cgoal = 0;
int pgoal = 0;

//initalizes the stones in each hole for player and computer
int p1 = 4;
int p2 = 4;
int p3 = 4;
int p4 = 4;
int p5 = 4;
int p6 = 4;

int c1 = 4;
int c2 = 4;
int c3 = 4;
int c4 = 4;
int c5 = 4;
int c6 = 4;

void next_turn(int i){
  int b = c[i];
  c[i] = 0;
  while(b!=0){
    i = i+1;
    if(i>6){
      i = 0;
      continue;
    }
    c[i] = c[i]+1;
    b = b-1;
  }
  if(c[i]==1&&p[i]!=0){
    cgoal= cgoal + p[i] + 1;
    c[i] = 0;
    p[i] = 0;
  }
  if(c[i]==cgoal){
    //current turn gets to go again
  }
  else{
    //next person
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
