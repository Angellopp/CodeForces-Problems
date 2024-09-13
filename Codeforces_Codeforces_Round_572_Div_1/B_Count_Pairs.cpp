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

int main() {
    fast_io;
    int tt = 1;
    while (tt--) {
        int n, p, k, aux;
        cin >> n >> p >> k;
        map<int, int> m;

        for(int i = 0; i < n; i++) {
            int a; cin >> a;

            int num = a * 1ll * a % p * a % p * a % p - a * 1ll * k % p;
            num %= p;
            if(num < 0) num += p;

            m[num]++;
        }

        ll ans = 0;

        for(auto e : m) {
            ans += e.second * 1ll * (e.second-1) / 2;
        }
         
        cout << ans << "\n";
    }
    
    return 0;
}