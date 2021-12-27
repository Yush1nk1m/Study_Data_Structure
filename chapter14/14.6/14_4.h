#define empty(item) (strlen(item.key) == 0)
#define equal(item1, item2) (!strcmp(item1.key, item2.key))

// insert key into table using linear probing
// if table is full, then terminate
void hash_lp_add(element item, element ht[])
{
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    // printf("hash_address = %d\n", i);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "searching key overlapped.\n");
            exit(1);
        }
        i = (i + 1) % TABLE_SIZE;
        if (i == hash_value) {
            fprintf(stderr, "table is full.\n");
            exit(1);
        }
    }
    ht[i] = item;
}