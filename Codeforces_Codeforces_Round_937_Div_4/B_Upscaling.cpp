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
        int n;
        cin >> n;
        for (int i = 0; i < 2*n; i++) {
            for (int j = 0; j < 2*n; j++) {
                if((i/2 + j/2) % 2) cout << ".";
                else cout << "#";
            }
            cout << nn;
        } 
    }        

    return 0;
}