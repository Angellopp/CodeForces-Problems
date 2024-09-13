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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector <ll> v(n);
        readv(v, n);
        ll ans = 0, aux = 0;
        for (int i = 0; i < n; i++) {ans ^= v[i];}
        if (ans == 0) {
            cout << "YES" << nn;
            continue;
        }
        bool can1 = 0, can2 = 0;
        int i, j;
        for (i = 0; i < n; i++) {
            aux ^= v[i];
            if (aux == ans) {can1 = 1; break;}
        }
        aux = 0;
        for (j = n-1; j >= 0; j--) {
            aux ^= v[j];
            if (aux == ans) {can2 = 1; break;}
        }
        cout << ((can1 and can2 and i < j) ? "YES" : "NO") << nn;
    }
    return 0;
}