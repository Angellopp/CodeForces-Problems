#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << " [ " << #x << " = " << x << " ]\n";
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;

int ask(int a, int b){
    cout << "? " << a << " " << b << endl;
    int r; cin >> r;
    return r;
}

int ternarySearch(int l, int r){
    while (l < r) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        int res = ask(mid1, mid2);
        if (res == mid1 * mid2) {
            l = mid2 + 1;
        } 
        else if (res == (mid1+1) * (mid2+1)) {
            r = mid1 - 1;
        } 
        else {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    return l;
}

void solve() {
    int ans = ternarySearch(1, 1000);
    cout << "! " << ans << endl;
}

int main() {
    fast_io;
    int tt;
    cin >> tt;

    while(tt--){
        solve();
    }
}
