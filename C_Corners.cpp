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
    int n, m;   
    char c;
    cin >> n >> m;
    int n1 = 0;
    bool n0 = 0, n00 = 0;
    vector <vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m ; j++) {
            cin >> c;
            v[i][j] = c - '0';
            if(c == '1') n1++;
            if(c == '0') n0 = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m ; j++) {
            if(v[i][j] == 0) {
                for(int k = 0; k < 8; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ver(ni, nj, n, m) and v[ni][nj] == 0) {
                        n00 = 1;
                        break;
                    } 
                }
            }
        }
    }
    if(n00) cout << n1 << endl;
    else if(n0) cout << n1 - 1 << endl;
    else cout << n1-2 << endl;
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