#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << " [ " << #x << " = " << x << " ]\n";
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;

vector <bool> vis(1000+5, 0);

int ask(int a, int b){
    cout << "? " << a << " " << b << endl;
    int r; cin >> r;
    return r;
}

void f(int i, int j, map <pair<int,int>,int>& ans) {
    if (vis[i] and vis[j]) return;
    int r = ask(i, j);
    if(r == i) {
        if(i > j) swap(i, j);
        if(ans.count({i, j}) == 0) {
            ans[{i, j}]++;
        }
        vis[i] = 1; vis[j] = 1;
        return;
    }
    f(i, r, ans);
    f(r, j, ans);

}

void solve() {
    int n;
    cin >> n;
    map <pair<int,int>, int> ans;
    for(int i = 2; i <= n; i++) {
        f(1, i, ans);
    }
    cout << "! ";
    for (auto& x : ans) 
        cout << x.F.F << " " << x.F.S << " ";
    cout << endl;
    for(int i = 0; i <= n; i++) vis[i] = 0;
    return;
}

int main() {
    fast_io;
    int tt;
    cin >> tt;

    while(tt--){
        solve();
    }
}