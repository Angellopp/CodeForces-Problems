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
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector <int> v(n-1);
        readv(v, n-1);
        int mod = v[0] + 1;
        cout << mod << " ";
        for (int i = 1; i < n-1; i++) {
            if(((-v[i] + v[i-1]) % mod + mod) % mod == 0){
                mod = v[i] + ((-v[i] + v[i-1]) % mod + mod) % mod + mod;
            }
            else mod = v[i] + ((-v[i] + v[i-1]) % mod + mod) % mod;
            cout << mod << " ";  
        }
        cout << (v[n-2]) % mod << " "; 
        // cout << mod << " ";  

        cout << nn;

    }
    return 0;
}