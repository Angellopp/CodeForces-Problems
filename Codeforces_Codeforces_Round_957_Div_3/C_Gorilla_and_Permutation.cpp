




















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

const int maxn = 1e5+3;

int main() {
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >>n >> m >> k;
        for (int i = n; i > m; i--) {
            cout << i << " ";
        }
        for (int i = 1; i <= m; i++) {
            cout << i << " ";
        }
        cout << endl;

    }
}
