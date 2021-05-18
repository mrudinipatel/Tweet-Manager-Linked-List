#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

void displayTweets(tweet * tweetList){
  tweet * temp = tweetList;

  /*
   * This function will print whatever has
   * been entered in the list. It does this by
   * iterating through a loop until it reaches NULL.
   * Inside is a printf that will print the contents of the
   * nodes in the list and move to the next node until NULL.
  */

  while (temp != NULL){
    printf("%d: Created by %s: %s\n", temp -> id, temp -> user, temp -> text);
    temp = temp -> next;
  }
}
