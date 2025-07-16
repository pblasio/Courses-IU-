// Program: assignment 4 c 
// Programmer: Phenzi Blasio 
// Course: CSCI-291 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 2048
// define here is used to declare the constant values of maxbuffer size of 2048 bytes 
#define MAX_WORD_LENGTH 50
// used to declare the constant value of maximum word length in camelcase
#define MAX_UNIQUE_WORDS 100
// used to declare the unique words 
int main(void) {
    char buffer[MAX_BUFFER_SIZE];
    // declare an array called buffer that is constrained by the max buffersize 
    char words[MAX_UNIQUE_WORDS][MAX_WORD_LENGTH];
    // declaring a multidimensional array 
    int counts[MAX_UNIQUE_WORDS] = {0};
    // intialize the count for the length of unique words to zero
    int begin[MAX_UNIQUE_WORDS];
    // numerical array for the listing of unique word count
    int length[MAX_UNIQUE_WORDS];
    // 
    int unique_word_count = 0;
    
    int total_word_count = 0;
    int i, j, k;

    // Read input text from standard input (stdin) and store it in a character array buffer.
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the buffer to identify each unique word and count how many times it appears.
    i = 0;
    while (buffer[i] != '\0') {
        // Skip whitespace characters.
        while (isspace(buffer[i])) {
            i++;
        }

        // Record the beginning of a new word.
        begin[unique_word_count] = i;

        // Parse the current word.
        j = 0;
        while (!isspace(buffer[i]) && buffer[i] != '\0') {
            words[unique_word_count][j] = buffer[i];
            i++;
            j++;
        }
        words[unique_word_count][j] = '\0';

        // Record the length of the current word.
        length[unique_word_count] = j;

        // Count the number of times the current word appears.
        for (k = 0; k < unique_word_count; k++) {
            if (strncmp(words[k], words[unique_word_count], length[unique_word_count]) == 0) {
                counts[k]++;
                break;
            }
        }
        if (k == unique_word_count) {
            counts[unique_word_count]++;
            unique_word_count++;
        }

        // Count the total number of words.
        total_word_count++;
    }

    // Print out the results in the format specified in the comments.
    printf("BEGIN     LENGTH    COUNT     WORD\n");
    for (i = 0; i < unique_word_count; i++) {
        printf("%-10d%-10d%-10d%s\n", begin[i], length[i], counts[i], words[i]);
    }
    printf("Total bytes processed: %d\n", strlen(buffer));
    printf("Total Unique Words: %d\n", unique_word_count);
    printf("Total words found: %d\n", total_word_count);

    return 0;
}

    // no global variables 
    // must declare a multidimensional array to hold the index length and count 
    
   // read from stdin 
   // read up to 2048 bytes of data until EOF, probably as a while loop
   // make a character array buffer 
   // learn how to make a buffer aka an array that holds info 
   // index through every unique word in buffer 
   // count how many of each word 
   // store every word and a count of how many times it shows up 
   // distinguish between whitespace and nonwhitespace characters 
   // let the program expect no more than 2048characters and terminate with EOF if there are less than 2048 characteras 
   // program will index the beginning and end of each word in buffer and use buffer as the storage for content in each word 
   // BEGIN     LENGTH    COUNT     WORD      
//0         3         1         All
//4         3         3         the
//8         3         1         men
//12        3         1         and
//16        3         2         all
//24        5         1         women
//30        2         1         in
//41        6         1         world.
//Total bytes processed: 48
//Total Unique Words: 8
//Total words found: 11
}
