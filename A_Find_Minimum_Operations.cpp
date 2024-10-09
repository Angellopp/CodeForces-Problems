#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << n << endl; return;
    }
    int ans = 0;
    while(n) {
        ans += n - k * (n / k);
        n /= k;
    }
    cout << ans << endl;
}

int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}