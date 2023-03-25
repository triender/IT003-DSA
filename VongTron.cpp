#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int start = (-k % n + n) % n;

    rotate(a.begin(), a.begin() + start, a.end());

    for (auto i : a)
        cout << i << " ";
}