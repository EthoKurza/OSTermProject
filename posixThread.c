#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"
#include <pthread.h>

//declare global variables
buffer_item buffer[BUFFER_SIZE];
int curBufferSize = 0;//current buffer size

//declare functions
int insert_item(buffer_item item);
int remove_item(buffer_item *item);

void *producer(void *param){	
	buffer_item item;
 	while (1) {
 		//sleep for a random period of time
 		sleep(rand() % 5 + 1);	//prevents it from sleeping for too long
 		item = rand();
 		if (insert_item(item))
 			printf("Error, buffer was unable to insert\n");
 		else
 			printf("producer produced %d\n",item);
 	}	
}

void *consumer(void *param){
	buffer_item item;
	
 	while (1) {
 		//sleep for a random period of time
 		sleep(rand() % 5 + 1);	//prevents it from sleeping for too long
 		if (remove_item(&item))
 			printf("Error, buffer was unable to remove\n");
 		else
 			printf("consumer consumed %d\n",item);
 	}
	
}

int main(int argc, char *argv[]) {

	//Check if enough arguments are entered
	if (argc < 4){
		printf("not enough arguments entered \n");
		exit(0);
	}

	/* 1. Get command line arguments  argv[1],argv[2],argv[3] */
	int sleepLength = atoi(argv[1]);
	int producerNum = atoi(argv[2]);
	int consumerNum = atoi(argv[3]);
	
	
	/* 2. Initialize buffer */
	//buffer_item buffer[BUFFER_SIZE] = { 0 }; //already declared and initialized above
	curBufferSize = 0;
	pthread_t tid[producerNum];
	pthread_t tid2[consumerNum];
	
	/* 3. Create producer thread(s) */
	int i;
	for(i = 0; i < producerNum; i++){
		pthread_create(&tid[i], NULL, producer, NULL);
	}

	/* 4. Create consumer thread(s) */
	for(i = 0; i < consumerNum; i++){
		pthread_create(&tid2[i], NULL, consumer, NULL);
	}

	/* 5. Sleep */
	sleep(sleepLength);

	/* 6. Exit */
	return 0;
}//end of main


//functions/methods

//insert item into buffer 
int insert_item (buffer_item item) {
	//check if buffer is full
	if(curBufferSize != BUFFER_SIZE){
		buffer[curBufferSize] = item;	//add item since buffer isnt full
		curBufferSize++;
		return 0;	//item was succesfully added to the buffer
	}
	else{
		return -1;	//buffer is full, therefore the item wasn't added to the buffer
	}
	
}//end of insert_item function

//remove item from buffer
int remove_item(buffer_item *item) {
	//declare variables
	int tempItem = buffer[0];

	//Check if buffer is empty
	if(curBufferSize != 0){
		*item = tempItem;
		curBufferSize--;	//since an item was removed , the buffer size should decrease
		return 0;		//item was successful removed
	}//end of if statement
	else{
		return -1;	//item was not removed
	}//end of else state ment

}//end of function remove_item


