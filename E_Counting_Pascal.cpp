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


ll nn = 0, m, b;

bool f(int j) {
    
}
const int N = 1e5 + 2;
const ll MOD = 1e11 + 7;

ll fact[N];

ll mul_mod(ll a, ll b) {
    return 1ll * a * b % MOD;
}

ll pow_mod(ll a, ll e) {
    ll r = 1;
    while(e) {
        if (e & 1) r = mul_mod(r, a);
        a = mul_mod(a, a);
        e >>= 1;
    }
    return r;
}

ll inv_mod(ll a) { 
    return pow_mod(a, MOD - 2);
}

ll C(ll n, ll k) {
    if (k > n) return 0;
    ll num = fact[n];
    ll den = mul_mod(fact[k], fact[n - k]);
    return mul_mod(num, inv_mod(den));
}

// bool f(int mid) {
//     return 
// }

// 1 1 1 1 ... |1| 0 0 .... 0
ll upper_bound(ll i, ll n){
    ll lo = i;
    ll hi = n;
    while(lo < hi){
        ll mid = lo + (hi - lo + 1) / 2;
        if(C(mid, b) <= nn) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

void solve() {
    cin >> nn;
    if(nn == -1) return ;
    if(nn == 2) {
        cout << 1 << endl;
        return;
    }
    ll ans = nn-1;
    for(int j = 2; j < 40; j++) {
        b=j;
        ans += upper_bound(1ll*3,1ll*1e5)-3;
        dbg(upper_bound(3ll,1ll*1e5));
    }
    
    cout << ans << endl;
    return;
}
int main() {
    fastio;
    cout << fixed << setprecision(10);
    // ll a = 2, ind = 3;
    // while (a <= 1e9) {
    //     v.emplace_back(a);
    //     a = a * ind / ((ind+1)/2);
    //     ind++;
    //     if(ind % 2 == 1) imp.emplace_back(a);
    // }
    while(nn != -1) {
        solve();
    }
    return 0;
}
