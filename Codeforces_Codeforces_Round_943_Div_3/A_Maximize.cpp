#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define uu(n) cout << "<[" << #n << "] = " << n << ">" << nn
#define all(n) n.begin(), n.end()
using namespace std;


int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int ans = 0, rr;
        for (int i = 1; i < n; i++) {
            if (__gcd(i, n) + i >= ans) {
                ans = __gcd(i, n) + i;
                rr = i;
            }
            // ans = max(ans, __gcd(i, n) + i);
        }
        cout << rr << nn;
    }
    return 0;
}