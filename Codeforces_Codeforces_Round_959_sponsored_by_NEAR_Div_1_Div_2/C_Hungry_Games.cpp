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
#define double long double
using namespace std;

vector <ll> sum(2e5+2);

int lower_bound(int i, int n, ll lim){
    int lo = i, hi = n;
    while(lo < hi){
        int mid = lo + (hi - lo) / 2;
        if(sum[mid] <= lim) lo = mid+1;
        else hi = mid;
    }
    return lo;
}


int main() {
    fastio;
    ll n, k, q;
    cin >> q;
    
    while(q--) {
        cin >> n >> k;
        vector <ll> ans(n+1); 
        vector <int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        for (int i = 0; i < n; i++) sum[i+1] = sum[i] + 1ll*v[i];

        ans[n] = (v[n-1] > k);

        for (int i = n-2; i >= 0; i--) {
            int ind = lower_bound(1, n, k+sum[i]);
            if (sum[ind] - sum[i] > k) ans[i+1] = 1 + ((ind < n) ? ans[ind+1] : 0);
            else ans[i+1] = 0;
        }

        ll acc = 1ll * n * (n+1) / 2;
        for(int i = 1; i <= n; i++) acc -= ans[i];
        cout << acc << endl;
    }
}