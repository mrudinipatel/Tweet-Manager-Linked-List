#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

int searchTweetsByKeyword(tweet * tweetList){
  char * keyword = malloc(sizeof(char) * 142);
  tweet * temp = tweetList;
  char * wordFound;
  int counter = 0;

  /*
   * This function prompts the user to enter a keyword they
   * wish to search ALL the tweets by. I then enter a while loop
   * that iterates through the list until NULL. Inside, I compare
   * the user's keyword to the tweets in the list using the function
   * 'strcasestr'. This function is very very similar to strstr. However, 
   * because we want to this function to be case-INsensitive, and strstr is
   * case-sensitive, 'strcasestr' is a better choice. I then print the tweet and
   * username of entries that match the keyword and return 1 to main if found,
   * or return 0 if not found and a companying message.
  */
  
  printf("Enter a keyword to search: ");
  getchar();
  fgets(keyword, 141, stdin);
  keyword[strlen(keyword) - 1] = '\0';

  while (temp != NULL){
    wordFound = strcasestr(temp -> text, keyword); // 'strcasestr' function requires a special flag: -o -D_GNU_SOURCE
    
    if (wordFound != NULL){
      printf("Match found for '%s': %s wrote: \"%s\"\n", keyword, temp -> user, temp -> text);
      counter = 1;
    }

    temp = temp -> next;
  }

  if (counter == 0){
    printf("This keyword was not found in the database.\n");
  }

  free(keyword);
  return counter;
}
