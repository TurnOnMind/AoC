#include <fstream>
#include <iostream>
#include <string>

#define PART2

#define FILENAME "./input"

int main(){
  std::fstream file(FILENAME, std::ios::in);
  if(!file.is_open()) return -1;

  int priorityscore = 0;

#ifdef PART1

  for(std::string row; std::getline(file, row);){
    for(size_t leftindex = 0; leftindex < row.size()/2; leftindex++){
      const char leftchar = row[leftindex];
      for(size_t rightindex = row.size()/2; rightindex < row.size(); rightindex++){
        const char rightchar = row[rightindex];
        if(leftchar == rightchar){
          if(leftchar < 91) priorityscore += leftchar - 64 + 26;
          else priorityscore += leftchar - 96;
          goto nextstep;
        }
      }
    }
    nextstep:
    continue;
  }

#endif

#ifdef PART2

  std::string elf[3];

  while(std::getline(file, elf[0])){
    std::getline(file, elf[1]);
    std::getline(file, elf[2]);
    for(size_t firstindex = 0; firstindex < elf[0].size(); firstindex++){
      const char firstchar = elf[0][firstindex];
      for(size_t secondindex = 0; secondindex < elf[1].size(); secondindex++){
        if(firstchar != elf[1][secondindex]) continue;
        for(size_t thirdindex = 0; thirdindex < elf[2].size(); thirdindex++){
          if(firstchar == elf[2][thirdindex]){
            if(firstchar < 91) priorityscore += firstchar - 64 + 26;
            else priorityscore += firstchar - 96;
            goto nextstep;
          }
        }
      }
    }
    nextstep:
    continue;
  }

#endif

  std::cout << priorityscore << std::endl;

  return 0;
}