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

const int MAXN = 4e5+5; 
int FT[ MAXN ]{};
int getFT (int b){
    int v = 0;
    for (int x = b; x; x -= x & -x) v += FT[x];
    return v;
}
void setFT (int p, int v) {
    for (int x = p; x < MAXN; x += x & -x) FT[x] += v;
}
int get (int a, int b) { return getFT(b) - getFT(a-1); }
void update (int x, int v) { setFT(x, v); }

int main() {
    fastio;
    int n, aux;
    cin >> n;
    vector <pair<int,int>> v(n);
    vector <pair<int,int>> ord(n);
    for (int i = 0; i < n; i++) {cin >> v[i].F; v[i].S = i;}
    sort(all(v));
    for (int i = 0; i < n; i++) ord[v[i].S] = {v[i].F, i+1};
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        setFT(ord[i].S, 1);
        int m = getFT(ord[i].S-1);
        ans += 1ll * ord[i].F * m;
    }
    for (int i = 0; i < MAXN; i++) FT[i] = 0;
    for (int i = n-1; i >= 0; i--) {
        setFT(ord[i].S, 1);
        int m = n-i - getFT(ord[i].S);
        ans -= 1ll * ord[i].F * m;
    }
    cout << ans << "\n";
}