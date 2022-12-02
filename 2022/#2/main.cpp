#include <fstream>
#include <iostream>

#define DRAW 3
#define WIN  6

#define PART2 

#define FILENAME "./input"

int main(){
  std::fstream file(FILENAME, std::ios::in);
  if(!file.is_open()) return -1;

  int myscore = 0;

  for(char input[4]; file.getline(&input[0], 4);){
    int oponentsMove  = input[0] - 64;
    int myMove        = input[2] - 87;

    #ifdef PART1
      myscore += myMove;

      if(myMove == oponentsMove) myscore += DRAW;
      else if(myMove == oponentsMove + 1 || (myMove == 1 && oponentsMove == 3)) myscore += WIN;
    #endif


    #ifdef PART2
      if(myMove == 1) myscore += (oponentsMove - 1) ? oponentsMove - 1 : 3;
      else if(myMove == 2) myscore += oponentsMove + DRAW;
      else myscore += ((oponentsMove + 1 != 4) ? oponentsMove + 1 : 1) + WIN;
    #endif
  }

  std::cout << myscore << std::endl;

  return 0;
}