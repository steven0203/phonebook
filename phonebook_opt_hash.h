#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define MAX_HASH_TABLE_SIZE 42737

#define OPT_HASH 1
typedef struct __PHONE_BOOK_DETAIL {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detail;

typedef struct __LAST_NAME_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    detail *entryDetail;
    struct __LAST_NAME_ENTRY *pNext;
} entry;

typedef struct __HASH_TABLE_ENTRY {
    entry *head;
} tableEntry;

entry *findName(char lastName[],tableEntry *hashTable);
void append(char lastName[],tableEntry *hashTable);
tableEntry * initializeTable(void);
void removeTable(tableEntry *);
unsigned int BKDRHash(char *str);
#endif
