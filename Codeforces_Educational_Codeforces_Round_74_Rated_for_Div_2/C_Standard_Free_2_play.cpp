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
            int h, n, aux;
            cin >> h >> n;
            deque <int> s;
            map <int, bool> mp;
            for (int i = 1; i <= n; i++) {
                cin >> aux;
                mp[aux] = 1;
                s.push_back(aux);
            }
            int ans = 0;

            while (s.size() and s.front() >= 3) {
                if (mp[s.front() - 1] == 1 and mp[s.front() - 2] == 0) {
                    int n = s.front() - 2;
                    s.pop_front();
                    s.pop_front();
                    s.push_front(n);
                    ans++;
                }
                else if (mp[s.front() - 1] == 1 and mp[s.front() - 2] == 1) {
                    s.pop_front();
                    s.pop_front();
                }
                else if (mp[s.front() - 1] == 0) {
                    s.pop_front();
                    if (s.size() == 0) break;
                    int n = s.front() + 1;
                    s.push_front(n);
                }
            }
            cout << ans << nn;
        }
        return 0;

    }


