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
#define clz(x) __builtin_clz(x) 
#define ctz(x) __builtin_ctz(x) 

using namespace std;


int mod = 1e9 + 7;
void solve() {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int ans = 0;
    int x = 0, y = 0;
    if(a1 > b1) x++;
    else if(a1 < b1) y++;
    if(a2 > b2) x++;
    else if(a2 < b2)y++;
    if(x > y) ans+=2;
    x = 0; y = 0;
    if(a1 > b2) x++;
    else if(a1 < b2) y++;
    if(a2 > b1) x++;
    else if(a2 < b1) y++;
    if(x > y) ans+=2;
    cout << ans << endl;


}

int main() {
    fastio;
    int q;
    cout << fixed << setprecision(10);
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}
