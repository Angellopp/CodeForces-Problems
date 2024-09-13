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
    #define all(n) n.begin(), n.end()
    using namespace std;

    const int INF = 1e9 + 7;
    const int maxn = 1e5 + 10;


    int main() {
        fast_io;
        int tt = 1;
        cin >> tt;
        while (tt--) {
            int n, k;
            cin >> n >> k;
            if (n == 1) {
                cout << k << nn;
                continue;
            }
            int aux = 0;
            int i = 0;
            while (aux + (1 << i) <= k) {
                aux += (1 << i);
                i++;
            }
            
            cout << aux << " " << k - aux << " ";
            for (int j = 0; j < n-2; j++) cout << 0 << " ";
            
            cout << nn;

        }
        
        return 0;
    }