




















#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int mod = 1e8;

const int maxn = 1e4;

int n, a, b;

vector <pair<ll,ll>> solve(int p) {
    vector <pair<ll,ll>> ans;
    for (int i = 1; i < 7; i++) {
        string s;
        for (int j = 0; j < i; j++) s += to_string(n);
        s = s.substr(0, i);
        ll u = stoll(s);
        u = p*u - n*i;
        if(u % (n-p) == 0) {
            ll k = u / (n-p);
            b = k, a = (k + i) / p;
            if((b + i) % p == 0 and a > 0 and a <= maxn and b > 0 and b <= maxn) ans.emplace_back(a, b);
        }
    }
    return ans;
}

int main() {
    fastio;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        ll a, b;
        vector <pair <ll,ll>> ans;
        if (n == 1) {
            cout << maxn - 1 << endl;
            for (int i = 1; i < maxn; i++) {
                cout << i+1 << " " << i << endl;
            }
            continue;
        }
        int c = 0, aux = n;
        while(aux) {aux /= 10; c++;}
        ans = solve(c);
        cout << ans.size() << endl;
        for (auto x : ans) {
            cout << x.F << " " << x.S << endl; 
        }
    }
}
