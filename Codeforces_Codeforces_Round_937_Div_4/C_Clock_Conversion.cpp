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
    fast_io;
    int tt = 1;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int h = stoi(s.substr(0,2));
        if (h == 0) cout << 12 << s.substr(2) << " AM\n";
        else if (h == 12) cout << s << " PM\n";
        else if (h < 13) cout << s << " AM\n";
        else cout << ((h-12<10) ? "0" : "") << h-12 << s.substr(2) << " PM\n";   
    }        

    return 0;
}