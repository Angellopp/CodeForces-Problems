#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define ll long long
using namespace std;

int main() {
    fastio;
    ll tt;
    cin  >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        vector <ll> v(n);
        for (ll i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector <vector <ll> > a(n-2, vector <ll> (3, 0));
        for (ll i = 0; i+2 < n; i++) {
            a[i][0] = v[i];
            a[i][1] = v[i+1];
            a[i][2] = v[i+2];
        }
        map<pair<ll,ll>, vector <ll> > mp1, mp2, mp3; 
        for (ll i = 0; i < n-2; i++) {
            mp1[{a[i][0], a[i][1]}].push_back(a[i][2]);
            mp2[{a[i][0], a[i][2]}].push_back(a[i][1]);
            mp3[{a[i][1], a[i][2]}].push_back(a[i][0]);
        }
        ll ans = 0;
        for (auto x : mp1) {
            if (x.second.size() < 2) continue;
            map<ll, ll> y;
            for (auto z : x.second) y[z]++;
            vector <ll> zz;
            for (auto z : y)  zz.emplace_back(z.second);
            for (ll i = 0; i + 1< zz.size(); i++)
                for (ll j = i+1; j < zz.size(); j++) 
                    ans += zz[i] * zz[j];
            // cout << x.first.first << " " << x.first.second << " " << x.second.size() << "\n";
        }
        for (auto x : mp2) {
            if (x.second.size() < 2) continue;
            map<ll, ll> y;
            for (auto z : x.second) y[z]++;
            vector <ll> zz;
            for (auto z : y)  zz.emplace_back(z.second);
            for (ll i = 0; i + 1< zz.size(); i++)
                for (ll j = i+1; j < zz.size(); j++) 
                    ans += zz[i] * zz[j];
            // cout << x.first.first << " " << x.first.second << " " << x.second.size() << "\n";
        }
        for (auto x : mp3) {
            if (x.second.size() < 2) continue;
            map<ll, ll> y;
            for (auto z : x.second) y[z]++;
            vector <ll> zz;
            for (auto z : y)  zz.emplace_back(z.second);
            for (ll i = 0; i + 1< zz.size(); i++)
                for (ll j = i+1; j < zz.size(); j++) 
                    ans += zz[i] * zz[j];
            // cout << x.first.first << " " << x.first.second << " " << x.second.size() << "\n";
        }
        cout << ans << "\n";
    }
}