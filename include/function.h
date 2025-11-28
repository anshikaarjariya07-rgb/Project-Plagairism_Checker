#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void toLowerCase(char *str);
void removePunctuation(char *str);
void readFileContent(char *filename, char *buffer);
float calculateSimilarity(char *text1, char *text2);

#endif
