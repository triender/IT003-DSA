#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll k;
        cin >> k;
        ll ans_m = -1, ans_n = -1, min_diff = 2 * k;

        ll sum_mn = k * 2, tempk = sqrt(sum_mn);

        for (ll n = tempk; n >= 2; n--)
        {
            ll m = (2 * k - 1 - n) / (2 * n + 1);
            if (2 * m * n + m + n + 1 == sum_mn)
            {
                if (abs(m - n) < min_diff)
                {
                    min_diff = abs(m - n);
                    ans_m = abs(m);
                    ans_n = abs(n);
                
                    if (min_diff <= 1)
                        break;
                }
            }
        }
        cout << min(ans_n, ans_m) << " " << max(ans_n, ans_m) << "\n";
    }

    return 0;
}