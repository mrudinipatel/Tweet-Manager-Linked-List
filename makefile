a3: createTweet.o addNodeToList.o displayTweets.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o mainA3.o
	gcc -Wall -std=c99 createTweet.o addNodeToList.o displayTweets.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o mainA3.o -o a3

mainA3.o: mainA3.c 
	gcc -Wall -std=c99 -c mainA3.c

createTweet.o: createTweet.c
	gcc -Wall -std=c99 -c createTweet.c

addNodeToList.o: addNodeToList.c
	gcc -Wall -std=c99 -c addNodeToList.c

displayTweets.o: displayTweets.c
	gcc -Wall -std=c99 -c displayTweets.c

searchTweetsByKeyword.o: searchTweetsByKeyword.c
	gcc -Wall -std=c99 -c searchTweetsByKeyword.c

countStopWords.o: countStopWords.c
	gcc -Wall -std=c99 -c countStopWords.c

deleteTweet.o: deleteTweet.c
	gcc -Wall -std=c99 -c deleteTweet.c

saveTweetsToFile.o: saveTweetsToFile.c
	gcc -Wall -std=c99 -c saveTweetsToFile.c

loadTweetsFromFile.o: loadTweetsFromFile.c
	gcc -Wall -std=c99 -c loadTweetsFromFile.c

clean:
	rm *.o a3
