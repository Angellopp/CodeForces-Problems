#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define dbg(n) cout << "<[" << #n << "] = " << n << ">" << nn
ll MOD = 998244353;
using namespace std;

int main() {
    fast_io;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector <int> v(n+1);
        vector <int> pos(n+1);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            pos[v[i]]= i+1;
        }
        int ans = n+1;
        int j = 1, acum = 0;
        while (acum < n) {
            int cur = 0;
            int aux = 0;
            for (j; j <= n ; j++) {
                if (pos[j] < cur) break;
                cur = pos[j];
                aux++;
            }
            acum += aux;
            ans = min(n-aux, ans);
        }
        cout << ans << nn;
    }
    return 0;
}