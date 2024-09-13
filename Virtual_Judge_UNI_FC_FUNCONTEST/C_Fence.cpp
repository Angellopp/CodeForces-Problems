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
        int n, k;
        cin >> n >> k;
        vector <ll> v(n);
        readv(v, n);
        ll sum = 0, ind = 0;
        for (int i = 0; i < k; i++) {
            sum += v[i];
        }
        ll minsum = sum;
        for (int i = 1; i + k - 1 < n; i++) {
            sum += (- v[i - 1] + v[i + k - 1]);
            if (minsum > sum) {
                ind = i;
                minsum = sum;
            }
        }

        cout << ind  + 1 << nn;



    }
    return 0;
}