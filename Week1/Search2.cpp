#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll k;
        cin >> k;
        ll ans_m = -1, ans_n = -1;

        ll sum_mn = k * 2, tempk = sqrt(sum_mn);

        for (ll m = 1; m < tempk; m++)
        {
            ll n = (sum_mn - 1 - m) / (2 * m + 1);
            if (m <= n && 2 * m * n + m + n + 1 == sum_mn)
            {
                ans_m = m;
                ans_n = n;
            }
        }
        cout << ans_m << " " << ans_n << "\n";
    }

    return 0;
}
