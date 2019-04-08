
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#ifdef _MSC_VER
#include <intrin.h> /* for rdtscp and clflush */
#pragma optimize("gt",on)
#else
#include <x86intrin.h> /* for rdtscp and clflush */
#endif

#define array_size  500000
#define flush_size  500000
int i;

int array[array_size] = {};
void *pointer;
pid_t pid;

int main(int argc, const char * * argv) {
	for(int z=0;z<array_size;z++)
	{
       	array[z] = z;
	}

	int len = sizeof (array) /sizeof (int);
 	 for (i=0;i< len;i++) {
 	printf("%d\n", array[i] );
 	 }
  	
     for(int i =0; i<array_size;i++){
    pointer = &array[i];
    printf(" Address is %p ", pointer);
     printf("  data is  is %d \n", array[i]);

 }

printf("Now the data will be flushed\n");



	for (int j = 0; j <flush_size; j++) 
	{
    	_mm_clflush(&array[j]);
	    }


 
	for(int i =0; i<array_size;i++){
    	printf(" Address is %p ", &array[i]);
    	printf("  data is %d \n", array[i]);}
 
  return(0);
			
}
