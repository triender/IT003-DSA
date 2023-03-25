#include <bits/stdc++.h>
using namespace std;

class BasicSorting
{
protected:
    vector<int> vec;

public:
    void GetArr(int n)
    {
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            vec.push_back(val);
        }
    }
    void BubbleSort()
    {
        for (int i = 0; i < vec.size(); i++)
            for (int j = vec.size() - 1; j > i; j--)
                if (vec[j] < vec[j - 1])
                    swap(vec[j], vec[j - 1]);
    }
    void InterchangeSort()
    {
        for (int i = 0; i < vec.size() - 1; i++)
            for (int j = i + 1; j < vec.size(); j++)
                if (vec[j] > vec[i])
                    swap(vec[i], vec[j]);
    }
    void SelectionSort()
    {
        int i, j, min_idx;
        for (i = 0; i < vec.size() - 1; i++)
        {
            min_idx = i;
            for (j = i + 1; j < vec.size(); j++)
                if (vec[j] < vec[min_idx])
                    min_idx = j;

            if (min_idx != i)
                swap(vec[min_idx], vec[i]);
        }
    }
    void InsertionSort()
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
    void Display()
    {
        for (auto &&i : vec)
            cout << i << " ";
    }
};

// const int MAX = 100000;
// void DistributedCountSort(vector<int> &a, int *count)
// {
//     for (int i = 0; i < a.size(); i++)
//         count[a[i]]++;
// }
class AdvancedSorting : public BasicSorting
{
private:
    void Heapify(int n, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && vec[l] > vec[largest])
            largest = l;
        if (r < n && vec[r] > vec[largest])
            largest = r;
        if (largest != i)
        {
            swap(vec[largest], vec[i]);
            Heapify(n, largest);
        }
    }
    void Merge(int l, int m, int r)
    {
        vector<int> subvec = vec;
        int i = l, j = m + 1, k = l;
        while (i <= m && j <= r)
        {
            if (subvec[i] <= subvec[j])
                vec[k++] = subvec[i++];
            else
                vec[k++] = subvec[j++];
        }
        while (i <= m)
            vec[k++] = subvec[i++];
        while (j <= r)
            vec[k++] = subvec[j++];
    }
    // Hoare's Partition
    // int Partition(int l, int r)
    // {
    //     int pivot = vec[l + (r - l) / 2];
    //     int i = l - 1, j = r + 1;
    //     while (true)
    //     {
    //         do
    //         {
    //             i++;
    //         } while (vec[i] < pivot);
    //         do
    //         {
    //             j--;
    //         } while (vec[j] > pivot);

    //         if (i >= j)
    //             return j;

    //         swap(vec[i], vec[j]);
    //     }
    // }
    // Lomuto's Partition
    int Partition(int l, int r)
    {
        int Pivot = vec[r];
        int i = l - 1;
        for (int j = l; j < r; j++)
        {
            if (vec[l] <= Pivot)
            {
                i++;
                swap(vec[i], vec[j]);
            }
            swap(vec[i + 1], vec[r]);
            return i + 1;
        }
    }

public:
    void HeapSort()
    {
        int n = vec.size();
        for (int i = n / 2; i >= 0; i--)
            Heapify(n, i);
        for (int i = n - 1; i >= 0; i--)
        {
            swap(vec[i], vec[0]);
            Heapify(i, 0);
        }
    }
    void MergeSort(int l = 0, int r = -1)
    {
        if (r == -1)
            r = vec.size() - 1;
        if (l < r)
        {
            int m = l + (r - l) / 2;
            MergeSort(l, m);
            MergeSort(m + 1, r);
            Merge(l, m, r);
        }
    }
    void QuickSort(int l = 0, int r = -1)
    {
        if (r == -1)
            r = vec.size() - 1;
        if (l < r)
        {
            int pivot = Partition(l, r);
            QuickSort(l, pivot);
            QuickSort(pivot + 1, r);
        }
    }
    void ShellSort()
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
};

int main()
{
    int n;
    cin >> n;
    AdvancedSorting Arr;
    Arr.GetArr(n);
    Arr.ShellSort();
    Arr.Display();
    return 0;
}