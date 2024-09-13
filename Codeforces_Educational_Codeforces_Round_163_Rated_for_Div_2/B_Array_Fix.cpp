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

bool check (int i) {
    return (i / 10 <= i % 10);
}

int main() {
    fast_io;
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        bool can = 1;
        vector <int> v(n);
        readv(v, n);
        int curr = (check(v[0]) ? v[0] % 10 : v[0]); 
        for (int i = 1; i < n; i++) {
            if (v[i] < curr) {
                can = 0; break;
            }
            else {
                if (v[i] >= 10 and v[i] / 10 >= curr and check(v[i])) curr = v[i] % 10;
                else curr = v[i];
            }
        }
        (can) ? cout << "YES\n" : cout << "NO\n";

    }

    return 0;
}