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

const int MAXN = 4e5+5; 
set<int> aa;
int FT[ MAXN ]{};
int getFT (int b){
    int v = 0;
    for (int x = b; x; x -= x & -x) v = max(v,FT[x]); 
    return v;
}
void setFT (int p, int v) {
    for (int x = p; x < MAXN; x += x & -x) FT[x] = max(FT[x], v);
}
int get (int a, int b) { return getFT(b) - getFT(a-1); }
void update (int x, int v) { setFT(x, v); }

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    int a[100+5][100+5];
    vector <int> ans(m);
    vector <int> b(m);
    for (int i = 0; i < m; i++) cin>> b[i];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            ans[j] += a[i][j];
        }
    }
    bool can = 1; 
    for (int i = 0; i < m; i++) if(b[i] > ans[i]) can = 0;
    cout << ((can) ? "Yes" : "No");
    
}