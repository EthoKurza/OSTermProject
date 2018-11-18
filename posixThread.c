#include <stdlib.h>
#include "buffer.h"

int main(int argc, char *argv[]) {

	//Check if enough arguments are entered
	if (argc < 4){
		printf("not enough arguments entered \n");
	}
	
	//declare and inititalize variables
	int sleepLength=0, producerNum=0, consumerLength=0

	/* 1. Get command line arguments  argv[1],argv[2],argv[3] */
	sleepLength = atoi(argv[1]);
	producerNum = atoi(argv[2]);
	consumerLength = atoi(argv[3]);
	
	
	/* 2. Initialize buffer */
	buffer item buffer[BUFFER SIZE];

	//insert item into buffer 
	int inser item (buffer item item) {
		/* inser item into buffer 
		return 0 if successful, otherwise
		return -1 indicating an error condition */
	}

	//remove item from buffer
	int remove item(buffer item *item) {
		/* remove an object from buffer 
		placing it in item
		return 0 if successful, otherwise
		return -1 indicating an error condition */
	}
	/* 3. Create producer thread(s) */

	/* 4. Create consumer thread(s) */

	/* 5. Sleep */

	/* 6. Exit */

}//end of main
