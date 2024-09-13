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
using namespace std;

const int INF = 1e9 + 7;
const int maxn = 1e5 + 10;


int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while (tt--) {
        ll n, k;
        cin >> n >> k;
        if(n == k) {
            cout << "YES\n";
            cout << 1 << nn << n / k << nn;
        }
        else if(n +1 >= 2*k) {
            cout << "YES\n2\n";
            cout << n - k + 1 << " " << 1 << nn;
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}