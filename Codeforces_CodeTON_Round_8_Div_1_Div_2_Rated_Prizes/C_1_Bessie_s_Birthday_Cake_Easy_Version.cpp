    #include <bits/stdc++.h>
    #define ll long long
    #define F first
    #define S second
    #define nn '\n'
    #define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
    #define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
    #define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
    #define dbg(n) cout << "<[" << #n << "] = " << n << ">" << nn
    using namespace std;

    int main() {
        fast_io;
        int tt = 1;
        cin >> tt;
        while (tt--) {
            int n, x, y;
            cin >> n >> x >> y;
            vector <int> v(x);
            readv(v, x);
            int ans = 0;
            sort(v.begin(), v.end());
            // for (int i = 1; i <= x; i++) {
            //     if((v[i % x] - v[(i-1) % x] + n) % n == 2) {
            //         ans++;
            //     }
            // }
            ans += x + y - 2;
            int uno = 0;
            vector <int> par, impar;
            for (int i = 1; i <= x; i++) {
                int dif = (v[i % x] - v[(i-1) % x] + n) % n;
                dif--;
                (dif % 2 == 0) ? par.emplace_back(dif) : impar.emplace_back(dif);
                if (dif == 1) uno++;
            }
            // dbg(uno);
            sort(impar.begin(), impar.end());
            sort(par.begin(), par.end());

            for (int i = 0; i < impar.size() and y > 0; i++) {
                int punt = (impar[i] + 1) / 2;
                if (punt == 1) {
                    continue;
                }
                if (y >= (punt - 1)) {
                    ans += punt;
                    y -= (punt - 1); 
                }
                else {
                    ans += y;
                    y = 0;
                    // break;
                }
            }
            // dbg(ans);
            if (y > 0) {
                if (y >= par.size()) {
                    ans += par.size();
                    y -= par.size();
                }
                else {
                    ans += y;
                    y = 0;
                }
            }
            uno -= y;
            // ans += (y - uno);
            cout << ans + uno << nn;
            // for (int i = 0; i < par.size() and y > 0; i++) {
                
            // }
            // printv(par);
            // printv(impar);
        }
        return 0;
    }