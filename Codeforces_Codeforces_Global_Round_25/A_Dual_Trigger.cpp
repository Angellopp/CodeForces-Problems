#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define dbg(n) cout << "<[" << #n << "] = " << n << ">" << nn
using namespace std;

const int INF = 1e9 + 7;
const int maxn = 1e5 + 10;




int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int con = 0;
        int caj = 0;
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if(s[i] == '0'){
                if(curr == 1) {
                    caj++;
                    curr = 0;
                }
            }
            else {
                if (curr == 0) curr = 1;
            }

            if (s[i] == '1') con++;
        }
        if(s[n-1] == '1') caj++;
        // dbg(caj);
        if (con % 2) {cout << "NO\n"; continue;}
        if (caj > 1) {cout << "YES\n"; continue;}
        if (con == 2) {cout << "NO\n"; continue;}
        cout << "YES\n";  

    }
    return 0;
}