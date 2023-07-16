# Text-Analysis-Utils

This repository contains a set of utility functions for text analysis and manipulation written in C. The functions are designed to perform various operations on text strings, such as reading file contents, counting words and sentences, obtaining user input, splitting sentences into words, removing punctuation, and appending suffixes to specific words. These functions can be useful for various text processing tasks, such as natural language processing and text mining.

## Functions

1. `char *readFile(char *filename)`: Reads the contents of a text file and returns them as a heap-allocated string.

2. `void dejaVu(char *aString, int *numWords, int *numSentences)`: Counts the number of words and sentences in a given string.

3. `char *goBig(char *aString)`: Prompts the user to enter n valid positive integers, where n is the length of the input string, and creates a new string based on the input.

4. `char **goAway(char *aString, int *numWordsReturned)`: Splits a string into separate words and stores them in an array of strings.

5. `char *breathless(char *aStringToShrink)`: Removes all punctuation characters from the string.

6. `void tail(char *aString, int whichWord, char *desiredSuffix)`: Returns the word at the desired position with the specified suffix.

## Usage

To use these text analysis functions, include the header file "khanAyeshaA2.h" in your C program and link it with the "khanAyeshaA2.c" file containing the function definitions.

Example usage:

```c
#include "khanAyeshaA2.h"
#include <stdio.h>

int main() {
    // Your code using the text analysis functions goes here...
}
