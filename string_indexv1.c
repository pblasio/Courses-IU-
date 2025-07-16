#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 2048
#define MAX_WORD_SIZE 100

typedef struct {
    int begin;
    int length;
    int count;
} WordInfo;

void populateBuffer(char buffer[MAX_BUFFER_SIZE]);
void indexBuffer(const char buffer[MAX_BUFFER_SIZE], WordInfo index[MAX_BUFFER_SIZE]);
void emitReport(const char buffer[MAX_BUFFER_SIZE], const WordInfo index[MAX_BUFFER_SIZE], int totalWords);

int main(void) {
    char buffer[MAX_BUFFER_SIZE];
    WordInfo index[MAX_BUFFER_SIZE];
    
    populateBuffer(buffer);
    int totalWords = 0;ss
    
    indexBuffer(buffer, index);
    for (int i = 0; i < MAX_BUFFER_SIZE; i++) {
        if (index[i].count > 0) {
            totalWords++;
        }
    }
    
    emitReport(buffer, index, totalWords);

    return 0;
}

void populateBuffer(char buffer[MAX_BUFFER_SIZE]) {
    int c;
    int i = 0;
    
    while ((c = getchar()) != EOF && i < MAX_BUFFER_SIZE - 1) {
        buffer[i++] = (char)c;
    }
    
    buffer[i] = '\0';
}

void indexBuffer(const char buffer[MAX_BUFFER_SIZE], WordInfo index[MAX_BUFFER_SIZE]) {
    int i = 0;
    int wordIndex = 0;
    
    while (buffer[i] != '\0' && wordIndex < MAX_BUFFER_SIZE) {
        while (isspace((unsigned char)buffer[i])) {
            i++;
        }
        
        if (buffer[i] == '\0') {
            break;
        }
        
        index[wordIndex].begin = i;
        index[wordIndex].length = 0;
        index[wordIndex].count = 0;
        
        while (!isspace((unsigned char)buffer[i]) && buffer[i] != '\0' && index[wordIndex].length < MAX_WORD_SIZE) {
            index[wordIndex].length++;
            i++;
        }
        
        wordIndex++;
    }
}

void emitReport(const char buffer[MAX_BUFFER_SIZE], const WordInfo index[MAX_BUFFER_SIZE], int totalWords) {
    const int columnWidth = 10;
    
    printf("%-*s%-*s%-*s%-s\n", columnWidth, "BEGIN", columnWidth, "LENGTH", columnWidth, "COUNT", "WORD");
    
    int totalBytes = 0;
    for (int i = 0; i < totalWords; i++) {
        printf("%-*d%-*d%-*d%-.*s\n", columnWidth, index[i].begin, columnWidth, index[i].length, columnWidth, index[i].count, index[i].length, buffer + index[i].begin);
        totalBytes += index[i].length;
    }
    
    printf("Total bytes processed: %d\n", totalBytes);
    printf("Total Unique Words: %d\n", totalWords);
    printf("Total words found: %d\n", totalWords);
}
