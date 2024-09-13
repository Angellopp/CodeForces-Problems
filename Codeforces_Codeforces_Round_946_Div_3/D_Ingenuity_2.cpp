#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define ll long long
using namespace std;

int main() {
    fastio;
    int tt;
    cin  >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        if((mp['N'] + mp['S']) % 2 == 1 or (mp['E'] + mp['W']) % 2 == 1 or (mp['W'] == 1 and mp['E'] == 1 and mp['N'] == 0 and mp['S'] == 0) or (mp['N'] == 1 and mp['S'] == 1 and mp['W'] == 0 and mp['E'] == 0)) {
            cout << "NO\n";
        }
        else {
            int nN = mp['N'], nS = mp['S'], nE = mp['E'], nW = mp['W'];
            int hn = 0, hs = 0, rn = 0, rs = 0;
            int he = 0, hw = 0, re = 0, rw = 0;
            if (nN == 1 and nS == 1 and nE == 1 and nW == 1) {
                cout << "RRHH" << "\n";
            }
            else {
                if (nN == nS and nN > 0) {
                    hn = nN - 1;
                    hs = nS - 1;
                    rn = 1;
                    rs = 1;
                } else if(nN >= nS) {
                    hn = (nN - nS) / 2;
                    hs = 0;
                    rn = nN - hn;
                    rs = nS;
                } else {
                    hn = 0;
                    hs = (nS - nN) / 2;
                    rn = nN;
                    rs = nS - hs;
                }
                if (nE == nW and nE > 0) {
                    he = nE - 1;
                    hw = nW - 1;
                    re = 1;
                    rw = 1;
                }
                else {
                    if (nE >= nW) {
                        he = (nE - nW) / 2;
                        hw = 0;
                        re = nE - he;
                        rw = nW;
                    }
                    else {
                        he = 0;
                        hw = (nW - nE) / 2;
                        re = nE;
                        rw = nW - hw;
                    }
                }

                for (int i = 0; i < n; i++) {
                    if(s[i] == 'N') {
                        if(hn > 0) {
                            hn--;
                            cout << 'H';
                        }
                        else {
                            rn--;
                            cout << 'R';
                        }
                    }
                    else if(s[i] == 'S') {
                        if(hs > 0) {
                            hs--;
                            cout << 'H';
                        }
                        else {
                            rs--;
                            cout << 'R';
                        }
                    }
                    else if(s[i] == 'E') {
                        if(he > 0) {
                            he--;
                            cout << 'H';
                        }
                        else {
                            re--;
                            cout << 'R';
                        }
                    }
                    else if(s[i] == 'W') {
                        if(hw > 0) {
                            hw--;
                            cout << 'H';
                        }
                        else {
                            rw--;
                            cout << 'R';
                        }
                    }
                }
            cout << "\n";
            }
        }


    }
}