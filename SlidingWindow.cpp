#include <bits/stdc++.h>
using namespace std;

const int WINDOW_SIZE = 3;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[105][106];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int min = INT_MAX, sum = 0;
    for (int i = 0; i < n - WINDOW_SIZE + 1; i++)
        for (int j = 0; j < m - WINDOW_SIZE + 1; j++)
        {
            sum = 0;
            for (int k = i; k < i + WINDOW_SIZE; k++)
                for (int l = j; l < j + WINDOW_SIZE; l++)
                    sum += arr[k][l];
            if (min > sum)
                min = sum;
        }
    cout << min;
    return 0;
}