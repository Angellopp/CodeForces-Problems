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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int fact[N];

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

// int C(int n, int k) {
//     if (k > n) return 0;
//     int num = fact[n];
//     int den = mul_mod(fact[k], fact[n - k]);
//     return mul_mod(num, inv_mod(den));
// }


int main() {
    fastio;
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1ll * fact[i - 1] * i % MOD;
    }
    int n ,k, pos, val;
    cin >> n >> k;
    vector <int> v(n);
    map <int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]]++;
    }
    int ans = 1;
    for (auto x: m) {
        ans = mul_mod(ans, fact[x.second]);
    }
    int invfacn = inv_mod(fact[n]);
    cout << mul_mod(ans, invfacn) << "\n";
    for (int i = 0; i < k; i++) {
        cin >> pos >> val;
        pos--;
        m[val]++;
        // if(m[val] != 1) 
        //     ans = mul_mod(mul_mod(ans, mul_mod(m[val], inv_mod(m[v[pos]]))), inv_mod(m[val]-1));
        // else 
            ans = mul_mod(ans, mul_mod(m[val], inv_mod(m[v[pos]])));

        // dbg(ans);
        m[v[pos]]--; 
        v[pos] = val;
        cout << mul_mod(ans, invfacn) << "\n";
    }

}