#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << " [ " << #x << " = " << x << " ]\n";
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    vector <int > v(n);
    for(int i = 0; i  <n; i++) {
        cin >> v[i];
    }
    sort(all(v));
    // for (int i = n-1; i > 0; i--) {
    if(n == 1) {
        if(v[0] == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;}
        if(v[n-1] > v[n-2]+1) {
            cout << "NO" << endl;
            return;
        }
    // }
    cout << "YES" << endl;
}

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}