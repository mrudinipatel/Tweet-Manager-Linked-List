#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

void loadTweetsFromFile(tweet ** tweetList){
  tweet * dummy;
  char * filename = malloc(sizeof(char) * 30);
  char * fileContents;
  char * token;
  int size, m;
  long int position;

  /*
   * This function will prompt the user to enter a filename of the file
   * they want to read in to load the tweets into the linked list. 
   * I read the file into 'fileContents' and strtok it to tokenize commas
   * to read the userID and username. I then strtok newline to read the tweet
   * text into the linked list. Because there is a terminating comma in .csv
   * file types, I remove the trailing comma from the text portion of the tweet
   * entry using the 'strrchr' function. This function searches the string for
   * the last occurrence of a comma. I then find the position of the comma and
   * set it equal to NULL to remove the comma from the tweet. I then call upon
   * the addNodeToList function to add the stored tweets into the 'dummy' node
   * into the linked list, and print a success message to the terminal.
  */

  printf("Enter a filename to load from: ");
  scanf("%s", filename);

  FILE * file = fopen(filename, "r");

  if (file == NULL){
    printf("This file is empty, please try again.\n");
    return;
  }
  else {
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    fileContents = calloc(1, sizeof(char) * size + 1); 
    
    fread(fileContents, size, 1, file);

    token = strtok(fileContents, ",");

    while (token != NULL){
      dummy = malloc (sizeof(tweet));
      m = atoi(token);
      dummy -> id = m;
      
      token = strtok(NULL, ",");
      strcpy(dummy -> user, token);

      token = strtok(NULL, "\n");
      strcpy(dummy -> text, token);

      char * searchComma = strrchr(dummy -> text, ',');
      position = searchComma - (dummy -> text);
      dummy->text[position] = '\0';

      // printf("%d,%s,%s\n", dummy -> id, dummy -> user, dummy -> text); // testing printf to see if it stores correctly.

      dummy -> next = NULL;

      addNodeToList(tweetList, dummy);

      token = strtok(NULL, ",");
    }
    printf("Tweets imported!\n");
  }
  fclose(file);
  free(filename);
}
