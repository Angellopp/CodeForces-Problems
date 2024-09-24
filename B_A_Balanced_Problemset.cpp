#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int dv = n / x;
    int ans = 0;
    for (int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            if(i <= dv) ans = max(ans, i);
            if(n/i <= dv) ans = max(ans, n/i);
        }
    }
    cout << ans << endl;
}


int main() {
    fastio;
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}

