#include <fstream>
#include <iostream>
#include <vector>
#include <array>

#define FILENAME "./input"

int main(){
  std::fstream file(FILENAME, std::ios::in);
  
  if(!file.is_open()){
    return -1;
  }

  size_t counter = 0;

  int four_previous_values[4] = {0,0,0,0};
  size_t index = 0;
  for(std::array<char, 8> input; file.getline(&input[0], 8, '\n');){
    short modIndex = index % 4;
    four_previous_values[modIndex] = std::atoi(&input[0]);

    if(index > 3 && four_previous_values[modIndex] > four_previous_values[(modIndex + 1) % 4]) counter++;

    index++;
  }

  std::cout << counter << std::endl;
  std::cin.get();

  return 0;
}
