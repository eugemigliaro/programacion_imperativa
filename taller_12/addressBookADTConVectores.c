#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "addressBookADT.h"

#define BLOCK 100

//ahora me doy cuenta que lo tengo que hacer con orden alfabético adentro de cada grupo,
//voy a hacer otro archivo donde uso listas en vez de vectores dinámicos

typedef struct tGroup{
    char *name;
    char *cleanName;
    size_t lenName;
    tContact *contacts;
    size_t numContacts;
    size_t actual;
}tGroup;

typedef struct addressBookCDT{
    tGroup *groups;
    size_t numGroups;
    size_t numContacts;
    size_t actual;
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

static tGroup * findGroup(addressBookADT ab, const char *groupName){
    char *aux = strtolwr(groupName, strlen(groupName));

    tGroup *found = NULL;
    
    for(size_t i = 0; i < ab->numGroups && !found; i++){
        if(strcmp(aux, ab->groups[i].cleanName) == 0){
            found = &(ab->groups[i]);
        }
    }

    return found;
}

int addGroup(addressBookADT ab, const char *groupName){
    if(ab->groups && findGroup(ab, groupName)){
        return 0;
    }

    ab->groups = realloc(ab->groups, (ab->numGroups + 1) * sizeof(tGroup));

    tGroup *new = &(ab->groups[ab->numGroups]);

    new->name = strtoptr(groupName, &(ab->groups[ab->numGroups].lenName));
    new->cleanName = strtolwr(ab->groups[ab->numGroups].name, ab->groups[ab->numGroups].lenName);
    new->contacts = NULL;
    new->numContacts = 0;
    new->actual = 0;

    ab->numGroups++;

    return 1;
}

static tContact * findContact(tGroup *group, const char *name){

    char *aux = strtolwr(name, strlen(name));

    tContact *found = NULL;

    for(size_t i = 0; i < group->numContacts && !found; i++){
        if(strcmp(strtolwr(group->contacts[i].name, strlen(group->contacts[i].name)), aux) == 0){
            found = &(group->contacts[i]);
        }
    }

    return found;
}

int addContact(addressBookADT ab, const char *groupName, tContact contact){

    tGroup *group = NULL;

    if(!(ab->groups) || !(group = findGroup(ab, groupName))){
        return 0;
    }

    if(group->contacts && findContact(group, contact.name)){
        return 0;
    }

    group->contacts = realloc(group->contacts, (group->numContacts + 1) * sizeof(tContact));

    tContact *new = &(group->contacts[group->numContacts]);

    new->name = strtoptr(contact.name, NULL);
    new->phoneNumber = strtoptr(contact.phoneNumber, NULL);
    
    group->numContacts++;

    return 1;
}