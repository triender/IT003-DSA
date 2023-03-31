// Hồi kí
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    unsigned long long n, k, Max = 0, sum = 0;
    cin >> n >> k;

    vector<unsigned long long> chapter_pages(n);
    for (unsigned long long i = 0; i < n; i++)
    {
        cin >> chapter_pages[i];
        sum += chapter_pages[i];
        Max = max(Max, chapter_pages[i]);
    }

    unsigned long long left = Max, right = sum;

    while (left <= right)
    {
        unsigned long long mid = left + ((right - left) >> 1);
        unsigned long long pages_read = 0, volumes = 1;
        for (unsigned long long i = 0; i < n; i++)
        {
            if (pages_read + chapter_pages[i] > mid)
            {
                volumes++;
                if(volumes > k) break;
                pages_read = chapter_pages[i];
            }
            else
                pages_read += chapter_pages[i];
        }
        if (volumes <= k)
            right = mid - 1;
        else
            left = mid + 1;
    }
    cout << left << endl;
    return 0;
}
