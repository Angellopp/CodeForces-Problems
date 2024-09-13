#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define rr(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define pp(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define uu(n) cout << "<[" << #n << "] = " << n << ">" << nn
#define all(n) n.begin(), n.end()
using namespace std;

bool f(ll ii, vector <ll>& v, ll k) {
    ll ans = 0;
    for (int i = 0; i < v.size(); i++) {
        if(v[i] < ii) ans += ii - v[i];
        else break;
    }
    return ans <= k;
}

ll upper_bound(ll i, ll n, vector <ll> &v, ll k){
    ll lo = i;
    ll hi = n;
    while(lo < hi){
        ll mi = lo + (hi - lo + 1) / 2;
        if(f(mi, v, k)) lo = mi;
        else hi = mi-1;
    }
    return lo;
}

const ll M = 2*1e12;

int main() {
    int tt = 1;
    cin >> tt;
    while (tt--) {
        ll n, k;
        cin >> n >> k;
        vector <ll> v(n);
        rr(v, n);
        sort(all(v));
        ll km = upper_bound(1, M, v, k), aux = 0;
        for (int i = 0; i < n; i++) {
            if(v[i] <= km) k -= km - v[i];
            else aux++;
        }
        k += aux+1;
        cout << k + n * (km-1) << nn;

    
    }
    return 0;
}