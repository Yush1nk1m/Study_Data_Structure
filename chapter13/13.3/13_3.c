int* list;
int search_binary(int key, int low, int high)
{
    int middle;

    if (low <= high) {
        middle = (low + high) / 2;
        if (key == list[middle])        // success
            return middle;
        else if (key < list[middle])    // search left part of list
            return search_binary(key, low, middle - 1);
        else
            return search_binary(key, middle + 1, high);

    }
    return -1;                          // fail
}