// Lab 1 by Chris Ingerson, Corey Ruderman, & Dan Travis

// Reads the input file 
// character by character and then prints what it just read.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

void swap(char a, char b);
void encrypt_data(FILE* input_file, FILE* output_file, FILE* keyFile);
char generateKeyByte(char s[]);


char key[256]; // Space for 256 characters
char S[256]; // State vector 
char T[256]; // Temporary vector

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
   
    if (argc < 3) 
    	printf("Input, output, and keyFile need to be specified\n");
    keyFile = fopen(argv[1], "r"); //Argument 1 is the key file
    ifp = fopen(argv[2], "r"); //Argument 2 is the input file
    ofp = fopen(argv[3], "w"); //Argument 3 is the output file

    assert(keyFile != NULL); //test if key file is there
    assert(ifp != NULL);  //test if input file is there
    assert(ofp != NULL);   //test if output file is there

    int kLength = 0;
    while ((((keyFileChar = fgetc(keyFile))) != EOF) && (kLength < 256)){ //scans in keyFile and stores in key array
            key[kLength++] = (char)keyFileChar; //Load key array and increment kLength to keep track of char
    }

    i = 0;
    while(i < 256){    //Initialize arrays S and T
        S[i] = i; 
        T[i] = key[i % kLength];
        i++;
    }

    j = 0;
    for(i = 0; i < 256; i++){    //permutate S and T
    	j = (j+S[i] + T[i]) % 256;
    	swap(S[i], S[j]);
    }
    
    encrypt_data(ifp, ofp, keyFile); //XOR data and write it to file

    fclose(keyFile); //close key file
    fclose(ifp);	//close inputf file
    fclose(ofp);	//close output file

}

void swap(char a, char b){ //swap two characters 
	char temp = a;
	a = b;
	b = temp;
}

void encrypt_data(FILE* input_file, FILE* output_file, FILE* keyFile){ //Symmetric cipher
    int key_count = 0; 												   //Can encrypt & decrypt with this function
    int encrypt_byte;
    int key_byte;
    
    while((encrypt_byte = fgetc(input_file)) != EOF){ //Read the input file char by char
        char keystream = generateKeyByte(key); //generate next element of key stream
        fputc(encrypt_byte ^ keystream, output_file); //XOR key byte with input byte and write to output
    }
}

char generateKeyByte(char s[]){  //Generate next key byte 
    static int i = 0; 
    static int j = 0;
    i = (i + 1) % 256;
    j = (j + S[i]) % 256;
    swap (S[i], S[j]);
    int t = (S[i] + S[j]) % 256;
    char keybyte = S[t];
    return keybyte;
}
