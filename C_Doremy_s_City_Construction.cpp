#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl '\n';
#define dd(x) cerr << #x << "=" << x << "." << endl;
#define ll long long
using namespace std;

const int maxn = 2e5+3;
vector <int> v(maxn);
int n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    sort(v.begin()+1, v.begin() + n+1);
    if (v[1] == v[n]){
        cout << n/2 << endl;
        return;
    }
    ll ans = 0;
    for (int l = 1, r = 1; l <= n; l = r = r+1){
        while (r+1 <= n and v[r+1] == v[l]) ++r;
        ans = max(ans, 1ll * (n-r) * r);
    }
    cout << ans << endl;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}