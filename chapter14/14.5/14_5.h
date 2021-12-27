// search the key saved in table using linear probing
void hash_lp_search(element item, element ht[])
{
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while (!empty(ht[i]))
    {
        if (equal(item, ht[i])) {
            fprintf(stderr, "search %s : address = %d\n", item.key, i);
            return;
        }
        i = (i + 1) % TABLE_SIZE;
        if (i == hash_value) {
            fprintf(stderr, "searching key does not exist in hashing table.\n");
            return;
        }
    }
    fprintf(stderr, "searching key does not exist in hashing table.\n");
}