#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

tweet * createTweet(tweet * tweetList){
  int userID = 0, lenUser = 0, lenTweet, i, sum = 0;
  /*
   * Please note: I am allocating more bytes to the two pointers below
   * for a reason: in order to validate the user's inputs
   * I must scan in more than the max limit of bytes (referred
   * to from the struct). Only then can I code an if statement
   * that correctly validates the user's inputs.
  */
  char * tempUser = malloc(sizeof(char) * 150);
  char * tempText = malloc(sizeof(char) * 150);
  tweet * temp = tweetList;
  tweet * node = malloc (sizeof(tweet)); // this cannot be freed in this function because we are returning it to main.

  /*
   * This function will allow the user to manually enter a tweet.
   * Here I am prompting the user for their username and tweet
   * to be entered. I will be validating the user's inputs through
   * the 2 if statements following each prompt. I then store the
   * ASCII values of the username into the 'sum' variable which I
   * will then use to add to 'lenTweet' to calculate the 'userID'.
  */

  printf("Enter a username: ");
  getchar();
  fgets(tempUser, 60, stdin);
  tempUser[strlen(tempUser) - 1] = '\0';
  lenUser = strlen(tempUser);
  
  if (lenUser == 0){ 
    printf("Error, you must enter a valid username.\n");
    return NULL;
  }
  else if (lenUser > 51){
    printf("Error, you must enter a valid username. Please try again.\n");
    free(tempUser);
    exit(0); // ** SECTION C) - README.md (reference).
  }

  for (i = 0; i < tempUser[i]; i++){
    sum += tempUser[i];
  }

  printf("Enter the user’s tweet: ");
  fgets(tempText, 150, stdin);
  tempText[strlen(tempText) - 1] = '\0';
  lenTweet = strlen(tempText);

  
  if (lenTweet == 0){
    printf("Error, you must enter a valid tweet.\n");
    return NULL;
  }
  else if (lenTweet > 141){
    printf("Error, you must enter a valid tweet. Please try again.\n");
    free(tempText);
    exit(0); // ** SECTION C) - README.md (reference).
  }

  userID = sum + lenTweet;

  /*
   * To ensure no duplicate userID's are stored, I iterate through the list
   * and check to see if userID exists. If it does, I form a random userID
   * between 1 and 999 and store that instead. To prevent the loop from 
   * randomizing the same userID over and over again, I use the srand function.
  */

  srand(time(NULL));  
  while (temp != NULL){
    if (userID == temp -> id){
      userID = (rand() % 999) + 1;
    }
    temp = temp -> next;
  }

  printf("Your computer-generated userid is %d.\n", userID);

  /*
   * After printing the userID in terminal, I store the username, tweet,
   * and userID inside a node in the linked list and return the same node
   * back to the main function to be added to the end of the list using
   * the addNodeToList function (also called when user enters '1').
  */

  node -> id = userID;
  strcpy(node -> user, tempUser);
  strcpy(node -> text, tempText);
  node -> next = NULL;

  free(tempUser);
  free(tempText);
  
  return node;
}
