void quick_sort(int l, int h)
{
    if (h - l <= 10)
    { // switch to insertion sort for small arrays
        insertion_sort(l, h);
        return;
    }
    int j = partition(l, h);
    quick_sort(l, j);
    quick_sort(j + 1, h);
}
