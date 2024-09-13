#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define dbg(n) cout << "<[" << #n << "] = " << n << ">" << nn
#define all(n) n.begin(), n.end()
using namespace std;

const int INF = 1e9 + 7;
const int maxn = 1e5 + 10;
ll nec = 0;
ll n = 0, k = 0;

int ans(vector <ll>& v, ll ini, ll fin, char op) {
    if (ini == fin) 
        return (v[ini] + nec > k) ? n-1 : n;
    int sz = n - fin - ini + 1;
    
    if (op == 'L'){
        if (v[ini] <= v[fin]) {
            nec += 2 * v[ini] - 1; v[fin] -= v[ini] - 1;
            if (nec > k) return sz;
            return ans(v, ini + 1, fin, 'R');
        }
        else {
            nec += 2 * v[fin]; v[ini] -= v[fin];
            if (nec > k) return sz;
            return ans(v, ini, fin - 1, 'L');
        }
    }
    else {
        if (v[fin] <= v[ini]) {
            nec += 2 * v[fin] - 1; v[ini] -= v[fin] - 1;
            if (nec > k) return sz;
            return ans(v, ini, fin - 1, 'L');
        }
        else {
            nec += 2 * v[ini]; v[fin] -= v[ini];
            if (nec > k) return sz;
            return ans(v, ini + 1, fin, 'R');
        }
    }
}

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while (tt--) {
        cin >> n >> k;
        vector <ll> v(n);
        readv(v, n);
        nec = 0;
        cout << ans(v, 0, n-1, 'L') << nn;
        
    }
    return 0;
}