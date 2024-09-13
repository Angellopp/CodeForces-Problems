#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;  

void cambio(char & c) {
    if(c == '1') c = '0';
    else c = '1';
}

int main() {
    fastio;
    int tt;
    cin >> tt;
    while (tt--) {
        int n, d;
        cin >> n >> d;
        string s;
        cin >> s;
        string ss  = s;
        reverse(all(s));
        s = ss + s;
        char cur = s[n-1];
        int l_ini = 0;
        int i = n-1;
        for (i; i >= 0; i--) {
            if(s[i] != cur) break;
            l_ini++; 
        }
        bool imp = (l_ini == d);
        // cout << i << "ga\n";
        if(l_ini > d) {
            cout << "-1\n";
            continue;
        }
        if(i == -1) {
            cout << d << "\n";
            continue;
        }
        bool can1 = 1;
        // cout << i << "ga1\n";
        int i_aux = i;
        while(can1 or (l_ini == d and i >= 0)) {
            can1 = 0;
            l_ini = 0;
            cambio(cur);
            // cout 
            for (int j = 0; j < d; j++) {
                if(s[i] != cur) break;
                l_ini++;
                i--;
            }
            if(l_ini == d)i_aux = i;
        }
        i = i_aux+1;
        // cout << s << "\n";
        string xd = s.substr(i,n-i) + s.substr(2*n - i);
        vector <char> as;
        char asd = xd[0];
        for (int j = 0; j < n/d; j++) {
            for (int m = 0; m < d; m++) {
                as.push_back(asd);
            }
            cambio(asd);
        }
        bool f = 1;
        for (int l = 0; l < n ; l++) {
            if(as[l] != xd[l]) {
                f = 0;
            }
        }
        if(f) {
            if(i == 0) cout << n << "\n";
            else cout << i << "\n";
        }
        else cout << "-1\n";
        
    }
}