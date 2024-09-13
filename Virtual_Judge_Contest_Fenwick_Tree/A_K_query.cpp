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

const int MAXN = 3e4 + 10;
int FT[MAXN];
bool FTT[MAXN]{0};

int getFT (int b) { int v = 0; for (int x = b; x; x -= x & -x) v += FT[x]; return v; }
void setFT (int p, int v) { for (int x = p; x < MAXN; x += x & -x) FT[x] += v; }
int get(int a, int b) { return getFT(b) - getFT(a-1); }
void update(int x, int v) { setFT(x, v); }

int main() {
    int n, q;
    cin >> n;
    vector <pair<int,int>> v(n);
    // vector <pair<int,int>> perm(n+1); 
    // vector <int> ord(n+1);
    for (int i = 0; i < n; i++) {cin >> v[i].F; v[i].S = i+1;}
    sort(all(v));
    // for (int i = 1; i <= n; i++) {perm[i] = {v[i-1].S, i};}
    // sort(perm.begin() + 1, perm.end());
    // for (int i = 1; i <= n; i++) {ord[i] = perm[i].S;}
    // for (int i = 1; i <= n; i++) {cout << ord[i] << " ";} cout << endl;
    
    
    cin >> q;
    vector <vector<int>> query;
    for (int i = 0; i < q; i++) {
        vector <int> aux(4);
        cin >> aux[1] >> aux[2] >> aux[0];
        aux[3] = i;
        query.emplace_back(aux);
        // aux[0] *= -1;
    }
    vector <int> ans(q);
    sort(rall(query));
    int i = n-1;

    for (auto x : query) {
        // int piv = -x.F[0];
        int piv = x[0];
        while(i >= 0 and v[i].F > piv) {
            setFT(v[i].S, 1);
            i--;
        }
        ans[x[3]] = get(x[1], x[2]);
    }
    for (int i = 0; i < q; i++) cout << ans[i] << "\n"; 

    return 0;
}