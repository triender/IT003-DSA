#include <iostream>
#include <climits>
using namespace std;

typedef unsigned long long ll;

ll a, k, b, m, n;

ll numTreesCut(ll days)
{
    return (days - days / k) * a + (days - days / m) * b;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> k >> b >> m >> n;

    ll left = 1, right = n / min(a, b), mid, treesCut;

    while (left < right)
    {
        mid = left + ((right - left) >> 1);
        treesCut = numTreesCut(mid);

        if (treesCut >= n)
            right = mid;
        else
            left = mid + 1;
    }
    cout << left << endl;
    return 0;
}
