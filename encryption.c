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
    int keyFileChar;
    int inputChar;
    int outputChar;
    int prevChar;
    int i;
    int j;
    int keyFileCounter;
    char *key = malloc(256 * sizeof(char));
    int *S = malloc(i * sizeof(int));
    int *T = malloc(i * sizeof(int));
   
    if (argc < 3) 
    	printf("Input and output files need to be specified\n");
    keyFile = fopen(argv[1], "r");
    ifp = fopen(argv[2], "r");
    ofp = fopen(argv[3], "w");

    assert(keyFile != NULL);
    assert(ifp != NULL);
    assert(ofp != NULL);

    S[i] = i;
    T[i] = key[i % kLength]);
    
    j = 0;
    for(i = 0; i < 256; i++){
    	j = (j+*(S+i)+*(T+i)) % 256;
    	swap(*(S+i), *(S+j));
    }

    keyFileCounter = 0;
    while ((keyFileChar = fgetc(keyFile))!=EOF && keyFileCounter<256){ //scans in keyFile and stores in key
        *key++ = (char)fgetc(keyFile); 
     }

    encrypt_data(input, output, keyFile); //XOR data and write it to file


    fclose(keyFile);
    fclose(ifp);
    fclose(ofp);

}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void encrypt_data(FILE* input_file, FILE* output_file, FILE* keyFile){
    int key_count = 0; //Restart if strlen(keyFile) < strlen(encrypt)
    int encrypt_byte;
    
    while( (encrypt_byte = fgetc(input_file)) != EOF){//Loop through each byte of file until EOF
        fputc(encrypt_byte ^ keyFile[key_count], output_file); //XOR the data and write it to a file
    }
}