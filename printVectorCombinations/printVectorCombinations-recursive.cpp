#include <iostream>
#include <string>
#include <vector>

void printWords(const std::vector<std::vector<std::string> > &allWords, size_t currentIndex, std::string currentWords) {
  if (currentIndex >= allWords.size()) {
    std::cout << currentWords << std::endl;
    return;
  }
  
  for (size_t i=0; i<allWords[currentIndex].size(); i++) {
    printWords(allWords, currentIndex+1, currentWords + allWords[currentIndex][i] + " ");
  }
}

int main(int argc, char *argv[]) {
  
  std::vector<std::string> words1; words1.push_back("quick"); words1.push_back("lazy");
  std::vector<std::string> words2; words2.push_back("brown"); words2.push_back("black"); words2.push_back("grey");
  std::vector<std::string> words3; words3.push_back("fox"); words3.push_back("dog");
  
  std::vector<std::vector<std::string> > allWords; allWords.push_back(words1); allWords.push_back(words2); allWords.push_back(words3);

  printWords(allWords, 0, "");
  
  return 0;
}
