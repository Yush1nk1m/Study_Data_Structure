#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )
int partition(int list[], int left, int right)
{
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do {
        do
            low++;
        while (list[low] < pivot);
        do
            high--;
        while (list[high] > pivot);
        if (low < high) SWAP(list[low], list[high], temp);
    } while (low < high);

    SWAP(list[left], list[high], temp);
    return high;
}