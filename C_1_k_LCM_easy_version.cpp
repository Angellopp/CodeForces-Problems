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

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

bool ver(int i, int j, int n, int m) {
    return(0 <= i and i < n and 0 <= j and j < m);
}

int maxn = 500+4;
void solve() {
    int n, k;
    cin >> n >> k;
    if(n % 4 == 2) {
        cout << 2 << " " << (n-2) / 2 << " " << (n-2) / 2 << endl;
        return;
    }
    else if(n % 4 == 0) {
        cout << n/2 << " " << n / 4 << " " << n / 4 << endl;
        return;
    } 
    else {
        cout << 1 << " " << n / 2 << " " << n / 2 << endl;
    }

}

int main() {
    fastio;
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}
