int* list;
int seq_search(int key, int low, int high)
{
    int i;
    for (i = low; i <= high; i++)
        if (list[i] == key)
            return i;   // if search is succeed, then return the index of the key
    return -1;          // else then return -1
}