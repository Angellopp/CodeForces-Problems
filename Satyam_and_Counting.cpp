
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define dbg(x) cerr << #x << " = " << x << endl
#define raya cerr << string(20, '=') << endl
#define pv(x) cerr << #x << ": "; for (auto e : x) cerr << e << " "; cerr << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define ff first
#define ss second

typedef long long ll;

const int N = 1e4+5;
const int INF = 1e9;

void solve() {
    int n, x, y;
    cin >> n;
    // vector <pair<int,int>> v(n);
    vector <bool> pis(n+1);
    vector <bool> ypis(n+1);
    vector <pair<int,int>> pp(n);
    ll cnt = 0;
    ll ans = 0;
    ll s0 = 0, s1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> pp[i].ff >> pp[i].ss;
        if(pp[i].ss == 0) {
            pis[pp[i].ff] = 1;
            s0++;
        }
        else {ypis[pp[i].ff] = 1; s1++;}
    }
    for (int i = 0; i < n; i++) {
        if(pp[i].ss == 0) {
            if(ypis[pp[i].ff]) ans += s1-1;
            if(pp[i].ff-1 >= 0 and pp[i].ff+1 <= n and ypis[pp[i].ff-1] and ypis[pp[i].ff+1]){
                ans++;
            }
        }
        else {
            if(pis[pp[i].ff]) ans += s0-1;
            if(pp[i].ff-1 >= 0 and pp[i].ff+1 <= n and pis[pp[i].ff-1] and pis[pp[i].ff+1]){
                ans++;
            }
        }

    }
    // dbg(p.size()-1);

    // ans += cnt*(p.size()-1);
    cout << ans << endl;
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
