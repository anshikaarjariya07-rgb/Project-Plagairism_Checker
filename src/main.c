#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

// Function to remove punctuation marks
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

// Function to read file content into a single string
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

// Function to calculate plagiarism percentage
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

int main() {
    char file1[100], file2[100];
    char text1[10000] = "", text2[10000] = "";

    printf("===== PLAGIARISM CHECKER =====\n\n");

    // Take file names from user
    printf("Enter first file name (with extension): ");
    scanf("%s", file1);
    printf("Enter second file name (with extension): ");
    scanf("%s", file2);

    // Read file contents
    readFileContent(file1, text1);
    readFileContent(file2, text2);

    // Preprocess text
    removePunctuation(text1);
    removePunctuation(text2);
    toLowerCase(text1);
    toLowerCase(text2);

    // Make copies since strtok modifies strings
    char text1Copy[10000], text2Copy[10000];
    strcpy(text1Copy, text1);
    strcpy(text2Copy, text2);

    // Calculate similarity
    float similarity = calculateSimilarity(text1Copy, text2Copy);

    printf("\n---------------------------------------\n");
    printf("Plagiarism Similarity: %.2f%%\n", similarity);

    // Interpret result
    if (similarity > 80)
        printf("Result: Highly Similar (Possible Plagiarism)\n");
    else if (similarity > 50)
        printf("Result: Moderately Similar\n");
    else
        printf("Result: Low Similarity (Mostly Original)\n");
    printf("---------------------------------------\n");

    return 0;
}