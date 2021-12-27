void hash_qp_add(element item, element ht[])
{
    int i, hash_value, inc = 0;
    hash_value = i = hash_function(item.key);
    // printf("hash_address = %d\n", i);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "searching key is overlapped.\n");
            exit(1);
        }
        i = (hash_value + inc*inc) % TABLE_SIZE;
        inc = inc + 1;
        if (i == hash_value) {
            fprintf(stderr, "table is full.\n");
            exit(1);
        }
    }
    ht[i] = item;
}