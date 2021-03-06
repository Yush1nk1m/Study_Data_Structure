// insertion sorting components which apart 'gap' times with each other
// sort range : first ~ last
void inc_insertion_sort(int list[], int first, int last, int gap)
{
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap) {
        key = list[i];
        for (j = i - gap; j >= first && key < list[j]; j = j - gap)
            list[j + gap] = list[j];
        list[j + gap] = key;
    }
}

void shell_sort(int list[], int n)  // n = size
{
    int i, gap;
    for (gap = n / 2; gap > 0; gap = gap / 2) {
        if ((gap % 2) == 0) gap++;
        for (i = 0; i < gap; i++)   // the number of part list is 'gap'
            inc_insertion_list(list, i, n - 1, gap);
    }
}