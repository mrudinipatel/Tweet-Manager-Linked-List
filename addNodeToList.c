#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

void addNodeToList(tweet**tweetList,tweet * node){
  /*
   * This function will take the node returned from
   * the createTweet function into main and the head
   * of the list. It will then iterate through the 
   * list and if the list is empty (no tweets
   * in it already), then node will become the head.
   * Otherwise, it will enter a loop that will push
   * the node to the end of the list.
  */

  if (node != NULL){
    if (*tweetList == NULL){
      *tweetList = node;
    }
    else{
      tweet * lastNode = *tweetList;

      while(lastNode -> next != NULL){
        lastNode = lastNode -> next;
      }

      lastNode -> next = node;
    }
  }
}
