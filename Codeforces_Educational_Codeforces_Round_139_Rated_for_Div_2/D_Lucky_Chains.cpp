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

const ll MX = 1e7 + 10;
int fact[MX];

void sieve() {
    for (ll i = 2; i < MX; i++) {
        if (fact[i] == 0) {
            for (int j = i; j < MX; j += i) {
                fact[j] = i;
            }
        }
    }
}   

int getDivisors(int& dif, int& n) {
    int ans = 1e9+5;
    while (dif > 1) {
        int f = fact[dif];
        if (dif % f == 0) {
            ans = min (ans, f * ((n + f - 1) / f) - n);
            while (dif % f == 0)
                dif /= f;
        }
    }
    return ans;
}

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    sieve();
    while (tt--) {
        int n, m;
        cin >> n >> m;
        int dif = m - n;
        if (dif == 1) {
            cout << -1 << nn;
            continue;
        }
        cout << getDivisors(dif, n) << nn;
        
    }
    return 0;
}