#include "../include/khanAyeshaA2.h"

/* 1
 *
 * Reads the contents of a text file and returns them as a heap-allocated string.
 *
 * @param filename The name of the file to read
 * @return A pointer to a heap-allocated string containing the contents of the file
 *         Or returns NULL if an error occurred.
 */
char *readFile(char *filename){
    // Local var
    FILE *fptr;
    // Holds size of the file
    int fileSize;
    // For temporary file contents
    char *temp;

    // Open to read in binary mode
    fptr = fopen(filename, "rb");

    // Check if file exists
    if (fptr == NULL) {
        printf("The file '%s' does not exist", filename);
        return NULL;
    }

    // Go to EOF
    fseek(fptr, 0, SEEK_END);
    // Set file size = the current position of "cursor"
    fileSize = ftell(fptr);
    // Go to the beginning of the file
    rewind(fptr);

    // Allocate memory to hold the file contents
    temp = (char *) malloc(fileSize * sizeof(char));
    // check if the memory allocation was successful
    if (temp == NULL) {
        printf("Could not allocate memory");

	// Close file and return NULL
        fclose(fptr);
        return NULL;
    }

    // Read the file into the buffer
    if (fread(temp, fileSize, 1, fptr) != 1) {
        printf("Could not read '%s'", filename);

        // Free the allocated memory before returning NULL
        free(temp);
        fclose(fptr);
        return NULL;
    }

    // close the file
    fclose(fptr);
    // return the buffer containing the file contents
    return temp;
}

/* 2
 *
 * Counts the number of words and sentences in a given string.
 *
 * @param aString the string to analyze
 * @param numWords a pointer to the variable that will hold the number of words
 * @param numSentences a pointer to the variable that will hold the number of sentences
*/
void dejaVu(char *aString, int *numWords, int *numSentences) {
    int index = 0, wordCount = 0, sentenceCount = 0;
    char currChar = aString[0];

    while (currChar != '\0') {
        // Check for whitespace
        if (currChar == ' ' || currChar == '\t' || currChar == '\n') {
            wordCount++;
        }
        // Check for end of sentence
        else if (currChar == '.' || currChar == ':' || currChar == ';' || currChar == '?' || currChar == '!') {
            sentenceCount++;
            // Skip any whitespace immediately after the end of the sentence
            do {
                currChar = aString[++index];
            } while (currChar == ' ' || currChar == '\t' || currChar == '\n');
            // Check if there is a new word after the end of the sentence
            if (currChar != '\0' && currChar != '.' && currChar != ':' && currChar != ';' && currChar != '?' && currChar != '!') {
                wordCount++;
            }
        }

	// Move to next character
        currChar = aString[++index];
    }

    // Check if there is a final word at the end of the string
    if (currChar == '\0' && aString[index - 1] != '.' && aString[index - 1] != ':' && aString[index - 1] != ';' && aString[index - 1] != '?' && aString[index - 1] != '!') {
        wordCount++;
    }
    // Check if there is a final sentence at the end of the string
    if (aString[index - 1] == '.' || aString[index - 1] == '?' || aString[index - 1] == '!') {
        sentenceCount++;
    }

    // Update the output variables
    *numWords = wordCount;
    *numSentences = sentenceCount;
}

/* 3
 *
 * Prompts the user to enter n valid positive integers, where n is the length of the input string.
 * Entering a 0 or negative number is considered invalid.
 *
 * @param aString a pointer to the input string
 * @return a pointer to the new string created by the function, or NULL if memory allocation fails
 */
char *goBig(char *aString) {
    int n = strlen(aString);
    int *counts = (int *) malloc(n * sizeof(int));
    char *resultStr = (char *) malloc(n * sizeof(char)), input[20];
    int i, j, k, resultLen;

    // Get counts from user input
    for (i = 0; i < n; i++) {
        // Prompt the user to enter a positive integer for the i-th character of aString
        printf("Enter a positive integer for character '%c': ", aString[i]);

        int validInput = 0;
        do {
            // Read input from user
            fgets(input, 20, stdin);
            int inputVal = atoi(input);

            // Check if input is valid
            if (inputVal > 0) {
                counts[i] = inputVal;
                validInput = 1;
            } else {
                // Invalid input, prompt user to try again
                printf("Invalid input. Please enter a positive integer.\n");
                printf("Enter a positive integer for character '%c': ", aString[i]);
            }
        } while (!validInput);
    }

    // Calculate length of result string
    resultLen = 0;
    for (i = 0; i < n; i++) {
        resultLen += counts[i];
    }

    // Allocate memory for result string
    resultStr = (char *)realloc(resultStr, (resultLen + 1) * sizeof(char));
    resultStr[resultLen] = '\0';

    // Populate result string
    k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < counts[i]; j++) {
            resultStr[k] = aString[i];
            k++;
        }
    }

    free(counts);
    return resultStr;
}

/* 4
 *
 * Split a string into separate words and store them in an array of strings.
 *
 * @param aSentenceToSplit the string to be split into words
 * @param numWordsReturned a pointer to an integer where the number of words found will be stored
 * @return an array of strings containing the individual words found, or NULL if an error occurs
 */
char **goAway(char *aString, int *numWordsReturned){
    // Local var
    int idxStr = 0, idxWord = 0, idxChar = 0, len = 0;
    int wordCount = 0;
    char **words = NULL;

    // Count the total number of words in the string provided
    while (aString[idxStr] != '\0') {
	// Check for spaces
        if (aString[idxStr] == ' ' || aString[idxStr] == '\n') {

            // Skip over whitespace characters
            while (aString[idxStr] == ' ' || aString[idxStr] == '\n') {
                idxStr++;	// move on
            }
        }
	// If no space, it is a word
	else {
	    // Add to the count
            wordCount++;

            // Count characters in current word
            while (aString[idxStr] != ' ' && aString[idxStr] != '\n' && aString[idxStr] != '\0') {
                idxStr++;
            }
        }
    }

    // Update the parameter
    *numWordsReturned = wordCount;

    // Allocate memory for the words array
    words = (char **)malloc(wordCount * sizeof(char *));

    // Check for empty input
    if (words == NULL) {
        printf("Memory allocation error.\n");
        return NULL;
    }

    // Reset the index
    idxStr = 0;

    // Split the string into words and store them in the words array
    while (aString[idxStr] != '\0') {
        // Check for whitespace characters again
	if (aString[idxStr] == ' ' || aString[idxStr] == '\n') {
            // Skip over whitespace characters
            while (aString[idxStr] == ' ' || aString[idxStr] == '\n') {
                idxStr++;	// move on
            }
        }
	// New word found
	else {
            idxChar = idxStr;
            // Store the number of characters in current word
            while (aString[idxChar] != ' ' && aString[idxChar] != '\n' && aString[idxChar] != '\0') {
                idxChar++;
            }

	    // Calculate length of current character by subtracting previous character
            len = idxChar - idxStr;

	    // Allocate memory
            words[idxWord] = (char *)malloc((len + 1) * sizeof(char));

            if (words[idxWord] == NULL) {
                printf("Memory allocation error.\n");
                return NULL;
            }

	    // Copy char from aString from current index
            strncpy(words[idxWord], &aString[idxStr], len);
            words[idxWord][len] = '\0';

	    // Store next word
            idxWord++;
	    // Go to next non whitespace char
            idxStr = idxChar;
        }
    }

    return words;
}

/* 5
 *
 * Removes all punctuation characters from the string
 *
 * @param aStringToShrink The input string to be stripped of punctuation.
 * @return A pointer to the resulting string with no punctuation.
 */
char *breathless(char *aStringToShrink){
    // Intitial cap is 1
    int newStringCapacity = 1, newStringIndex = 0;

    // Initially allocate only one byte for newString
    char* newString = (char*)malloc(newStringCapacity * sizeof(char));

    for (int i = 0; i < strlen(aStringToShrink); i++) {
	// If the current character is not a punctuation, add it to the newString
        if (aStringToShrink[i] != '.' && aStringToShrink[i] != ':' && aStringToShrink[i] != ';' && aStringToShrink[i] != '?' && aStringToShrink[i] != '!') {

	    // Check if there is enough space in newString to add next character
            if (newStringIndex >= newStringCapacity - 1) {
		// Add one more byte
                newStringCapacity++;

		// Reallocate memory for newString
                newString = (char*)realloc(newString, newStringCapacity * sizeof(char));
            }

	    // After adding another byte, add the non punctuation char to the newString
            newString[newStringIndex] = aStringToShrink[i];
            newStringIndex++;
        }
    }

    // Null char for the newString
    newString[newStringIndex] = '\0';

    // Trim newString to the min size needed
    newString = (char*)realloc(newString, (newStringIndex + 1) * sizeof(char));
    return newString;
}

/* 6
 *
 * Returns the word at the desired position with the specified suffix
 *
 * @param aString The input string.
 * @param whichWord The position of the desired word in the input string (starting from 1).
 * @param desiredSuffix The desired suffix to be appended to the selected word.
 * @return A pointer to the selected word with the specified suffix.
 */
void tail(char *aString, int whichWord, char *desiredSuffix){
    //Local var
    char *word, *finalWord;
    int count = 0;

    // Get the first word of the sentence
    // Exclude any punctuation and whitespaces
    word = strtok(aString, " \t\n\r\f\v.,:;?!\"");

    // Keep getting words until the end of the sentence
    while (word != NULL) {
	count++;

	// Check to find the n-th word
        if(count == whichWord) {
            finalWord = (char*) malloc((strlen(word) + 1) * sizeof(char));
            strcpy(finalWord, word);
	    break;
        }
        // Otherwise, get the next word in the sentence
        else{
	    word = strtok(NULL, " \t\n\r\f\v.,:;?!\"");
	}
    }

    // Print each word with the desired suffix
    for(int i = 0; i < strlen(finalWord); i++){
	putchar(finalWord[i]);
	printf("%s\n", desiredSuffix);
    }
}
