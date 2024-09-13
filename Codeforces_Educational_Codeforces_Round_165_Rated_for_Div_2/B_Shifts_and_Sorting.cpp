#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define uu(n) cout << "<[" << #n << "] = " << n << ">" << nn
#define all(n) n.begin(), n.end()
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        s = s + "1";
        int n = s.size();
        int curr = s[0];
        // vector <pair<int, int>> v;
        int caj1 = 0, caj2 = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++) {

            if (s[i] == '1') {
                if(caj2 != 0) {ans += (caj2)*((caj1 != 0) ? caj1+1 : 0); ; caj2 = 0;}
                caj1++;
                curr = s[i];
            }
            else {
                caj2++;
                
                // if (curr == '1') {ans += (caj2)*((caj1 != 0) ? caj1+1 : 0); caj1 = 0; caj2 = 0;}
                curr = s[i];
            }
            // cout << ans << nn;
            // if (i == n-1) ans += (caj2)*(caj1+1);
            
        }
        // if(caj2 != 0 and s[n-1] == '1') {ans += (caj2)*((caj1 != 0) ? caj1+1 : 0); caj1 = 0; caj2 = 0;}
        cout << ans << nn;
    }
}