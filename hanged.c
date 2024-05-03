#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ERRORS 6


char print_hanged(int errors);//this works
char print_word(char *word);//this works
char *set_answer(char *valid_words[], int amount);//this works
char *set_hanged_word(char *answer);//this works
char check_guess(char *hanged_word, char *guess, char *answer, int *dashes);//i don't think this works
char is_alpha(char *str);
char play_game(char *hanged_word, char *guess, char *answer, int *errors, int *dashes);

int main(){

    char *words[] = {"HOLA", "CHAU", "PALABRA", "RESPUESTA", "FALSO", "VERDADERO"};
    srand(time(0));

    char *answer = set_answer(words, sizeof(words) / sizeof(words[0]));
    int dashes = strlen(answer);
    int errors = 0;
    char guess[100] = {0};

    char *hanged_word = set_hanged_word(answer);
    printf(hanged_word);
    printf(answer);
    print_word(hanged_word);
    char won = 0;
    while(won == 0 && errors < MAX_ERRORS){
        won = play_game(hanged_word, guess, answer, &errors, &dashes);
    }

    print_hanged(errors);
    print_word(hanged_word);

    printf("%s, la palabra era %s\n", ((won) ? "Ganaste" : "Perdiste"), answer);

    free(hanged_word);

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

char print_word(char *word){
    for(int i = 0; word[i]; i++){
        printf("%c ", word[i]);
    }
    printf("\n");

    return 0;
}

char *set_answer(char *valid_words[], int amount){
    char *answer = NULL;

    long random = (rand() + rand()) % amount;
    answer = valid_words[random];

    return answer;
}

char *set_hanged_word(char *answer){
    int answer_length = strlen(answer);
    char *hanged_word = malloc(sizeof(char) * (answer_length + 1));
    for(int i = 0; i < answer_length; i++){
        hanged_word[i] = '_'; 
    }

    hanged_word[answer_length] = '\0';

    return hanged_word;
}

char check_guess(char *hanged_word, char *guess, char *answer, int *dashes){
    char found = 0;
    int guess_len = strlen(guess);

    if(guess_len != 1){
        if(strcmp(guess, answer) == 0){
            found = 2;
            strcpy(hanged_word, answer);
        }
        else{
            found = 0;
        }
    }
    else{
        for(int i = 0; answer[i]; i++){
            if(guess[0] == answer[i] && hanged_word[i] == '_'){
                hanged_word[i] = guess[0];
                found = 1;
                (*dashes)--;
            }
        }

        if(*dashes == 0){
            found = 2;
        }
    }

    return found;
}

char is_alpha(char *str){
    char is_alpha = 1;

    for(int i = 0; str[i] && is_alpha; i++){
        if((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')){
            is_alpha = 0;
        }
    }

    return is_alpha;
}

char play_game(char *hanged_word, char *guess, char *answer, int *errors, int *dashes){
    char won = 0;

    print_hanged(*errors);
    print_word(hanged_word);

    int i = 0;

    do{
        printf("%sadivina una letra o la palabra entera: ", (i) ? ("dije una letra o palabra, ") : (""));
        scanf(" %s", guess);
        i++;
    }while(!is_alpha(guess));

    strupr(guess);

    char check = check_guess(hanged_word, guess, answer, dashes);

    if(check == 2){
        won = 1;
    }
    else{
        (*errors) += !check;
    }

    return won;
}