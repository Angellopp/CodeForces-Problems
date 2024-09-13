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



int maxn = 500+4;
void solve() {
    int n, m;
    char c;
    cin >> n >> m;
    int a[maxn][maxn], b[maxn][maxn];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            cin >> c;
            b[i][j] = c - '0';
        }
    }
    vector<int> sumfilas_a(n), sumcolumnas_a(m);
    vector<int> sumfilas_b(n), sumcolumnas_b(m);
    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum = (sum + a[i][j]) % 3;
        }
        sumfilas_a[i] = sum;
    }
    for (int i = 0; i < m; i++){
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum = (sum + a[j][i]) % 3;
        }
        sumcolumnas_a[i] = sum;
    }

    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum = (sum + b[i][j]) % 3;
        }
        // dbg(sum);
        sumfilas_b[i] = sum;
    }
    for (int i = 0; i < m; i++){
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum = (sum + b[j][i]) % 3;
        }
        sumcolumnas_b[i] = sum;
    }
    bool can = 1;

    for (int i = 0; i < n; i++) {
        if(sumfilas_a[i] != sumfilas_b[i]) can = 0;
    }
    for (int i = 0; i < m; i++) {
        if(sumcolumnas_a[i] != sumcolumnas_b[i]) can = 0;
    }
    cout << ((can) ? "YES" : "NO") << endl;

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
