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
    string s;
    cin >> s;
    if(s[0] != s[n-1]) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;


}

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}