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
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector <int> v1(n), v2(n);
        readv(v1, n);
        readv(v2, n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            for (j; j < n; j++) {
                if (v1[i] <= v2[j]) {break;}
            }
            ans = max(ans, j - i);
        }
        cout << ans << nn;
    
    }
    return 0;
}