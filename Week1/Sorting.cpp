#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>

using namespace std;
using namespace std::chrono;

const int N[] = {100, 1000, 5000, 10000, 50000, -1};

void generateVector(vector<int> &vec, int n, int min, int max)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        vec.push_back(min + rand() % (max - min + 1));
}

void printVector(vector<int> vec)
{
    for (auto &&i : vec)
        cout << i << " ";
    cout << endl;
}

void BubbleSort(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
        for (int j = vec.size() - 1; j > i; j--)
            if (vec[j] < vec[j - 1])
                swap(vec[j], vec[j - 1]);
}

void selectionSort(vector<int> vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < vec.size(); j++)
            if (vec[j] < vec[minIdx])
                minIdx = j;
        swap(vec[i], vec[minIdx]);
    }
}

void insertionSort(vector<int> vec)
{
    int val, idx;
    for (int i = 1; i < vec.size(); i++)
    {
        val = vec[i];
        idx = i - 1;
        while (idx >= 0 && val < vec[idx])
        {
            vec[idx + 1] = vec[idx];
            idx--;
        }
        vec[idx + 1] = val;
    }
}

void heapify(vector<int> vec, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && vec[left] > vec[largest])
        largest = left;
    if (right < n && vec[right] > vec[largest])
        largest = right;
    if (largest != i)
    {
        swap(vec[i], vec[largest]);
        heapify(vec, n, largest);
    }
}

void heapSort(vector<int> vec)
{
    for (int i = vec.size() / 2 - 1; i >= 0; i--)
        heapify(vec, vec.size(), i);
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

void shellSort(vector<int> vec)
{
    for (int gap = vec.size() / 2; gap > 0; gap /= 2)
        for (int i = gap; i < vec.size(); i++)
        {
            int val = vec[i];
            int idx = i;
            while (idx >= gap && vec[idx - gap] > val)
            {
                vec[idx] = vec[idx - gap];
                idx -= gap;
            }
            vec[idx] = val;
        }
}

// Hoare's Partition
int partition(vector<int> vec, int l, int r)
{
    int pivot = vec[l + (r - l) / 2];
    int i = l - 1, j = r + 1;
    while (true)
    {
        do
        {
            i++;
        } while (vec[i] < pivot);
        do
        {
            j--;
        } while (vec[j] > pivot);

        if (i >= j)
            return j;

        swap(vec[i], vec[j]);
    }
}

void quickSort(vector<int> vec, int l = 0, int r = -1)
{
    if (r == -1)
        r = vec.size() - 1;
    if (l < r)
    {
        int pivot = partition(vec, l, r);
        quickSort(vec, l, pivot);
        quickSort(vec, pivot + 1, r);
    }
}

void QuickSortCall(vector<int> vec)
{
    quickSort(vec);
}

template <typename SortingFunction>
long long measureTime(SortingFunction sortFunc, vector<int> &vec)
{
    auto start = high_resolution_clock::now();
    sortFunc(vec);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

int main()
{
    int k = 0;
    int numberOfElement = N[k++];
    while (numberOfElement != -1)
    {
        int n = numberOfElement;
        vector<int> vec;

        generateVector(vec, n, -1000000, 1000000);

        // cout << "Mang truoc khi sap xep:" << endl;
        // printVector(vec);
        long long timeBubble = measureTime(BubbleSort, vec);
        long long timeSel = measureTime(selectionSort, vec);
        long long timeIns = measureTime(insertionSort, vec);
        long long timeHeap = measureTime(heapSort, vec);
        long long timeShell = measureTime(shellSort, vec);
        long long timeQuick = measureTime(QuickSortCall, vec);

        // cout << "Mang sau khi sap xep:" << endl;
        // heapSort(vec);
        // printVector(vec);

        cout << "So luong phan tu la: " << numberOfElement << "\n";
        cout << "Thoi gian thuc hien Bubble sort: " << timeBubble << " microseconds"
             << "\n";
        cout << "Thoi gian thuc hien Selection sort: " << timeSel << " microseconds"
             << "\n";
        cout << "Thoi gian thuc hien Insertion sort: " << timeIns << " microseconds"
             << "\n";
        cout << "Thoi gian thuc hien Heap sort: " << timeHeap << " microseconds"
             << "\n";
        cout << "Thoi gian thuc hien Shell sort: " << timeShell << " microseconds"
             << "\n";
        cout << "Thoi gian thuc hien Quick sort: " << timeQuick << " microseconds"
             << "\n\n";
        numberOfElement = N[k++];
    }
    system("pause");
    return 0;
}
