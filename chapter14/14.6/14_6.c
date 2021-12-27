#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "14_1.h"
#include "14_2.h"
#include "14_3.h"
#include "14_4.h"
#include "14_5.h"

// print contents of hashing table
void hash_lp_print(element ht[])
{
    int i;
    puts("\n=================================");
    for (i = 0; i < TABLE_SIZE; i++)
        printf("[%d] : %s\n", i, ht[i].key);
    puts("=================================\n");
}

// example using hashing table
int main(void)
{
    char* s[7] = { "do", "for", "if", "case", "else", "return", "function" };
    element e;

    for (int i = 0; i < 7; i++) {
        strcpy(e.key, s[i]);
        hash_lp_add(e, hash_table);
        hash_lp_print(hash_table);
    }
    return 0;
}