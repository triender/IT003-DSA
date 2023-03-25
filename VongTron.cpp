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



//////////// cách bình thường///////////
// #include <iostream>
// #include <vector>
// int main() {
//     int N, K;
//     std::cin >> N >> K;
//     std::vector<int> a(N), new_pos(N);
//     for (int i = 0; i < N; i++)
//         std::cin >> a[i];
//     for (int i = 0; i < N; i++) {
//         int old_pos = i;
//         int new_idx = (old_pos + K) % N;
//         new_pos[new_idx] = a[i];
//     }
//     for (auto i : new_pos)
//         std::cout << i << " ";
//     return 0;
// }
