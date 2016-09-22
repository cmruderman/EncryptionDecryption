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
    char key[256]; // Space for 256 characters
    char S[256]; // State vector 
    char T[256]; // Temporary vector
   
    if (argc < 3) 
    	printf("Input, output, and keyFile need to be specified\n");
    keyFile = fopen(argv[1], "r"); 
    ifp = fopen(argv[2], "r");
    ofp = fopen(argv[3], "w");

    assert(keyFile != NULL); //test if keyFile is there
    assert(ifp != NULL);  //test if message is there
    assert(ofp != NULL);   //test if output file is there

    int kLength = 0;
    while (((keyFileChar = fgetc(keyFile)) != EOF) && (kLength < 256)){ //scans in keyFile and stores in key
        key[kLength++] = (char)fgetc(keyFile); 
     }

    i = 0;
    while(i < 256){
        S[i] = i; //what is i?
        T[i] = key[i % kLength];
        i++;
    }

    j = 0;
    for(i = 0; i < 256; i++){
    	j = (j+S[i] + T[i]) % 256;
    	swap(S[i], S[j]);
    }

    i = 0;
    j = 0;

    generateKeyByte(S);

   // encrypt_data(input, output, keyFile); //XOR data and write it to file

    fclose(keyFile);
    fclose(ifp);
    fclose(ofp);

}

void swap(char a, char b){
	char temp = a;
	a = b;
	b = temp;
}

void encrypt_data(FILE* input_file, FILE* output_file, FILE* keyFile){
    int key_count = 0; //Restart if strlen(keyFile) < strlen(encrypt)
    int encrypt_byte;
    int key_byte;
    
    while((encrypt_byte = fgetc(input_file)) != EOF && ((encrypt_byte = fgetc(keyFile)) != EOF)){ //Loop through each byte of file until EOF
        fputc(encrypt_byte ^ key[key_count], output_file); //XOR the data and write it to a file
        key[key_count] = (char)fgetc(keyFile); 
        generateKeyByte(S);
        key_count++;
    }
}

char generateKeyByte(char s[]){
    static int i = 0;
    static int j = 0;
    i = (i + 1) % 256;
    j = (j + S[i]) % 256;
    swap (S[i], S[j]);
    t = (S[i] + S[j]) % 256;
    return S[t];
}