#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

int main(int argc, char * argv[]) {
  int choice;
  tweet * tweetList = NULL; // assigninig head to NULL at the start.
  /*
   * Please note: 'retVal' cannot be freed. This is because we must account for
   * the case when we delete ALL the tweets in the linked list using the menu
   * option 5, before exiting the program using menu option 8. If we were to free
   * 'retVal', we would encounter a malloc memory error indicating that we are freeing
   * a pointer that is not being allocated anything and would abort the ./a3 executable.
   * 
   * Regardless of this specific case, I am going to free 'retVal'
   * to ensure that all tweets in memory are in fact being freed
   * upon exiting the program.
  */
  tweet * retVal;
  retVal = malloc(sizeof(tweet));

  do {
    /*
     * This do-while loop will print the menu over and over again,
     * until the user enters '8' which exits the program altogether.
     * If the user enters a number less than 1 or greater than 8, 
     * an error message will be printed and they will be prompted
     * to enter their choice again. According to the user's choice,
     * the corresponding functions will be called to perform the
     * user's task of choice. 
    */
    printf("1. Create a new tweet\n");
    printf("2. Display tweets\n");
    printf("3. Search a tweet (by keyword)\n");
    printf("4. Find how many words are “stop words” (stop words are explained in a later section)\n");
    printf("5. Delete the nth tweet\n");
    printf("6. Save tweets to a file\n");
    printf("7. Load tweets from a file \n");
    printf("8. Exit\n");

    printf("Choose a menu option: ");
    scanf("%d", &choice);

    if (choice == 1){
      retVal = createTweet(tweetList);
      addNodeToList(&tweetList, retVal);
    }
    else if (choice == 2){
      displayTweets(tweetList);
    }
    else if (choice == 3){
      searchTweetsByKeyword(tweetList);
    }
    else if (choice == 4){
      countStopWords(tweetList);
    }
    else if (choice == 5){
      deleteTweet(&tweetList);
    }
    else if (choice == 6){
      saveTweetsToFile(tweetList);
    }
    else if (choice == 7){
      loadTweetsFromFile(&tweetList);
    }

    if (choice > 8 || choice < 1){
      printf("Error, option was not found in menu. Please try again.\n\n");
    }

  } while (choice != 8);

  free(retVal);
  free(tweetList); // freeing the list at the end of the program (when user selects menu option 8).

  return 0;
}
