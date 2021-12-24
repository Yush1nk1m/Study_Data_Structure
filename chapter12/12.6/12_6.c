#define MAX_SIZE 10
int sorted[MAX_SIZE];   // extra space is needed

void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left; j = mid + 1; k = left;

    /* merging lists which are divided and sorted */
    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if (i > mid)    /* copy leaving records */
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    else
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    /* recopy array sorted[] into array list[] */
    for (l = left; l <= right; l++)
        list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right)
{
    int mid;
    if (left < right) {
        mid = (left + right) / 2;           /* equal dividing of list */
        merge_sort(list, left, mid);        /* sorting partial list */
        merge_sort(list, mid + 1, right);   /* sorting partial list */
        merge(list, left, mid, right);      /* merging */
    }
}