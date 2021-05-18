#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

void saveTweetsToFile(tweet * tweetList){
  tweet * temp = tweetList;
  char * filename = malloc(sizeof(char) * 30);

  /*
   * This function will save whichever tweets are inside the linked list
   * into a file of the user's choice. I do this by prompting the user to enter
   * a filename and open that filename for the tweets to be stored.
   * 
   * Please note: I am using the 'a' (append) notation to write to the file of choice.
   * This allows the program to create the file IF the file does not already exist in the
   * directory and write to the end of an existing file. I then store the tweets by using the 
   * fprintf function which prints the tweets into the file to be saved. A success
   * message is then printed to the terminal to notify user that the job is done.
  */
  
  printf("Enter the filename where you would like to store your tweets: ");
  scanf("%s", filename);

  FILE * file = fopen(filename, "a");

  while(temp != NULL){
    fprintf(file, "%d, %s, %s\n", temp -> id, temp -> user, temp -> text);
    temp = temp -> next;
  }

  printf("Output successful!\n");
  
  fclose(file);
  free(filename);
}
