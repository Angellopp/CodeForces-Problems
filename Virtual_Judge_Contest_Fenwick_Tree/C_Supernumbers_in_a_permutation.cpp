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
    int n;
    cin >> n;
    vector <int> v(n), dp(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        dp[i] = 1 + getFT(v[i]-1);
        setFT(v[i], dp[i]);
    }
    int lis = 0;
    int lis_aux = 0;
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
        lis = max(dp[i], lis);
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (dp[i] == lis) {
            getFT(v[i]-1);
            cout << v[i] << " ";
        }
    }
    

    // 3 = {3, 6}
    // 2
    
    // for (int i = 0; i < n; i++) FT[i] = 0;
    // for (int i = n-1; i >= 0; i--) {
    //     if(dp[i] == lis_aux) {
    //         ans.insert(v[i]);
    //         ((lis_aux) ? lis_aux-- : lis_aux = lis);
    //     }
    // }
}