/* Phenzi Blasio
C291 Assignment - my_wc */


/* Phenzi Blasio
C291 Assignment - custom_wc */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define initial_buffer_capacity 40
#define buffer_resize_step 40
#define word_array_increment 5
#define initial_word_array_size 5

// function prototypes
char *fetch_input();
void process_input(char *data, int *total_lines);
void display_help();
int calculate_word_count(char *data);
void show_word_frequencies(char **words_array, int *frequency_array, int word_array_size);
void release_memory(char **words_array, int **frequency_array, int word_array_size);
int calculate_char_count(char *data);

int main(int argc, char *argv[])
{
    int line_counter = 0;
    int word_counter = 0;
    int char_counter = 0;
    char **words_array = NULL;
    int *frequency_array = NULL;
    int word_array_size = initial_word_array_size;
    int actual_word_counter = 0;

    // allocate memory for word storage and frequency tracking
    words_array = (char **)malloc(word_array_size * sizeof(char *));
    frequency_array = (int *)malloc(word_array_size * sizeof(int));

    if (words_array == NULL || frequency_array == NULL)
    {
        fprintf(stderr, "debug    error: memory allocation failed for word arrays\n");
        exit(1);
    }

    // get input from stdin
    char *data = fetch_input();
    process_input(data, &line_counter);
    word_counter = calculate_word_count(data);
    char_counter = calculate_char_count(data);

    // tokenize input and populate words_array and frequency_array
    char *token = strtok(data, " \n\t");
    while (token != NULL)
    {
        int is_duplicate = 0;
        // check if the token is already stored in words_array
        for (int i = 0; i < actual_word_counter; i++)
        {
            if (strcmp(words_array[i], token) == 0)
            {
                frequency_array[i]++;
                is_duplicate = 1;
                break;
            }
        }
        // if token is unique, add it to the array
        if (!is_duplicate)
        {
            if (actual_word_counter >= word_array_size)
            {
                // increase storage if required
                word_array_size += word_array_increment;
                words_array = (char **)realloc(words_array, word_array_size * sizeof(char *));
                frequency_array = (int *)realloc(frequency_array, word_array_size * sizeof(int));
                if (words_array == NULL || frequency_array == NULL)
                {
                    fprintf(stderr, "debug    error: memory reallocation failed for word arrays\n");
                    exit(1);
                }
            }
            // allocate memory for the new token
            words_array[actual_word_counter] = (char *)malloc((strlen(token) + 1) * sizeof(char));
            strcpy(words_array[actual_word_counter], token);
            frequency_array[actual_word_counter] = 1;
            actual_word_counter++;
        }
        token = strtok(NULL, " \n\t"); // move to the next token
    }

    // command line argument handling
    for (int i = 1; i < argc; i++)
    {
        const char *arg = argv[i];

        switch (arg[1])
        {
        case 'l':
            printf("line count: %d\n", line_counter);
            break;
        case 'c':
            printf("character count: %d\n", char_counter);
            break;
        case 'w':
            printf("word count: %d\n", word_counter);
            return 0;
        case 'f':
            show_word_frequencies(words_array, frequency_array, word_array_size);
            break;
        case 'v':
            printf("line count: %d\n", line_counter);
            printf("word count: %d\n", word_counter);
            printf("character count: %d\n", char_counter);
            show_word_frequencies(words_array, frequency_array, word_array_size);
            break;
        case 'd':
            fprintf(stderr, "debug    error: debug mode activated.\n");
            break;
        case 'h':
            display_help();
            return 0;
        default:
            printf("line count: %d\n", line_counter);
            printf("word count: %d\n", word_counter);
            printf("character count: %d\n", char_counter);
            break;
        }
    }
    free(data);
    release_memory(words_array, &frequency_array, word_array_size);

    return 0;
}

char *fetch_input()
{
    char *buffer = (char *)malloc(initial_buffer_capacity * sizeof(char));
    if (buffer == NULL)
    {
        fprintf(stderr, "debug    error: initial buffer allocation failed\n");
        exit(1);
    }

    int buffer_capacity = initial_buffer_capacity;
    int pos = 0;
    int ch;

    while ((ch = getchar()) != EOF)
    {
        if (pos >= buffer_capacity - 1)
        {
            buffer_capacity += buffer_resize_step;
            buffer = (char *)realloc(buffer, buffer_capacity * sizeof(char));
            if (buffer == NULL)
            {
                fprintf(stderr, "debug    error: buffer reallocation failed\n");
                exit(1);
            }
        }
        buffer[pos++] = ch;
    }

    buffer[pos] = '\0';
    return buffer;
}

int calculate_word_count(char *data)
{
    int word_counter = 0;
    int inside_word = 0;

    // iterate through each character in the data buffer
    for (int i = 0; data[i] != '\0'; i++)
    {
        // if current character is not a space, newline, or tab, and we're not already in a word, increment word counter
        if ((data[i] != ' ' && data[i] != '\n' && data[i] != '\t') && !inside_word)
        {
            inside_word = 1;
            word_counter++;
        }
        // if current character is a space, newline, or tab, reset inside_word flag
        else if (data[i] == ' ' || data[i] == '\n' || data[i] == '\t')
        {
            inside_word = 0;
        }
    }

    return word_counter;
}

int calculate_char_count(char *data)
{
    int char_counter = 0;

    for (int i = 0; data[i] != '\0'; i++)
    {
        char_counter++;
    }

    return char_counter;
}

void process_input(char *data, int *total_lines)
{
    // initialize line count to 0
    *total_lines = 0;

    // iterate through each character in the data buffer
    for (int i = 0; data[i] != '\0'; i++)
    {
        // if the current character is a newline, increment the line count
        if (data[i] == '\n')
        {
            (*total_lines)++;
        }
    }
}

void display_help()
{
    printf("prints the word count from stdin.\n");
    printf("usage: custom_wc [-h] [-l] [-c] [-w] [-f] [-d] [-v] [-a] [-p]\n");
    printf("-h -- display this help message\n");
    printf("-d -- debugging output to stderr\n");
    printf("-w -- word count (default with no options)\n");
    printf("-c -- character count\n");
    printf("-l -- line count\n");
    printf("-f -- word frequency\n");
    printf("-v -- output all word, line, character, and frequency counts\n");
    printf("-a -- report average word and line length\n");
    printf("-p -- exclude punctuation in words\n");
}

void show_word_frequencies(char **words_array, int *frequency_array, int word_array_size)
{
    printf("word frequency:\n");
    for (int i = 0; i < word_array_size; i++)
    {
        if (words_array[i] != NULL)
        {
            printf("    %s: %d\n", words_array[i], frequency_array[i]); // displays words and counts
        }
    }
}

void release_memory(char **words_array, int **frequency_array, int word_array_size)
{
    if (words_array != NULL)
    {
        for (int i = 0; i < word_array_size; i++)
        {
            if (words_array[i] != NULL)
            {
                free(words_array[i]); // free each word's memory
            }
        }
        free(words_array); // free the array itself
    }

    if (*frequency_array != NULL)
    {
        free(*frequency_array); // free memory for frequency array
    }
}
