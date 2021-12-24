#define INDEX_SIZE 256
typedef struct {
    int key;
    int index;
} itable;
itable index_list[INDEX_SIZE];

int* list;
// INDEX_SIZE is the size of index table, n is the number of the entire data
int search_index(int key, int n)
{
    int i, low, high;

    // if key value isn't value of list range, then terminate searching
    if (key < list[0] || key > list[n - 1])
        return -1;

    // examine the index table and decide section of the key
    for (i = 0; i < INDEX_SIZE; i++)
        if (index_list[i].key <= key &&
            index_list[i + 1].key > key)
            break;
    if (i == INDEX_SIZE) {  // if the end of the index table
        low = index_list[i - 1].index;
        high = n;
    }
    else {
        low = index_list[i].index;
        high = index_list[i + 1].index;
    }
    // sequential search only in the expected range
    return seq_search(key, low, high);
}