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
using namespace std;

ll m;
int MOD = 1e9+7;
int mul_mod(int a, int b) {
    return 1ll * a * b % MOD;
}

int pow_mod(int a, int e) {
    int r = 1;
    while(e) {
        if (e & 1) r = mul_mod(r, a);
        a = mul_mod(a, a);
        e >>= 1;
    }
    return r;
}

vector <int> f (string& s) {
    int sz = s.size();
    ll ans = 0;
    vector <int> ind;
    for (int i = 0; i < sz; i++) {
        ans = (ans * 10 % m + (s[i] - '0')) % m;
        if (ans == 1ll*0) ind.emplace_back(i);
    }
    return ind;
}

int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n >> m;
        string s;
        cin >> s;
        vector <int> ans = f(s);
        if (ans.empty() or ans.back() != s.size() - 1) {cout << 0 << "\n"; continue;}  
        if (ans.back() == s.size() - 1) ans.pop_back(); 
        int a = ans.size();
        cout << pow_mod(2, a);

    }
    return 0;
}