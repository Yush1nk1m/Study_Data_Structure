int* list;
int seq_search2(int key, int low, int high)
{
    int i;

    list[high + 1] = key;
    for (i = low; list[i] != key; i++)  // if key value is found, then terminate
        ;
    if (i == (high + 1)) return -1;     // fail
    else return i;                      // success
}