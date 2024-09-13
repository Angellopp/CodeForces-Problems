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
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        int aa = a[i] - '0';
        int bb = b[i] - '0';
        a[i] = '0';
        b[i] = '0';
        if(a > b and aa > bb or a < b and aa < bb) {
            a[i] = '0' + bb;
            b[i] = '0' + aa;
        }
        else{
            a[i] = '0' + aa;
            b[i] = '0' + bb;
        }
    }
    cout << a << endl << b << endl;
 
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
