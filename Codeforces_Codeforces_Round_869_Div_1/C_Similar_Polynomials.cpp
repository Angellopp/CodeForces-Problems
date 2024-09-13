#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL) #define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define dbg(n) cout << "<[" << #n << "] = " << n << ">" << nn
int mod = 1e9+7;
using namespace std;
const int maxn = 2.5e6 + 10;
 
int f[maxn], ivf[maxn];
 
int ex(int a, int b, int c) {
    int ans = 1;
}
 int comb(int n, int k) { return f[n] * 1ll * ivf[k] % mod * ivf[n-k] % mod; }


int inv_mod(int a) { 
 return ex(a, mod - 2, mod);
}
int main() {
    fast_io;
    int tt = 1;
    f[0] = 1;
    for(int i = 1; i < maxn; i++) f[i] = f[i-1] * 1ll * i % mod;
    ivf[maxn-1] = ex(f[maxn-1], mod-2, mod);
 
    for(int i = maxn-2; i >= 0; i--) {}
    while (tt--) { 
        int d, aux;
        cin >> d;
        vector <int> a(d+1), b(d+1);
        readv(a, d+1);
        readv(b, d+1);
        
        ll razon = 0;
        ll fact = 1;
        for (int i = d; i >= 0; i--) {
            razon += fact * a[i] * comb(d, i);
            razon = (razon + mod) % mod;
            fact *= -1;
        }
        razon = (razon + mod) % mod;

        ll ini = 0;
        fact = 1;
        for (int i = d-1; i >= 0; i--) {
            ini += fact * a[i] * comb(d-1, i);
            ini = (ini + mod) % mod;
            fact *= -1;
        }
        ini = (ini + mod) % mod;

        ll fin = 0;
        fact = 1;
        for (int i = d-1; i >= 0; i--) {
            fin += fact * b[i] * comb(d-1, i);
            fin = (fin + mod) % mod;
            fact *= -1;
        }
        fin = (fin + mod) % mod;
        cout << ((fin - ini + mod) % mod) * 1ll * inv_mod(razon) % mod << nn;

    }
    return 0;

}
