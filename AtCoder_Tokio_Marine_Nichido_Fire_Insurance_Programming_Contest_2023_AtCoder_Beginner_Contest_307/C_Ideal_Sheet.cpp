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

pair<int,int> refactor(vector <vector <char>> &a) {
    bool al = 1;
    int fil = -1, col = -1;
    while(fil+1 < (int)a.size()) {
        bool can = 0;
        for (int i = 0; i < (int)a[0].size(); i++) {
            can |= (a[fil+1][i] == '#');
        }
        if (can) break;
        fil++;
    }
    while(col+1< (int)a[0].size()) {
        bool can = 0;
        for (int i = 0; i < (int)a.size(); i++) {
            can |= (a[i][col+1] == '#');
        }
        if (can) break;
        col++;
    }
    return {fil, col};
}

vector <vector <char>> copy(vector <vector <char>> &a, int i, int j) {
    vector <vector <char>> b(a.size(), vector <char> (a[0].size()));
    for (int k = i+1; k < a.size(); k++) 
        for (int l = j+1; l < a[0].size(); l++) 
            b[k-i-1][l-j-1] = a[k][l];
    return b;

}

int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int ha, wa;
        cin >> ha >> wa;
        vector <vector <char>> a(ha, vector <char> (wa));
        for (int i = 0; i < ha; i++) 
            for (int j = 0; j < wa; j++) 
                cin >> a[i][j];
        
        int hb, wb;
        cin >> hb >> wb;
        vector <vector <char>> b(hb, vector <char> (wb));
        for (int i = 0; i < hb; i++) 
            for (int j = 0; j < wb; j++) 
                cin >> b[i][j];
        int hx, wx;
        cin >> hx >> wx;
        vector <vector <char>> c(ha + hb + hx, vector <char> (wa + wb + wx, '.'));
        vector <vector <bool>> bol(ha + hb + hx, vector <bool> (wa + wb + wx, 0));
        for (int i = 0; i < hx; i++) 
            for (int j = 0; j < wx; j++) 
                cin >> c[i][j];
        
        pair <int,int> ra = refactor(a);
        pair <int,int> rb = refactor(b);

        a = copy(a, ra.F, ra.S);
        b = copy(b, rb.F, rb.S);


        bool ans = 0;
        for (int i = 0; i < hx; i++) {
            for (int j = 0; j < wx; j++) {
                bool can = 1;
                for (int k = 0; k < ha; k++) {
                    for (int l = 0; l < wa; l++) {
                        if (a[k][l] == '#' and c[i+k][j+l] == '.') {
                            can = 0;
                            break;
                        }
                    }
                }
                if (can) {
                    for (int k = 0; k < ha + hb + hx; k++) 
                        for (int l = 0; l < wa + wb + wx; l++) 
                            bol[k][l] = 0;

                    for (int k = 0; k < ha; k++) 
                        for (int l = 0; l < wa; l++) 
                            if (a[k][l] == '#' and c[i+k][j+l] == '#') bol[i+k][j+l] = 1;
                        

                    for (int ii = 0; ii < hx; ii++) {
                        for (int jj = 0; jj < wx; jj++) {
                            bool can = 1;
                            for (int k = 0; k < hb; k++) {
                                for (int l = 0; l < wb; l++) {
                                    if (b[k][l] == '#' and c[ii+k][jj+l] == '.') {
                                        can = 0;
                                        break;
                                    }
                                }
                            }
                            if (can) {
                                for (int k = 0; k < hb; k++) 
                                    for (int l = 0; l < wb; l++) 
                                        if (b[k][l] == '#' and c[ii+k][jj+l] == '#') bol[ii+k][jj+l] = 1;

                                bool loc = 1;
                                for (int k = 0; k < hx; k++) 
                                    for (int l = 0; l < wx; l++) 
                                        if (((bol[k][l] or bol[k][l]) and c[k][l] == '.') or (!(bol[k][l] or bol[k][l]) and c[k][l] == '#')) loc = 0;
                            
                                ans |= loc;
                            }
                        }
                    }
                }
            }
        }
        cout << (ans ? "Yes" : "No") << nn;






    }
    return 0;
}