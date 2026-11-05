#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high, int &comp, int &swaps, bool randomized)
{
    if (randomized)
    {
        int pivotindex = low + rand() % (high - low + 1);
        swap(arr[pivotindex], arr[low]);
        swaps++;
    }

    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (true)
    {
        while (left <= right)
        {
            comp++;

            if (arr[left] <= pivot)
                left++;
            else
                break;
        }

        while (left <= right)
        {
            comp++;

            if (arr[right] >= pivot)
                right--;
            else
                break;
        }

        if (left > right)
            break;

        swap(arr[left], arr[right]);
        swaps++;
    }

    swap(arr[low], arr[right]);
    swaps++;

    return right;
}

void quicksort(vector<int> &arr, int low, int high, int &comp, int &swaps, bool randomized)
{
    if (low >= high)
        return;

    int pivot = partition(arr, low, high, comp, swaps, randomized);

    quicksort(arr, low, pivot - 1, comp, swaps, randomized);
    quicksort(arr, pivot + 1, high, comp, swaps, randomized);
}

void printarr(vector<int> &arr)
{
    for (auto ele : arr)
        cout << ele << " ";

    cout << endl;
}

int main()
{
    srand(time(0));

    vector<int> arr = {10, 7, 8, 9, 1, 5};

    int comp = 0;
    int swaps = 0;

    bool randomized = true;

    quicksort(arr, 0, arr.size() - 1, comp, swaps, randomized);

    cout << "Sorted Array: ";
    printarr(arr);

    cout << "Comparisons: " << comp << endl;
    cout << "Swaps: " << swaps << endl;

    return 0;
}