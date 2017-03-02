#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt_hash.h"



entry *findName(char lastName[],tableEntry *hashTable)
{
    int index=BKDRHash(lastName);
    entry *head=hashTable[index].head;
    while (head) {
        if (strcasecmp(lastName, head->lastName) == 0)
            return head;
        head = head->pNext;
    }
    return NULL;
}

void append(char lastName[], tableEntry *hashTable)
{
    int index=BKDRHash(lastName);
    entry *newEntry=(entry *)malloc(sizeof(entry));
    strcpy(newEntry->lastName,lastName);
    newEntry->pNext=hashTable[index].head;
    hashTable[index].head=newEntry;
}

tableEntry *initializeTable()
{
    tableEntry *hashTable=(tableEntry*)malloc(sizeof(tableEntry)*MAX_HASH_TABLE_SIZE);
    for(int i=0; i<MAX_HASH_TABLE_SIZE; ++i) {
        (hashTable+i)->head=NULL;
    }
    return hashTable;
}

void removeTable(tableEntry *hashTable)
{
    for(int i=0; i<MAX_HASH_TABLE_SIZE; ++i) {
        entry *head=(hashTable+i)->head;
        while(head) {
            entry *tmp=head->pNext;
            free(head);
            head=tmp;
        }
    }
    free(hashTable);
}

unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131;
    unsigned int hash = 0;
    while (*str) {
        hash = hash * seed + (*str++);
    }
    return hash%MAX_HASH_TABLE_SIZE;
}
