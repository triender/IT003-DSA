// Nếu bây chạy mà không được thì bỏ thằng đo thời gian của Merge ra
// tui cũng không biết sao nó bị lỗi đâu.
#include <algorithm>
#include <iostream>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <vector>

using namespace std;
using namespace std::chrono;

constexpr int N[] = {10, 100, 1000, 5000, /* 10000, 50000, 100000, 250000, */ -1};

void generateVector(vector<int> &vec, int n, int min, int max)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        vec.push_back(min + rand() % (max - min + 1));
}

void printVector(vector<int> &vec)
{
    for (auto &&i : vec)
        cout << i << " ";
    cout << endl;
}

void bubbleSort(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        for (int j = vec.size() - 1; j > i; j--)
            if (vec[j] < vec[j - 1])
                swap(vec[j], vec[j - 1]);
}

void shakerSort(vector<int> &vec)
{
    int left = 0;
    int right = vec.size() - 1;
    int k = 0;
    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            if (vec[i] > vec[i + 1])
            {
                swap(vec[i], vec[i + 1]);
                k = i;
            }
        }
        right = k;
        for (int i = right; i > left; i--)
        {
            if (vec[i] < vec[i - 1])
            {
                swap(vec[i], vec[i - 1]);
                k = i;
            }
        }
        left = k;
    }
}

void interchangeSort(vector<int> &vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
        for (int j = i + 1; j < vec.size(); j++)
            if (vec[j] < vec[i])
                swap(vec[i], vec[j]);
}

void selectionSort(vector<int> &vec)
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

void insertionSort(vector<int> &vec)
{
    int val, idx;
    for (int i = 1; i < vec.size(); i++)
    {
        val = vec[i];
        idx = i - 1;
        while (val < vec[idx] && idx >= 0)
        {
            vec[idx + 1] = vec[idx];
            idx--;
        }
        vec[idx + 1] = val;
    }
}

int binarySearch(vector<int> vec, int k, int left, int right)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (vec[mid] <= k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

void binaryInsertionSort(vector<int> &vec)
{
    int val, idx, k;
    for (int i = 1; i < vec.size(); i++)
    {
        val = vec[i];
        idx = i - 1;
        k = binarySearch(vec, val, 0, idx);
        while (idx >= k)
        {
            vec[idx + 1] = vec[idx];
            idx--;
        }
        vec[idx + 1] = val;
    }
}

void merge(vector<int> &vec, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = vec[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = vec[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            vec[k++] = left[i++];
        else
            vec[k++] = right[j++];
    }
    while (i < n1)
        vec[k++] = left[i++];
    while (j < n2)
        vec[k++] = right[j++];
}

void heapify(vector<int> &vec, int n, int i)
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

void mergeSort(vector<int> &vec, int l = 0, int r = -1)
{
    if (r == -1)
        r = vec.size();
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(vec, l, m);
        mergeSort(vec, m + 1, r);
        merge(vec, l, m, r);
    }
}

void heapSort(vector<int> &vec)
{
    for (int i = vec.size() / 2 - 1; i >= 0; i--)
        heapify(vec, vec.size(), i);
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

void shellSort(vector<int> &vec)
{
    int size = vec.size();
    for (int gap = size / 2; gap > 0; gap /= 2)
        for (int i = gap; i < size; i++)
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

int partition(vector<int> &vec, int l, int r)
{
    int pivot = vec[l + ((r - l) >> 1)];
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

void quickSort(vector<int> &vec, int l = 0, int r = -1)
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

void countSort(vector<int> &vec, int base)
{
    int size = vec.size();
    const int max = 20; // count array size must be increased to accommodate negative digits
    int count[max] = {};
    int output[size];

    for (int i = 0; i < size; i++)
        count[(vec[i] / base) % 10 + max / 2]++; // shift negative digits to non-negative range

    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        int digit = (vec[i] / base) % 10 + max / 2;
        output[count[digit] - 1] = vec[i];
        count[digit]--;
    }

    for (int i = 0; i < size; i++)
        vec[i] = output[i];
}

void countingSort(vector<int> &vec)
{
    int size = vec.size();
    int min = *min_element(vec.cbegin(), vec.cend());
    int max = *max_element(vec.cbegin(), vec.cend());
    int range = max - min + 1;
    vector<int> output(size);
    vector<int> count(range);

    for (int i = 0; i < size; i++)
        count[vec[i] - min]++;

    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[vec[i] - min] - 1] = vec[i];
        count[vec[i] - min]--;
    }

    for (int i = 0; i < size; i++)
        vec[i] = output[i];
}

void radixSort(vector<int> &vec)
{
    int max = abs(*max_element(vec.cbegin(), vec.cend())); // use absolute value of maximum element

    for (int base = 1; max / base > 0; base *= 10)
        countSort(vec, base);

    // re-order negative elements in descending order
    int i = 0, j = vec.size() - 1;
    while (i < j)
    {
        if (vec[i] < 0 && vec[j] < 0)
        {
            swap(vec[i], vec[j]);
            i++;
        }
        else if (vec[i] < 0 && vec[j] >= 0)
        {
            i++;
            j--;
        }
        else if (vec[i] >= 0 && vec[j] < 0)
        {
            swap(vec[i], vec[j]);
            i++;
            j--;
        }
        else
        {
            j--;
        }
    }
}

template <typename SortingFunction>
long long measureTime(SortingFunction sortFunc, const vector<int> &vec)
{
    vector<int> vec_copy = vec;
    auto start = high_resolution_clock::now();
    sortFunc(vec_copy);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

long long measureTimeMerge(const vector<int> &vec)
{
    vector<int> vec_copy = vec;
    auto start = high_resolution_clock::now();
    mergeSort(vec_copy);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

long long measureTimeQuick(const vector<int> &vec)
{
    vector<int> vec_copy = vec;
    auto start = high_resolution_clock::now();
    quickSort(vec_copy);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k = 0;
    int numberOfElement = N[k++];
    while (numberOfElement != -1)
    {
        int n = numberOfElement;
        vector<int> vec;

        generateVector(vec, n, -10000, 10000);

        cout << "Mang truoc khi sap xep:" << endl;
        printVector(vec);

        long long timeInterchange = measureTime(interchangeSort, vec);
        long long timeBubble = measureTime(bubbleSort, vec);
        long long timeShaker = measureTime(shakerSort, vec);
        long long timeSel = measureTime(selectionSort, vec);
        long long timeIns = measureTime(insertionSort, vec);
        long long timeBiIns = measureTime(binaryInsertionSort, vec);
        long long timeMerge = measureTimeMerge(vec);
        long long timeHeap = measureTime(heapSort, vec);
        long long timeShell = measureTime(shellSort, vec);
        long long timeQuick = measureTimeQuick(vec);
        long long timeRadix = measureTime(radixSort, vec);
        long long timeCounting = measureTime(countingSort, vec);

        cout << "Mang sau khi sap xep:" << endl;
        mergeSort(vec);
        printVector(vec);

        cout << "So luong phan tu la: " << numberOfElement << endl;
        cout << "Thoi gian thuc hien Interchange sort: " << timeInterchange << " microseconds" << endl;
        cout << "Thoi gian thuc hien Bubble sort: " << timeBubble << " microseconds" << endl;
        cout << "Thoi gian thuc hien Shaker sort: " << timeShaker << " microseconds" << endl;
        cout << "Thoi gian thuc hien Selection sort: " << timeSel << " microseconds" << endl;
        cout << "Thoi gian thuc hien Insertion sort: " << timeIns << " microseconds" << endl;
        cout << "Thoi gian thuc hien Binary Insertion sort: " << timeBiIns << " microseconds" << endl;
        cout << "Thoi gian thuc hien Merge sort: " << timeMerge << " microseconds" << endl;
        cout << "Thoi gian thuc hien Heap sort: " << timeHeap << " microseconds" << endl;
        cout << "Thoi gian thuc hien Shell sort: " << timeShell << " microseconds" << endl;
        cout << "Thoi gian thuc hien Quick sort: " << timeQuick << " microseconds" << endl;
        cout << "Thoi gian thuc hien Radix sort: " << timeRadix << " microseconds" << endl;
        cout << "Thoi gian thuc hien Counting sort: " << timeCounting << " microseconds" << endl;
        cout << "-------------------------------------------\n";
        numberOfElement = N[k++];
    }
    return 0;
}
