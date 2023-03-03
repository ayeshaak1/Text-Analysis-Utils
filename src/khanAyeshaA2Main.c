#include "../include/khanAyeshaA2.h"

int main(int argc, char *argv[]) {
    // Check if file name is provided
    if (argc < 2) {
        printf("Error: please provide a file name\n");
        return 0;
    }

    /**** 	FUNCTION 1	****/
    printf("FUNCTION 1\n");
    // Local var for func1
    char *fileContents = readFile(argv[1]);

    // Check for errors in file
    if (fileContents == NULL) {
        printf("File contents could not be saved using '%s'\n", argv[1]);
        return 0;
    }

    printf("%s", fileContents); /***** DELETE ******/


    /****	FUNCTION 2	****/
    printf("\n\nFUNCTION 2\n");

    // Var for func2
    int numWords = 0, numSentences = 0;

    // Call the function and print the result
    dejaVu(fileContents, &numWords, &numSentences);
    printf("Number of words in %s are %d\n", argv[1], numWords);
    printf("Number of sentences in %s are %d\n", argv[1], numSentences);


    /****	FUNCTION 3	****/
    printf("\n\nFUNCTION 3\n");

    // Local var
    char *result3 = goBig(fileContents);

    // Print the results
    printf("Original string: %s\n", fileContents);
    printf("Resultant string: %s\n", result3);


   /****	FUNCTION 4	****/
    printf("\n\nFUNCTION 4\n");

    numWords = 0;
    char **words = NULL;

    // Call the function
    words = goAway(fileContents, &numWords);

    // Print out total num of words it was split into
    printf("The sentence was split into %d words\n", numWords);


    /****	FUNCTION 5	****/
    printf("\n\nFUNCTION 5\n");

    // Call the function
    char* newString = breathless(fileContents);

    printf("Original string: %s", fileContents);
    printf("Resultant string: %s\n", newString);


    /****	FUNCTION 6	****/
    printf("\n\nFUNCTION 6\n");
    int whichWord = 0;
    char desiredSuffix[200];

    // Ask for whichWord
    printf("Enter which word to start from (integer): ");
    scanf("%d", &whichWord);

    // Ask desiredSuffix
    printf("Enter desired suffix: ");
    scanf("%s", desiredSuffix);

    // Call the function
    tail(fileContents, whichWord, desiredSuffix);

    // Free the allocated memory
    free(fileContents);
    free(result3);
    free (words);

    return 0;
}
