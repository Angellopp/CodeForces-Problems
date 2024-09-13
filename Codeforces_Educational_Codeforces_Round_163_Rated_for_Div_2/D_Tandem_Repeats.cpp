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

string s;
bool check(int i, int k) {
    return (s[i] == s[i+k/2] or s[i] == '?' or s[i+k/2] == '?');
}

int main() {
    fast_io;
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> s;
        int n = s.size();
        int ans = 0;
        for (int k = 2; k <= n; k+=2) {
            int sol = 0;
            for (int i = 0; i < k/2; i++) 
                sol += check(i, k);

            if (sol == k/2) ans = max(ans, k);

            for (int i = 1; i < n - k + 1; i++) {
                sol -= check(i-1, k);
                sol += check(i-1+k/2, k);
                if (sol == k/2) ans = max(ans, k);
            }
        }
        cout << ans << nn;
    }
    return 0;
}
