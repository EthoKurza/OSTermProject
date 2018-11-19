#include <stdlib.h>
#include "buffer.h"
#include <pthread.h>
#define BUFFER_SIZE 5
//declare variables
buffer_item buffer[BUFFER_SIZE];
int curBufferSize = 0;//current buffer size

//declare functions
int insert_item(buffer_item item);
int remove_item(buffer_item *item);

void *producer(void *param){	
	buffer_item item;
 	while (true) {
 		//sleep for a random period of time
 		sleep(...);
 		//generate a random number
 		item = rand();
 		if (insert item(item))
 			fprintf("report error condition");
 		else
 			printf("producer produced %d\n",item);
 	}	
}

void *consumer(void *param){
	
	buffer_item item;

 	while (true) {
 	//sleep for a random period of time
 	sleep(...);
 	if (remove item(&item))
 		fprintf("report error condition");
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
	buffer[BUFFER_SIZE] = { 0 } 
	
	pthread_t tid;
	
	/* 3. Create producer thread(s) */
	for(int i = 0; i > producerNum; i++){
		pthread_create(&tid, NULL, producer, NULL);
		
	}

	/* 4. Create consumer thread(s) */
	for(int i = 0; i > consumerNum; i++){
		pthread_create(&tid, NULL, consumer, NULL);
	}

	/* 5. Sleep */
	sleep(sleepLength);

	/* 6. Exit */
	return 0;
}//end of main

//insert item into buffer 
int insert_item (buffer_item item) {
	//check if buffer is full
	if(currBufferSize < BUFFER_SIZE){
		buffer[currBufferSize] = item;	//add item since buffer isnt full
		return 0;
	}
	else{
		return -1;	//buffer is full 
	}
	
	
}

//remove item from buffer
int remove_item(buffer_item *item) {
	//declare variables
	int i, tempItem = buffer[0], arrSize=sizeof(buffer);
	*item = tempItem;
	
	if(*item == buffer[i]){
		for(i = 0 ; i < arrSize; i++){
			buffer[i]=buffer[i+1];
		}//end of for loop
	curBufferSize--;
	return 0;
	}//end of if statement
	else{
		return -1;
	}

}//end of function remove_item

/*
	Regular errors should be printed to stderr() by means of fprintf(). The choice of when to terminate the program on specific errors is left to you.
	
	Failed system calls should use the perror() function for reporting error messages.
*/
