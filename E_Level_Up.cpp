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
int ind, k;

bool f(int ind, int k) {
    
}

int upper_bound(int i, int n, int k){
    int lo = i;
    int hi = n;
    while(lo < hi){
        int mid = lo + (hi - lo + 1) / 2;
        if(f(mid, k)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector <int> v(n), ans(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        ans[i-1] = upper_bound(0, n-1, i);
    }

    while(q--) {
        cin >> ind >> k;


    }

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
