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

    if (argc < 3) 
    	printf("Input and output files need to be specified\n");
    keyFile = fopen(argv[1], "r");
    ifp = fopen(argv[2], "r");
    ofp = fopen(argv[3], "w");

    assert(keyFile != NULL);
    assert(ifp != NULL);
    assert(ofp != NULL);

    char *key = malloc(MAX_SIZE);
    printf("Passphrase: "); // read in key
    fgets(key, MAX_SIZE, stdin);

    //strip newlines
    strip_newline(key);

    //XOR data and write it to file
    encrypt_data(input, output, key);
    
    printf("Encrypted data written to %s\n", argv[2]);

    //Release memory
    free(key);

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