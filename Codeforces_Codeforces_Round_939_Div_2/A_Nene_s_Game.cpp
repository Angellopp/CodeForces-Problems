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
            int k, q;
            cin >> k >> q;
            vector<int> a(k), n(q);
            readv(a,k);
            readv(n,q);
            for (int i = 0; i < q; i++) {
                if (n[i] < a[0]){
                    cout << n[i] << " ";
                }
                else {
                    cout << a[0] - 1 << " ";
                }
            }
            cout << nn;
        }
        
        return 0;
    }