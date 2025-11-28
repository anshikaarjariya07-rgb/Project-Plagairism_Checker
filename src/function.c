#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "../include/functions.h"

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

// Function to remove punctuation
void removePunctuation(char *str) {
    char temp[10000];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i]) || isspace(str[i])) {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

// Function to read file content into a buffer
void readFileContent(char *filename, char *buffer) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    char line[500];
    while (fgets(line, sizeof(line), fp)) {
        strcat(buffer, line);
    }
    fclose(fp);
}

// Function to calculate plagiarism similarity percentage
float calculateSimilarity(char *text1, char *text2) {
    int totalWords = 0, matchedWords = 0;
    char *word;

    word = strtok(text1, " ");
    while (word != NULL) {
        totalWords++;
        if (strstr(text2, word)) {
            matchedWords++;
        }
        word = strtok(NULL, " ");
    }

    if (totalWords == 0) return 0.0;
    return ((float)matchedWords / totalWords) * 100;
}
