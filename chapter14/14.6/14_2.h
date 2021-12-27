void init_table(element ht[])
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        ht[i].key[0] = '\0';
    }
}