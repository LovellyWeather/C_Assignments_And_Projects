/* File: makeReverseString.c
   Compile by: gcc -o reverseString makeReverseString.c
   Run by: ./reverseString
   Output: An entered string reversed
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverseString(char*, int, int);
void reverseWords(char*, int);

int main() {
  
  char string[100] = "Today is a good day to Learn C";
  printf("String to Reverse: %s\n", string);
  reverseString(string, 0,  strlen(string) - 1);
  reverseWords(string, strlen(string));
  printf("%s\n", string);
}

void reverseString(char* buffer, int startIndex, int endIndex) {

  int ch, i, j;
  for (i = startIndex, j = endIndex; i < j; i++, j--) {
    ch = buffer[i];
    buffer[i] = buffer[j];
    buffer[j] = ch;
  }
}

void reverseWords(char* buffer, int strLength) {
  
  if (*buffer == '\0')
    return;

  int startWord = 0, endWord = 0;
  while (endWord < strLength) {
    while (buffer[endWord] != ' ' && buffer[endWord] != '\0') {
      endWord++;
    }
    reverseString(buffer, startWord, endWord-1);
    startWord = ++endWord;
  }
}
