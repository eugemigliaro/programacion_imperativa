#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "addressBookADT.h"

#define BLOCK 100

typedef struct contNode{
    tContact *contact;
    struct contNode *next;
}tContNode;

typedef struct tGroup{
    char *name;
    char *cleanName;
    size_t lenName;
    tContNode *firstCont, *currentCont;
}tGroup;

typedef struct groupNode{
    tGroup *group;
    struct groupNode *next;
}tGroupNode;

typedef struct addressBookCDT{
    tGroupNode *firstGroup, *currentGroup;
}addressBookCDT;

addressBookADT newAddressBook(){
    addressBookADT ans = calloc(1, sizeof(addressBookCDT));
    return ans;
}

static char *strtolwr(const char *s, size_t len){
    char *ans = malloc((len + 1) * sizeof(char));
    for(size_t i = 0; i < len; i++){
        ans[i] = tolower(s[i]);
    }

    ans[len] = '\0';
    return ans;
}

static char *strtoptr(const char *s, size_t *len){
    char *ans = NULL;
    size_t i = 0;

    for(i; s[i] != '\0'; i++){
        if(i % BLOCK == 0){
            ans = realloc(ans, (i + BLOCK) * sizeof(char));
        }
        ans[i] = s[i];
    }

    ans[i] = '\0';
    ans = realloc(ans, (i + 1) * sizeof(char));

    if(len){
        *len = i;
    }

    return ans;
}

static tContNode *findContact(tGroup *group, const char *contactName){
    char *aux = strtolwr(contactName, strlen(contactName));
    tContNode *found = NULL;
    
    for(tContNode *i = group->firstCont; i && !found; i = i->next){
        if(strcmp(aux, strtolwr(i->contact->name, strlen(i->contact->name))) == 0){
            found = i;
        }
    }

    return found;
}

static tGroupNode *findGroup(addressBookADT ab, const char *groupName){
    char *aux = strtolwr(groupName, strlen(groupName));
    tGroupNode *found = NULL;
    
    for(tGroupNode *i = ab->firstGroup; i && !found; i = i->next){
        if(strcmp(aux, i->group->cleanName) == 0){
            found = i;
        }
    }

    return found;
}

int addGroup(addressBookADT ab, const char *groupName){
    if(ab->firstGroup && findGroup(ab, groupName)){
        return 0;
    }

    tGroup *new = calloc(1, sizeof(tGroup));

    new->name = strtoptr(groupName, &(new->lenName));
    new->cleanName = strtolwr(new->name, new->lenName);
    
    tGroupNode *newNode = calloc(1, sizeof(tGroupNode));

    newNode->group = new;

    for(tGroupNode *i = ab->firstGroup; i && i->next &&(strcmp(i->next->group->cleanName, new->cleanName) < 0); i = i->next){
}