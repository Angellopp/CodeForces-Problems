#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;

const int maxn = 2e5 + 5;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int fact[N];
vector <int> g[maxn];
vector <bool> nf(maxn), vis(maxn);
vector <int> nhijos(maxn);

int mul_mod(int a, int b) {
    return 1ll * a * b % MOD;
}

int pow_mod(int a, int e) {
    int r = 1;
    while(e) {
        if (e & 1) r = mul_mod(r, a);
        a = mul_mod(a, a);
        e >>= 1;
    }
    return r;
}

int inv_mod(int a) { 
    return pow_mod(a, MOD - 2);
}

int C(int n, int k) {
    if (k > n) return 0;
    int num = fact[n];
    int den = mul_mod(fact[k], fact[n - k]);
    return mul_mod(num, inv_mod(den));
}

int dfsnh(int i) {
    vis[i] = 1;
    for (int j : g[i]) {
        if (vis[j]) continue;
        nhijos[i] += dfsnh(j) + 1;
    }
    return nhijos[i];
}

ll ans = 1;

int f (int i) {
    vis[i] = 1;
    if(g[i].empty()) return 1;
    int p = 1;
    int nhij_aux = nhijos[i];
    for (int j : g[i]) {
        p = mul_mod(p, f(j));
        p = mul_mod(p, C(nhij_aux, nhijos[j]+1));
        nhij_aux -= (nhijos[j]+1);
    }
    return p;
}


int main() {
    fastio;
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1ll * fact[i - 1] * i % MOD;
    }
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            g[a].emplace_back(b);
            nf[b] = 1;
        }

        int us = n;
        for (int i = 1; i <= n; i++) if(!nf[i]) dfsnh(i);

        for (int i = 1; i <= n; i++) {
            if(nf[i]) continue;
            int nhij_aux = nhijos[i] + 1;
            ans = mul_mod(ans, f(i));
            ans = mul_mod(ans, C(us, nhij_aux));
            us -= nhij_aux;
        }
        cout << ans;
        
    }
    return 0;
}