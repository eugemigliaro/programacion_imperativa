#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibleADT.h"

#define BOOKS 76
#define BLOCK 100

typedef struct{
    char *verse;
    size_t len;
}TVerse;

typedef struct{
    TVerse *verses;
    size_t numVerses;
}TBook;

struct bibleCDT{
    TBook books[BOOKS];
};

bibleADT newBible(){
    bibleADT ans = calloc(1, sizeof(struct bibleCDT));
    return ans;
}

char *strtoptr(const char *s, size_t *size){
    char *ans = NULL;

    size_t i;

    for(i = 0; s[i] != '\0'; i++){
        if(i % BLOCK == 0){
            ans = realloc(ans, (i+BLOCK) * sizeof(char));
        }
        ans[i] = s[i];
    }
    ans[i] = '\0';

    ans = realloc(ans, (i+1) * sizeof(char));

    *size = i;

    return ans;
}

int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char * verse){
    if(bible->books[bookNbr-1].verses == NULL){
        bible->books[bookNbr-1].verses = calloc(1, sizeof(TVerse));
    }
    if(verseNbr > bible->books[bookNbr-1].numVerses){
        bible->books[bookNbr-1].verses = realloc(bible->books[bookNbr-1].verses, (verseNbr) * sizeof(TVerse));
        
    }
    else if(bible->books[bookNbr-1].verses[verseNbr - 1].verse){
        return 0;
    }
    
    bible->books[bookNbr-1].verses[verseNbr - 1].verse = strtoptr(verse, &(bible->books[bookNbr-1].verses[verseNbr - 1].len));
    bible->books[bookNbr-1].numVerses = verseNbr;
    return 1;
}

char * getVerse(bibleADT bible, size_t bookNbr, size_t verseNbr){
    if(bookNbr > BOOKS || verseNbr > bible->books[bookNbr-1].numVerses || bible->books[bookNbr-1].verses[verseNbr - 1].verse == NULL){
        return NULL;
    }
    char * ans = strtoptr(bible->books[bookNbr-1].verses[verseNbr - 1].verse, &(bible->books[bookNbr-1].verses[verseNbr - 1].len));

    return ans;
}

void freeBible(bibleADT bible){
    size_t i, j;

    for(i = 0; i < BOOKS; i++){
        if(bible->books[i].verses){
            for(j = 0; j < bible->books[i].numVerses; j++){
                printf("%d %d\n", i, j);
                if(bible->books[i].verses[j].verse){
                    printf("freeing\n");
                    free(bible->books[i].verses[j].verse);
                }
            }
            if(bible->books[i].verses){
                free(bible->books[i].verses);
            }
        }
    }
    free(bible);
}