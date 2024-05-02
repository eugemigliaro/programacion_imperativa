#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ERRORS 6


char print_hanged(int errors);
char print_word(char word[]);
char *set_answer(char *valid_words[], int amount);
char *set_hanged_word(char *answer, char *guess);

int main(){

    char *words[] = {"HOLA", "CHAU", "PALABRA", "RESPUESTA", "FALSO", "VERDADERO"};
    srand(time(0));

    char *answer = set_answer(words, sizeof(words) / sizeof(words[0]));
    int errors = 0;
    printf("answer: %s\n", answer);
    char *guess;
    char *guesses = NULL;

    return 0;
}

char print_hanged(int errors){
    switch(errors){
        case 0:
            printf("  +---+\n  |   |\n      |\n      |\n      |\n      |\n========\n");
            break;
        case 1:
            printf("  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n========\n");
            break;
        case 2:
            printf("  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n========\n");
            break;
        case 3:
            printf("  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n========\n");
            break;
        case 4:
            printf("  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n========\n");
            break;
        case 5:
            printf("  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n========\n");
            break;
        case 6:
            printf("  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========\n");
            break;
        default:
            break;
    }

    return 0;
}

char print_word(char word[]){
    for(int i = 0; !word[i]; i++){
        printf("%c ", word[i]);
    }
    printf("\n");
}

char *set_answer(char *valid_words[], int amount){
    char *answer = NULL;

    long random = (rand() + rand()) % amount;
    answer = valid_words[random];
}

char *set_hanged_word(char *answer, char *guess){
    int answer_length = strlen(answer);
    char *hanged_word = malloc(sizeof(char) * (answer_length + 1));
    for(int i = 0; i < answer_length; i++){
        hanged_word[i] = '_'; 
    }
}