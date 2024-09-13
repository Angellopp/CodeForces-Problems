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
    int n, m, k, l;
    cin >> n >> m >> k;
    vector <char> aa(m);
    vector <vector<int>> aux(m);
    for (int j = 0; j < m; j++) {
        int nn;
        cin >> nn;
        for (int i = 0; i < nn; i++) {cin >> l; aux[j].emplace_back(l-1);}
        cin >> aa[j];
    }
    // for (int i = 0; i < m; )
    int ans = 0;
    for (int i = 0; i < (1<<n); i++) {
        bool can = 1;
        for(int j = 0; j < m; j++) {
            int c = 0;
            for (int x : aux[j]) {
                c += (((i >> x) & 1));
            }
            if((c >= k and aa[j] == 'x') or (c < k and aa[j] == 'o')) can = 0;
        } 
        if(can) ans++;
    }
    cout << ans ;
    
}