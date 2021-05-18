#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

void deleteTweet(tweet ** tweetList){
  tweet * temp = *tweetList;
  tweet * temp2 = *tweetList;
  tweet * prev = *tweetList;
  tweet * curr = *tweetList;
  int i, numTweets = 0, value, numTweetsAfter = 0;

  /*
   * I will first check if the list is NULL. If it is, I printf a message
   * and return back to main where the menu will be reprinted and the
   * user will be prompted to select an option again.
  */

  if (*tweetList == NULL){
    printf("This database is empty.\n");
    return;
  }

  /*
   * I then find the number of tweets in the list by iterating through
   * list until I hit NULL and incrementing a counter.
  */

  while (temp != NULL){
    numTweets++;
    temp = temp -> next;
  }

  /*
   * I then printf the current number of tweets. I then ask the user
   * to input a tweet number they wish to delete from the list. I then
   * validate the input through a single if statement by checking if it
   * falls in the appropriate bounds, otherwise I printf a message and reprompt.
  */

  printf("Currently there are %d tweets.\n", numTweets);
  printf("Which tweet do you wish to delete – enter a value between 1 and %d: ", numTweets);
  scanf("%d", &value);

  if (value > numTweets || value < 1){
    printf("Please enter a valid tweet number you wish to delete.\n");
    return;
  }

  /*
   * If the user wishes to delete the first tweet (head), then the head
   * of the list becomes the next node and we free/delete the head of the list
   * and move to the next nodes.
  */

  if (value == 1){
    (*tweetList) = (*tweetList) -> next;
    free((*tweetList));
    temp2 = temp2 -> next;
  }
  else{
    /*
     * If the user wishes to delete any other tweets (other than head), then the
     * the previous node will become the current node and both will move to the 
     * next nodes in the list until NULL. We then free/delete the current node.
    */
    for (i = 0; i <= value - 2; i++){
      prev = curr;
      curr = curr -> next;
    }

    prev -> next = curr -> next;
    curr -> next = NULL;
    free(curr);
  }

  /*
   * Then I iterate through the 'new list' and increment a counter until we
   * hit NULL. This way we are able to get the number of tweets remaining in the list.
  */
  while (temp2 != NULL){
    numTweetsAfter++;
    temp2 = temp2 -> next;
  }

  printf("Tweet %d deleted. There are now %d tweets left.\n", curr -> id, numTweetsAfter);
}
