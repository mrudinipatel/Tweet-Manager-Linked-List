#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

void countStopWords(tweet * tweetList){
  /*
   * Here I am storing all 25 of the stop words into an array. Since I am strtoking the tweets, and I know
   * that strtok modifies the original string, I created an array 'tempStr' that I will use to strcpy the original tweets into.
  */
  char stopWords[ ][25] = {"a", "an", "and", "are", "as", "at", "be", "by", "for", "from", "has", "he", "in", "is", "it", "its", "of", "on", "that", "the", "to", "was", "were", "will", "with"};
  tweet * temp = tweetList;
  char * token;
  char tempStr[141];
  int i, numTweets = 0, wordFound, total = 0;

  /*
   * In this loop, I iterate through the list until NULL. Inside, I compare each of the tokenized words in the tweets
   * to the stopWords array inside a for loop that iterates 25 times. If a stop word is found, I increment a counter and
   * print the appropriate message after the loop. Please note: I am tokenizing space, newline, null, and a lot of
   * punctuations. This is to account for a case where the stop word could possibly be followed by any of these characters.
  */

  while (temp != NULL){
    for (i = 0; i < 25; i++){
      strcpy (tempStr, temp -> text);
      token = strtok(tempStr, " \n.,!?;:\0");

      while (token != NULL){
        wordFound = strcmp(token, stopWords[i]);
        
        if (wordFound == 0){
          total++;
        }
        
        token = strtok(NULL, " \n.,!?;:\0");
      }
    }
    numTweets++;
    temp = temp -> next;
  }
  
  printf("Across %d tweets, %d stop words were found.\n", numTweets, total);
}
