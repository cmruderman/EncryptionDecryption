// Lab 1 by Chris Ingerson, Corey Ruderman, & Dan Travis

// Reads the input file 
// character by character and then prints what it just read.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>


int main(int argc, char *argv[]) {

	FILE *keyFile;
    FILE *ifp;
    FILE *ofp;
    int inputChar;
    int outputChar;
    int prevChar;
    int i;
    int j;
    int *S;
    int *T;

    if (argc < 3) 
    	printf("Input and output files need to be specified\n");
    keyFile = fopen(argv[1], "r");
    ifp = fopen(argv[2], "r");
    ofp = fopen(argv[3], "w");

    assert(keyFile != NULL);
    assert(ifp != NULL);
    assert(ofp != NULL);

    S = (int *) malloc(i * sizeof(int));
    T[i] = key[i % kLength]);
    
    j = 0;
    for(i = 0; i < 256; i++){
    	j = (j+*(S+i)+*(T+i)) % 256;
    	swap(*(S+i), *(S+j));
    }

     while ((inputChar = fgetc(ifp))!=EOF){
       fputc(inputChar, ofp); 
     }

    fclose(keyFile);
    fclose(ifp);
    fclose(ofp);

}

void swap(int* a, int* b){
 int temp = *a;
 *a = *b;
 *b = temp;
}