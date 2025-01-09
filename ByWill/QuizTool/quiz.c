#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int randomNumberInRange(int min, int max);
void swapWords(char*** wordList, int indexToSwap, int indexToSwapTo);
void printWords(char** words, int numberOfWords);
char** getWords(FILE *input, int *wordIndex);

int main(int argc, char** argv) {
    srand(time(NULL));
    FILE* input;
    if (argc > 1) {
        if (!(input = fopen(argv[1], "r"))) {
            fprintf(stderr, "Unable to open file: exiting.\n");
            exit(0);
        }
    }
    else {
        input = fopen("input.txt", "r");
    }
    int wordIndex;
    char** words = getWords(input, &wordIndex);
    printWords(words, wordIndex + 1);
    printf("\e[1;1H\e[2JDone.\n");
    return 0;
}

char** getWords(FILE *input, int *wordIndex) {
    char** words = calloc(1, sizeof(char*));
    (*wordIndex) = 0;
    words[0] = calloc(1, sizeof(char));
    int characterIndex = 0;
    int character;
    while ((character = getc(input)) != EOF) {
        if (character == ',') { // found new word
            words[(*wordIndex)][characterIndex] = '\0';
            characterIndex = 0;
            (*wordIndex)++;
            words = realloc(words, ((*wordIndex) + 1) * sizeof(char*));
            while (isspace(character = getc(input)));
        }
        if (character != '\n' && character != '\13') { // for if there's a trailing newline on the last word
            words[(*wordIndex)] = realloc(words[(*wordIndex)], (characterIndex + 1) * sizeof(char));
            words[(*wordIndex)][characterIndex] = (char)character;
            characterIndex++;
        }
    }
    fclose(input);
    return words;
}

void printWords(char **words, int numberOfWords) {
    char eatCharacter = 'a';
    while (numberOfWords > 0) {
        printf("\e[1;1H\e[2J");
        int nextWordIndex;
        if (numberOfWords > 1) {
            nextWordIndex = randomNumberInRange(0, numberOfWords - 1);
        }
        else {
            nextWordIndex = 0;
        }
        swapWords(&words, nextWordIndex, numberOfWords - 1);
        printf("%s\n", words[numberOfWords - 1]);

        free(words[numberOfWords - 1]);
        numberOfWords--;
        words = realloc(words, numberOfWords * sizeof(char*));

        scanf("%c", &eatCharacter);
    }
    free(words);
}

int randomNumberInRange(int min, int max) {
    int random = rand();
    random = random % (max - min);
    random += min;
    return random;
}

void swapWords(char*** wordList, int indexToSwap, int indexToSwapTo) {
    char* temp = (*wordList)[indexToSwapTo];
    (*wordList)[indexToSwapTo] = (*wordList)[indexToSwap];
    (*wordList)[indexToSwap] = temp;
}
