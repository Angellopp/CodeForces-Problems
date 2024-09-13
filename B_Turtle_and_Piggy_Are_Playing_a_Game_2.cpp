#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << " [ " << #x << " = " << x << " ]\n";
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector <int > v(n);
    for (int i = 0; i < n; i++) cin>> v[i];
    sort(all(v));
    cout << v[n/2] << endl;
}

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}