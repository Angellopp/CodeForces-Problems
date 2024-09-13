#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define dbg(n) cout << "<[" << #n << "] = " << n << ">" << nn
int mod = 1e9+7;
using namespace std;
const int maxn = 2.5e6 + 10;
int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        n *= 2;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                if (360 % (n / i) == 0 and (n / i) <= 180 - n/2){
                    cout << 360 * i / n << nn;
                    break;
                }
            }
        }
    }
    return 0;

}


