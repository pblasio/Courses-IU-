/* assignment 4 stringind */
/* Programmer: Phenzi Blasio */
/* Course: CSCI-291 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_BUFFER_SIZE 2048
#define MAX_WORDS 512
#define MAX_WORD_LENGTH 50


// input functions for charc and indexes for red index words and report 
void read_input(char buffer[], int *total_bytes);
void index_words(const char buffer[], int word_indices[][3], int *word_count, int *total_words, int total_bytes);
void emit_report(const char buffer[], int word_indices[][3], int word_count, int total_bytes, int total_words);

// Helper function prototype
int is_unique_word(const char *word, const char buffer[], int word_indices[][3], int word_count, int word_length);

int main(void) {
    char buffer[MAX_BUFFER_SIZE];
    int word_indices[MAX_WORDS][3]; // Stores offset, length, and count for each unique word
    int total_bytes = 0;
    int word_count = 0;
    int total_words = 0; // To count total words found

    // Initialize buffer and word_indices
    memset(buffer, 0, sizeof(buffer));
    for (int i = 0; i < MAX_WORDS; i++) {
        word_indices[i][0] = word_indices[i][1] = word_indices[i][2] = 0;
    }

    // Populate buffer with input
    read_input(buffer, &total_bytes);

    // Index words in the buffer
    index_words(buffer, word_indices, &word_count, &total_words, total_bytes);

    // Emit report to stdout
    emit_report(buffer, word_indices, word_count, total_bytes, total_words);

    return 0;
}

/* Function to read input into buffer */
void read_input(char buffer[], int *total_bytes) {
    int ch;
    *total_bytes = 0;
    while ((ch = getchar()) != EOF && *total_bytes < MAX_BUFFER_SIZE) {
        buffer[*total_bytes] = ch;
        (*total_bytes)++;
    }
}

/* Function to index unique words in the buffer */
void index_words(const char buffer[], int word_indices[][3], int *word_count, int *total_words, int total_bytes) {
    int i = 0;
    while (i < total_bytes) {
        while (i < total_bytes && isspace(buffer[i])) i++; // Skip whitespace
        int start = i;
        while (i < total_bytes && !isspace(buffer[i])) i++; // Find end of word
        int end = i;

        if (start < end) {
            int word_length = end - start;
            char word[MAX_WORD_LENGTH];
            strncpy(word, buffer + start, word_length);
            word[word_length] = '\0';

            int index = is_unique_word(word, buffer, word_indices, *word_count, word_length);
            if (index == -1) { // New word
                word_indices[*word_count][0] = start;
                word_indices[*word_count][1] = word_length;
                word_indices[*word_count][2] = 1;
                (*word_count)++;
            } else { // Existing word
                word_indices[index][2]++;
            }
            (*total_words)++;
        }
    }
}

/* Helper function to check if a word is unique */
int is_unique_word(const char *word, const char buffer[], int word_indices[][3], int word_count, int word_length) {
    for (int i = 0; i < word_count; i++) {
        if (strncmp(word, buffer + word_indices[i][0], word_indices[i][1]) == 0 && word_indices[i][1] == word_length) {
            return i;
        }
    }
    return -1;
}

/* Function to emit report of indexed words */
void emit_report(const char buffer[], int word_indices[][3], int word_count, int total_bytes, int total_words) {
    printf("BEGIN     LENGTH    COUNT     WORD\n");
    for (int i = 0; i < word_count; i++) {
        printf("%-10d%-10d%-10d", word_indices[i][0], word_indices[i][1], word_indices[i][2]);
        for (int j = 0; j < word_indices[i][1]; j++) {
            putchar(buffer[word_indices[i][0] + j]);
        }
        putchar('\n');
    }
    printf("Total bytes processed: %d\n", total_bytes);
    printf("Total Unique Words: %d\n", word_count);
    printf("Total words found: %d\n", total_words); // This line includes all unique and repeated words
}

