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
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector <int> v(n);
        readv(v, n);
        sort(v.begin(), v.end());
        int aux = v[(n-1)/2];
        int ans = 0;
        for (int i = (n-1)/2; i < n; i++) {
            if (v[i] == aux) {
                ans++;
            }
            else break;
        }
        cout << ans << nn;
    }
    return 0;
}