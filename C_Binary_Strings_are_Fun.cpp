#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

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

void solve() {
    int n, l = 0;
    cin >> n;
    string s;
    cin >> s;
    vector <int> v;
    char cur = s[0];
    for (int i = 0; i < n; i++) {
        if(s[i] == cur) {
            l++;
        }
        else {
            v.emplace_back(l);
            l = 1;
            cur = s[i];
        }
    }   
    v.emplace_back(l);
    int ans = 0; 
    for (auto& x : v) {
        ans = (1ll * ans + pow_mod(2, x) - 1) % MOD ;
    }
    cout << ans << endl;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}