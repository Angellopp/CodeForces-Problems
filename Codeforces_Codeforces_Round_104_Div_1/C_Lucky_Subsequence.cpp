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

const int MOD = 1e9 + 7;
const int maxn = 1e5 + 10;
int nlk = 0, K = 0;
int fact[maxn];

vector <pair<int,int>> lk;

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

bool islk(int x) {
    while(x) {
        if(x % 10 != 4 and x % 10 != 7) return false;
        x /= 10;
    }
    return true;
}

int dp[2000][2000];

void fill1() {
    for (int i = lk.size(); i >= 0; i--) {
        for (int k = lk.size(); k >= 0; k--) {
            if (k == K) {dp[i][k] = 1; continue;}
            if (i == lk.size()) {dp[i][k] = C(nlk, K-k); continue;}
            dp[i][k] = (1ll * lk[i].S * dp[i+1][k+1] % MOD + dp[i+1][k] % MOD) % MOD;
        }
    }
}

void fill2() {
    for (int i = 0; i < lk.size(); i++) {
        dp[i][K] = 1;
        dp[lk.size()][i] = C(nlk, K-i);
    }
    for (int i = lk.size(); i >= 0; i--) {
        for (int k = lk.size(); k >= 0; k--) {
            dp[i][k] = (1ll * lk[i].S * dp[i+1][k+1] % MOD + dp[i+1][k] % MOD) % MOD;
        }
    }
}

int main() {
    fast_io;
    int tt = 1;
    // cin >> tt;
    fact[0] = 1;
    for (int i = 0; i < 2000; i++) for (int j = 0; j < 2000; j++) dp[i][j] = -1;

    for (int i = 1; i < maxn; i++) {
        fact[i] = 1ll * fact[i - 1] * i % MOD;
    }

    while (tt--) {
        int n, aux;
        cin >> n >> K;
        vector <int> v(n);
        map <int, int> m;
        readv(v, n);
        sort(all(v));

        int nolk = n;
        for (int i = 0; i < n; i++) {
            if (islk(v[i])) {
                m[v[i]]++; nolk--;
            }
        }
        nlk = nolk;

        for (auto x : m) lk.emplace_back(x.first, x.second);
        fill1();
        cout << dp[0][0] << nn;
    }
    return 0;
}