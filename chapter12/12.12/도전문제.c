#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )
#define MAX_WORD_SIZE 50
#define MAX_MEANING_SIZE 500
#define SIZE 5

typedef struct {
    char word[MAX_WORD_SIZE];
    char meaning[MAX_MEANING_SIZE];
} element;

int compare(const void* arg1, const void* arg2)
{
    return strcmp(((element*)arg1)->word, ((element*)arg2)->word);
}

int main(void)
{
    element list[SIZE];

    int i, j;
    element temp;
    puts("Enter 5 words and their meanings.");
    for (i = 0; i < SIZE; i++) {
        scanf("%s[^\n]", list[i].word);
        scanf("%s[^\n]", list[i].meaning);
    }

    qsort(list, SIZE, sizeof(list[0]), compare);

    printf("\ndictionary's content after sorting :\n");
    for (i = 0; i < SIZE; i++)
        printf("%s : %s\n", list[i].word, list[i].meaning);
    
    return 0;
}