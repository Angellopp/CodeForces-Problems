#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define dbg(x) cerr << #x << " = " << x << endl
#define raya cerr << string(20, '=') << endl
#define pv(x) cerr << #x << ": "; for (auto e : x) cerr << e << " "; cerr << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define ff first
#define ss second

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector <pair<int,int>> v(n);
    vector <ll> pre(n+1);
    for (int i = 0; i < n; i++) {cin >> v[i].ff, v[i].ss = i+1;}
    sort(all(v));
    for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + v[i-1].ff;
    set<int> ans;
    ans.insert(v[n-1].ss);
    for(int i = n-1; i >= 1; i--) {
        if(!(pre[i] >= v[i].ff)) break;
        ans.insert(v[i-1].ss);
    }
    cout << ans.size() << endl;
    for(auto& x : ans) cout << x << " ";
    cout << endl;
}

int main() {
    fastio;
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}

