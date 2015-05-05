/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 * Checks to see if a given string has all unique characters.
 * Requires an argument
 *
 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <stdio.h>
#include <string.h>


unsigned short isUniqueChars(char* str) {
  
  int checker = 0;
  int val, i;
 
  for (i = 0; i < strlen(str); i++) {
    val = str[i] - 'a';
    if ((checker & (1 << val)) > 0)
      return 0;
    checker |= (1 << val);
  }
  return 1;
}

int main(int argc, char *argv[]) {

  (isUniqueChars(argv[1])) ? printf("Yes, the characters are unique.\n") :
    printf("No, the characters are not unique.\n");

  return 0;
}
