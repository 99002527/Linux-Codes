#include <stdio.h>
#include <time.h>   	// for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h> 	// for sleep()

// main function to find the execution time of a C program


void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 


int main()
{
	// to store execution time of code
	double time_spent = 0.0;

	clock_t begin = clock();

	// do some stuff here
	//sleep(3);
    for (int i = 0; i < 100; i++) { 
        // delay of one second
         delay(1); 
    printf("Delay to see time elapsed\n");
    } 

	clock_t end = clock();

	// calculate elapsed time by finding difference (end - begin) and
	// dividing the difference by CLOCKS_PER_SEC to convert to seconds
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Time elpased is %f seconds", time_spent);

	return 0;
}