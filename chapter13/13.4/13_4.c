int* list;
int search_binary2(int key, int low, int high)
{
    int middle;

    while (low <= high) {           // if numbers are left
        middle = (low + high) / 2;
        if (key == list[middle])
            return key;
        else if (key < list[middle])
            high = middle - 1;
        else
            low = middle + 1;
    }
    return -1;                      // not found
}