#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define uu(n) cout << "<[" << #n << "] = " << n << ">" << nn
#define all(n) n.begin(), n.end()
using namespace std;

int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int n;
        cin >> n;
        vector <string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            string aux = v[i].substr(0, s.size());
            if(aux == s) {
                cout << v[i] << nn;
                flag = 1;
                break;
            }
        }
        if(!flag) cout << s << nn;



    




    }
    return 0;
}