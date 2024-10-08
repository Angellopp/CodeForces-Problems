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

float ex(float a, int b) {
    float ans = 1;
    while(b) {
        if(b&1) ans = ans  * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int main() {
    fast_io;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int m, n;
        cin >> m >> n;
        float ans = 0;
        for (int i = 1 ; i < m; i++) {
            float base = i / (float)m;
            ans -= ex(base, n);
        }
        ans += m;
        cout << fixed << setprecision(5) << ans << nn;
    }
    return 0;

}


