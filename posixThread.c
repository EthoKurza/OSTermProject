#include <stdlib.h>
#include "buffer.h"
#include <pthread.h>

//declare variables
buffer item_buffer
//declare functions
int insert_item(buffer item item);
int remove_item(buffer item *item);

void *producer(void *param){	
	buffer item item;
 	while (true) {
 		//sleep for a random period of time
 		sleep(...);
 		//generate a random number
 		item = rand();
 		if (insert item(item)==(-1))
 			fprintf("report error condition");
 		else
 			printf("producer produced %d\n",item);
 	}	
}

void *consumer(void *param){
	/*
	buffer item item;

 	while (true) {
 	//sleep for a random period of time
 	sleep(...);
 	if (remove item(&item))
 		fprintf("report error condition");
 	else
 		printf("consumer consumed %d\n",item);
 	}
	*/
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
	buffer item_buffer[BUFFER SIZE];
	
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
int insert_item (buffer item item) {
	/* insert item into buffer 
	return 0 if successful, otherwise
	return -1 indicating an error condition */
	
}

//remove item from buffer
int remove_item(buffer item *item) {
	/* remove an object from buffer 
	placing it in item
	return 0 if successful, otherwise
	return -1 indicating an error condition */
}

/*
	Regular errors should be printed to stderr() by means of fprintf(). The choice of when to terminate the program on specific errors is left to you.
	
	Failed system calls should use the perror() function for reporting error messages.
*/
