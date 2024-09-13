#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define cp(x) cerr << " [ " << #x << " = (" << x.F << ", " << x.S << ") ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define all(x) x.begin(), x.end()
#define ll long long
#define double long double
#define clz(x) __builtin_clz(x) 
#define ctz(x) __builtin_ctz(x) 

using namespace std;

int f(int n) {
    int ans = 0;
    while(n % 2 == 0) {
        n/=2;
        ans++;
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> v(n), sum(n+1,0);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        sum[i+1] = sum[i] + v[i]; 
    }
    int ans = 2e5 + 10;
    for (int i = 0; i < n; i++) {
        // int k = sum[i];
        int it = upper_bound(all(sum), k + sum[i]) - sum.begin();
        if(it) it--;
        if(sum[it] - sum[i] == k) {
            ans = min(ans, n - (it - i));
        }
    }
    if(ans == 2e5+10) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    fastio;
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}