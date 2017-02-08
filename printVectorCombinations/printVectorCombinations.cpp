#include <iostream>
#include <string>
#include <vector>

void printWords(const std::vector<std::vector<std::string> > &all_words) {
  int steps = 0;
  bool keep_going = true;
  size_t all_words_size = all_words.size();

  int word_count;
  int word_count_array[all_words_size];
  for( size_t i=0; i<all_words_size; i++) {
    word_count_array[i] = 0;
  }
  
  while(keep_going) {
    for(size_t i=0; i<all_words_size; i++) {
      word_count = word_count_array[i];
      std::cout << all_words[i][word_count] << " ";
    }
    std::cout << std::endl;

    word_count_array[all_words_size-1]++;

    for(size_t j=all_words_size; j-- > 0;) {
      word_count = word_count_array[j];
      if(word_count == all_words[j].size()) {
        if( j ) {
          word_count_array[j] = 0;
          word_count_array[j-1]++;
        } else {
          keep_going = false;
        }
      }
    }
    steps++;
  }
}

int main(int argc, char *argv[]) {
  
  std::vector<std::string> words1; words1.push_back("quick"); words1.push_back("lazy");
  std::vector<std::string> words2; words2.push_back("brown"); words2.push_back("black"); words2.push_back("grey");
  std::vector<std::string> words3; words3.push_back("fox"); words3.push_back("dog");
  
  std::vector<std::vector<std::string> > all_words; all_words.push_back(words1); all_words.push_back(words2); all_words.push_back(words3);

  printWords(all_words);
  
  return 0;
}
