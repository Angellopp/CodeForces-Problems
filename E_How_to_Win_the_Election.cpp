#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

const int maxn = 2e5+5;
vector<ll> suf(maxn, 0);
vector<ll> ans(maxn, 0);

ll res = 0;
ll m = 0;

bool f(int idx, ll x, vector<ll>& v) {
    int n = v.size();
    ll val = v[idx];
    int num = upper_bound(all(v), val + x) - v.begin();
    int num_may = n - num;
    int ns = num - 1;
    ll queda = res - x;
    int falta = m - n + num;
    int lo = n - m - 1;
    if(falta <= 0) return 0;
    ll aux = 1ll * falta * (val + x + 1) - (suf[lo] - suf[ns+1] - val); 
    aux += (lo >= idx) * (v[lo] - val);
    return aux > queda; 
}

ll lowerBound(int idx, ll i, ll n, vector<ll>& v){
    ll lo = i;
    ll hi = n; 
    while(lo < hi){
        ll mid = lo + (hi - lo) / 2;
        if(!f(idx, mid, v)) lo = mid+1;
        else hi = mid;
    }
    if(f(idx, lo, v)) return lo; 
    else return -1;
}

void solve() {
    ll n, k;
    cin >> n >> m >> k;
    vector<pair<ll,int>> v(n);
    vector<ll> auxv(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {cin >> v[i].ff; v[i].ss = i; sum += v[i].ff;}
    for (int i = 0; i < n; i++) auxv[i] = v[i].ff;
    if(m == n) {
        for (int i = 0; i < n; i++) cout << 0 << " ";
        cout << endl;
        return;
    }
    res = k - sum;
    sort(all(v));
    sort(all(auxv));
    for (int i = n-1; i >= 0; i--) {
        suf[i] = suf[i+1] + auxv[i];
    }
    // dd(res);
    for (int i = 0; i < n; i++) {
        ans[v[i].ss] = lowerBound(i, 0, res, auxv);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    for (int i = 0; i <= n; i++) suf[i] = 0; 
}

int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}

