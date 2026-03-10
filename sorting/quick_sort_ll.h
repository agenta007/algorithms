//
// Created by neo on 3/9/26.
//

#ifndef QUICK_SORT_LL_H
#define QUICK_SORT_LL_H
int partition_ll(int array[], int left, int right)
{
    int pivot = array[left]; // определя оста

    while (left <= right) {
        //търси елемент, който е по-голям от оста
        while (array[left] < pivot)
            left++;

        //търси елемент, който е по-малък от оста
        while (array[right] > pivot)
            right--;

        // разменя елементите
        if (left <= right) {
            int tmp = array[left];
            array[left] = array[right];
            array[right] = tmp;

            left++; //увеличава левия индекс
            right--; //намаля десния индекс
        }
    }
    return left;
}

void QuickSort(int array[], int start, int end)
{
    // Разделя входната последователност на лява и дясна част
    // idx - показва до къде е обработена входната последователност
    int idx = partition_ll(array, start, end);

    // Рекурсивно извикване за лявата част
    if (start < idx - 1)
        QuickSort(array, start, idx - 1);

    // Рекурсивно извикване за дясната част
    if (end > idx)
        QuickSort(array, idx, end);
}
#endif //QUICK_SORT_LL_H
