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

void solve() {
    int n;
    cin >> n;
    int r, p, s;
    cin >> r >> p >> s;
    int ini = r + p + s;
    string ss, ans;
    cin >> ss;
    for (int i = 0; i < n; i++) {
        if(ss[i] == 'R') {
            if(p > 0) {ans.push_back('P'); p--;}
            else ans.push_back('.');
        }
        else if (ss[i] == 'P') {
            if(s > 0) {ans.push_back('S'); s--;}
            else ans.push_back('.');
        }
        else if (ss[i] == 'S') {
            if(r > 0) {ans.push_back('R'); r--;}
            else ans.push_back('.');
        }
    }
    if(!(ini - r - p - s >= (n+1)/2)) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        if (ans[i] == '.') {
            if(r > 0) {ans[i] = 'R'; r--;}
            else if(p > 0) {ans[i] = 'P'; p--;}
            else if(s > 0) {ans[i] = 'S'; s--;}
        }
    }
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
