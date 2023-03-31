#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll findMinHeight(vector<ll>& a, vector<ll>& b, ll n, ll m, ll mid, vector<ll>& c) {
    ll i = 0, j = 0, minHeight = INT64_MAX;
    while (i < n && j < m) {
        if (a[i] >= mid) {
            c[i] = a[i];
            i++;
        }
        else {
            if (a[i] + b[j] >= mid) {
                c[i] = a[i] + b[j];
                i++;
                j++;
            }
            else {
                j++;
            }
        }
    }
    for (i = 0; i < n; i++)
        minHeight = min(minHeight, c[i]);
    return minHeight;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, m, i, left, mid, j, mi;
    ll res = -1;

    cin >> n;
    vector<ll> a(n), c(n, 0);
    for (i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    vector<ll> b(m);
    for (i = 0; i < m; i++)
        cin >> b[i];

    left = 1;
    ll right = INT64_MAX >> 1;
    while (left <= right) {
        mid = left + ((right - left) >> 1);
        ll minHeight = findMinHeight(a, b, n, m, mid, c);
        if (minHeight < mid) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
            res = minHeight;
        }
    }

    // Tìm số tấm gỗ cần đóng
    ll k = 0;
    vector<pair<ll, ll>> added;
    for (i = 0, j = 0; i < n && j < m;) {
        if (a[i] < res) {
            if (a[i] + b[j] >= res) {
                k++;
                added.emplace_back(i + 1, j + 1);
                i++;
            }
            j++;
        }
        else {
            i++;
        }
    }

    cout << res << " " << k << endl;
    for (auto& p : added)
        cout << p.first << " " << p.second << endl;

    return 0;
}
