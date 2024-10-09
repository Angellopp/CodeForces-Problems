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
    int a, b, c;
    cin >> a >> b >> c;
    cout << min(2 *b+4*c, min(2*a+2*c, 4*a+2*b)) <<endl;

}

int main() {
    fastio;
    int tt = 1;
    for (int i = 1; i <= tt; i++) {
        solve();
    }
}
