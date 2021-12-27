#define KEY_SIZE 10     // maximum number of searching key
#define TABLE_SIZE 13   // size of hashing table : prime number

typedef struct {
    char key[KEY_SIZE];
    // other necessary fields
} element;

element hash_table[TABLE_SIZE];     // hashing table