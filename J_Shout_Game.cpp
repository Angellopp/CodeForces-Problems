#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ddl cerr << string(20, '=') << endl;
#define ll long long
#define ld long double
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;
const int MOD = 1e9+7; 

int sum_mod(int a, int b) {
    return (1ll * a + 1ll *  b) % MOD;
}

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    for (auto c : s) {
        cnt+=c-'0';
    }
    cout << cnt%3;

}

int main() {
    fastio;
    int tt = 1;
    for (int i = 1; i <= tt; i++) {
        solve();
    }
}
