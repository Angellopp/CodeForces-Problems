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
            vector <int> v(x), impar;
            readv(v, x);
            sort(v.begin(), v.end());
            int ans = x + y - 2;
            int par = 0;
            for (int i = 1; i <= x; i++) {
                int dif = (v[i % x] - v[i-1] + n) % n - 1;

                if (dif % 2 == 0) par += dif / 2;
                else if (dif != 1) impar.emplace_back(dif);
                else ans++;
            }

            sort(impar.begin(), impar.end());

            for (int i = 0; i < impar.size() and y > 0; i++) {
                int punt = (impar[i] + 1) / 2;

                ans += min(y, punt-1);
                if (y >= punt - 1) ans++;
                y -= min(y, punt-1);
            }

            ans += min(y, par);
            y -= min(y, par);

            cout << ans - y << nn;
        }
        return 0;
    }