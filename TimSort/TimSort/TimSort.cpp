#include <iostream>
#include <vector>
#include <algorithm>
#include "ArrayList.h"

template <typename T>
void InsertionSort(std::vector<T>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++) {
        T temp = arr[i];
        int j = i;
        while (j > left && arr[j - 1] > temp) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}

template <typename T>
void Merge(std::vector<T>& arr, int left, int mid, int right)
{
    int len1 = mid - left + 1;
    int len2 = right - mid;
    std::vector<T> leftArr(len1);
    std::vector<T> rightArr(len2);

    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[left + i];

    for (int i = 0; i < len2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0;
    int k = left;
    while (i < len1 && j < len2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < len2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

template <typename T>
void Timsort(std::vector<T>& arr)
{
    int minrun = 32; // Размер минимальной последовательности run

    int n = arr.size();
    for (int i = 0; i < n; i += minrun)
    {
        InsertionSort(arr, i, std::min(i + minrun - 1, n - 1));
    }

    for (int size = minrun; size < n; size *= 2)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = std::min((left + 2 * size - 1), (n - 1));
            Merge(arr, left, mid, right);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    ArrayList<double> list;
    list.AddEnd(3);
    list.AddEnd(1);
    list.AddEnd(5);
    list.AddEnd(2);
    list.AddEnd(0);
    list.AddEnd(4);

    list.Print();

    std::vector<double> arr(list.Size());
    for (int i = 0; i < list.Size(); i++)
    {
        arr[i] = list.Get(i);
    }

    Timsort(arr);

    std::cout << "Массив List после сортировки: ";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}