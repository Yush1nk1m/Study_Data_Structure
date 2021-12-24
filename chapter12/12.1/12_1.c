#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )

void selection_sort(int list[], int n)
{
    int i, j, least, temp;
    for (i = 0; i < n - 2; i++) {
        least = i;
        for (j = i; j < n - 1; j++)
            if (list[j] < list[least]) least = j;
        SWAP(list[i], list[least], temp);
    }
}