#include <fstream>
#include <iostream>

#define FILENAME "./input"

int main(){
  std::fstream file(FILENAME, std::ios::in);
  if(!file.is_open()) return -1;
  
  int localSum = 0, highest = 0, second = 0, third = 0;
  for(char input[16]; file.getline(&input[0], 16);){
    if(input[0] == 0){
      if(localSum >= highest){
        third = second;
        second = highest;
        highest = localSum;
      }else{ if(localSum >= second){
          third = second;
          second = localSum;
        }else{ if(localSum >= third){
            third = localSum;
          }
        }
      }
      localSum = 0; 
    }
    localSum += std::atoi(&input[0]);
  }
  localSum = 0; 
  std::cout << highest + second + third << std::endl;
  return 0;
}