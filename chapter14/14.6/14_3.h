// transform key consisting of letters into number
int transform(char* key)
{
    int number = 0;
    while (*key)
        number = 31 * number + *key++;
    return number;
}
// hashing function using division function
int hash_function(char* key)
{
    // transform key into natural number and divide of table size and finally return remainder
    printf("transform %s = %d\n", key, transform(key));
    return transform(key) % TABLE_SIZE;
}