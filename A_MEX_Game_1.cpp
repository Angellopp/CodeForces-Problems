#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << " [ " << #x << " = " << x << " ]\n";
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;

// const int mod = 32768;
// vector <int> dp(mod+10);
// vector <bool> vis(mod+10);

void solve() {
    int n, xd;
    cin >> n;
    vector<int> m(n+2, 0);
    for (int i = 0; i < n; i++) {cin >> xd; m[xd]++;}
    if(m[0] == 0) {cout << 0 << endl; return;}
    if(m[0] == 1) {
        for (int i = 1; i <= n; i++) {
            if(m[i]<=1) { 
                cout << i << endl; return; 
            }
    }
    }
    int ind = 0;
    for (int i = 1; i <= n; i++) {
        if(m[i]==1) { ind = i; break;}
    }
    // dbg(ind);
    for (int i = 1; i <= n; i++) {
        if(i == ind) continue;
        if(m[i]<=1) { 
            cout << i << endl; return;
        }
    }

}

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}