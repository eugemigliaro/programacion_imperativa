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
    tContNode *firstCont;
}tGroup;

typedef struct groupNode{
    tGroup *group;
    struct groupNode *next;
}tGroupNode;

typedef struct addressBookCDT{
    tGroupNode *firstGroup, *currentGroup;
    tContNode *currentCont;
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
            printf("found: %p\n", found);
      }
    }

    return found;
}

int addGroup(addressBookADT ab, const char *groupName){
    if(ab->firstGroup && findGroup(ab, groupName)){
        return 0;
    }

    tGroup *new = calloc(1, sizeof(tGroup));
    printf("newfirst: %p\n", new->firstCont);

    new->name = strtoptr(groupName, &(new->lenName));
    new->cleanName = strtolwr(new->name, new->lenName);
    
    tGroupNode *newNode = calloc(1, sizeof(tGroupNode));
    printf("newnodenext: %p\n", newNode->next);

    newNode->group = new;

    tGroupNode *i = ab->firstGroup;

    if(!i){
        ab->firstGroup = newNode;
    }
    else if(strcmp(i->group->cleanName, new->cleanName) > 0){
        newNode->next = i;
        ab->firstGroup = newNode;
    }
    else{
        
        tGroupNode *prev = NULL;
        
        while(i){
            prev = i;
            i = i->next;
            if(i && !(strcmp(i->group->cleanName, new->cleanName) < 0)){
                i = NULL;
            }
        }

        newNode->next = prev->next;
        prev->next = newNode;
    }

    return 1;
}

int addContact(addressBookADT ab, const char *groupName, tContact contact){
    tGroupNode *group = NULL;

    if(ab->firstGroup && !(group = findGroup(ab, groupName))){
        return 0;
    }

    if(group->group->firstCont && findContact(group->group, contact.name)){
        return 0;
    }

    tContNode *new = calloc(1, sizeof(tContNode));

    new->contact = calloc(1, sizeof(tContact));
    new->contact->name = strtoptr(contact.name, NULL);
    new->contact->phoneNumber = strtoptr(contact.phoneNumber, NULL);

    tContNode *i = group->group->firstCont;

    if(!i){
        group->group->firstCont = new;
    }
    else if(!i->next){
        if(strcmp(strtolwr(i->contact->name, strlen(i->contact->name)), strtolwr(new->contact->name, strlen(new->contact->name))) < 0){
            i->next = new;
        }
        else{
            new->next = i;
            group->group->firstCont = new;
        }
    }
    else{

        for(i; i->next && (strcmp(i->next->contact->name, new->contact->name) < 0); i = i->next);

        new->next = i->next;
        i->next = new;
    }

    return 1;
}

void toBeginForGroup(addressBookADT ab, const char *groupName){
    tGroupNode *group = NULL;

    if(ab->firstGroup && !(group = findGroup(ab, groupName))){
        return;
    }

    ab->currentGroup = group;
    ab->currentCont = group->group->firstCont;
}

int hasNextForGroup(addressBookADT ab){
    return ab->currentCont && ab->currentCont->next;
}

tContact nextForGroup(addressBookADT ab){
    if(hasNextForGroup(ab)){
        ab->currentCont = ab->currentCont->next;
    }

    return *(ab->currentCont->contact);
}

void toBegin(addressBookADT ab){
    ab->currentGroup = ab->firstGroup;
    ab->currentCont = ab->currentGroup->group->firstCont;
}

int hasNext(addressBookADT ab){
    return ab->currentGroup && ab->currentGroup->next;
}

char *next(addressBookADT ab){
    if(hasNext(ab)){
        ab->currentGroup = ab->currentGroup->next;
    }

    char *ans = strtoptr(ab->currentGroup->group->name, NULL);

    return ans;
}