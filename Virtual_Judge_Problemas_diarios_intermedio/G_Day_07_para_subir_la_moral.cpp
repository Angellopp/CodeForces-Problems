#include <bits/stdc++.h>
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define print_v(x) cerr << #x << "[]: "; for (auto e : x) cerr << e <<" "; cerr << '\n'
#define RAYA cerr << string(15,'=')
#define all(x) x.begin(), x.end()
using namespace std;
    typedef long long ll;
    const int MAXN = 4e5+5;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; 
        cin >> n;
        vector <int> v(n+1);
        vector <int> vis(n+1);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if(v[i] <= n) vis[v[i]]++;
        }
        int mex = 0;
        for (int i = 0; i <= n; i++) 
            if(vis[i] == 0) {mex = i; break;}
        
        pair<int, int> rg = {-1,-1};
        for (int i = 0; i < n; i++) {
            if(v[i] == mex+1) {
                if (rg.first == -1) rg.first = i; rg.second = i;
            }
        }
        if (rg.first == -1) {
            cout << ((mex == n) ? "No\n" : "Yes\n");
            continue;
        }
        for (int i = rg.first; i <= rg.second; i++) {
            if(v[i] <= n) vis[v[i]]--;
            v[i] = mex;
        }
        vis[mex] = 1;

        int nmex = 0;
        for (int i = 0; i <= n; i++) {
            if(vis[i] == 0) {nmex = i; break;}
        }
        cout << ((nmex - mex == 1) ? "Yes\n" : "No\n");
    }
    return 0;
}
