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

const int maxn = 1e3 + 5;

int main() {
    fastio;
    int n, m;
    bool pre[maxn][maxn]{}, suf[maxn][maxn]{}, mat[maxn][maxn]{};
    bool sol[maxn]{};
    cin >> n >> m;
    int a, aux;
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> aux;
        sol[aux] = 1;
    }
    int pp = -1, ss = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        for (int j = 1; j <= a; j++) {
            cin >> aux;
            mat[i][aux] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) pre[i][j] = pre[i-1][j] ^ mat[i][j];
        bool can = 1;
        for (int j = 1; j <= m; j++) {
            if (pre[i][j] != sol[j]) can = 0;
        }
        if(can) {pp = i; break;}
    }
    for (int i = n; i >= 2; i--) {
        for (int j = 1; j <= m; j++) suf[i][j] = suf[i+1][j] ^ mat[i][j];
        bool can = 1;
        for (int j = 1; j <= m; j++) {
            if (suf[i][j] != sol[j]) can = 0;
        }
        if(can) ss = i;
    }
    if (pp == -1 and ss == -1) {
        cout << "-1\n";
    }
    else {
        if(pp != -1) cout << pp << "\n";
        else cout << n + ss - 1 << "\n";
    }

}