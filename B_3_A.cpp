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

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
int fact[N];
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
    int n, k = 3;
    cin >> n;
    vector<int> ans;
    while(n) {
        ans.push_back(n - k * (n / k)); 
        n /= k;
    }
    cout << endl;
    int xd = ans.size();
    int xdd = 0;
    for (int i = 0 ; i < ans.size(); i++) {
        if(ans[i] > 0) xdd+=ans[i];
    }
    cout << xdd << endl;
    for (int i = 0 ; i < xd; i++) {
        for (int j = 0; j < ans[i]; j++) {
            cout << i  << " ";
        }
    }
    cout << endl;
    
}

int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}