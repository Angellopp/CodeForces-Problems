#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define uu(n) cout << "<[" << #n << "] = " << n << ">" << nn
#define all(n) n.begin(), n.end()
using namespace std;

const int INF = 1e9 + 7;
const int maxn = 1e5 + 10;

ll sum(int n) {
    return n * 1ll * (n+1) / 2;
}

int main() {
    fast_io;
    int tt = 1;
    while (tt--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        ll ans = 0;
        for (int i = 0; i + 1 < n; i++) {
            int x = v[i], y = v[i+1];
            if (x > y) swap(x, y);
            ans += (n-y+x+1) * 1ll * (y - x);
        }
        ans += sum(n) - sum(v[0] - 1) - sum(n-v[0]);
        ans += sum(n) - sum(v[n-1] - 1) - sum(n-v[n-1]);
        cout << ans / 2 << nn;

    }
    
    return 0;
}