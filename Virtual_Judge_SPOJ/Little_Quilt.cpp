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

vector <vector<char>> A = {{'/', '/'}, {'/', '+'}}, B = {{'-', '-'}, {'-', '-'}};

void imprimir(vector <vector<char>>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++)
            cout << v[i][j];
        cout << nn;
    }
}

vector <vector<char>> turn(vector <vector<char>> v) {
    if(v.size() == 0) {return {};}
    int m = v.size();
    int n = v[0].size();
    vector <vector<char>> c(n, vector <char> (m, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[j][m-1-i] = v[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(c[i][j] == '/') c[i][j] = '\\';
            else if(c[i][j] == '\\') c[i][j] = '/';
            else if(c[i][j] == '-') c[i][j] = '|';
            else if(c[i][j] == '|') c[i][j] = '-';
        }
    }
    return c;
}

vector <vector<char>> sew(vector <vector<char>> v1, vector <vector<char>> v2) {
    int m1 = v1.size(), m2 = v2.size(); 
    int n1 = v1[0].size(), n2 = v2[0].size();
    if (v1.size() == 0 or v2.size() == 0 or m1 != m2) {return {};}
    vector <vector<char>> c(m1, vector <char> (n1+n2));
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) 
            c[i][j] = v1[i][j];
        for (int j = 0; j < n2; j++) 
            c[i][j+n1] = v2[i][j];
    }
    return c;
}

vector <vector <char>> convert (string s) {
    if (s == "A") return A;
    if (s == "B") return B;
    int i = s.find_first_of('(');
    int j = s.find_last_of(')');
    string ins = s.substr(0, i);
    string sturn = s.substr(i+1, j-i-1);
    if (ins == "sew") {
        int cont = 0, ind = 0;
        for (int i = 0; i < sturn.size(); i++) {
            if (sturn[i] == ',' and cont == 0) {
                ind = i;
                break;
            }
            else if (sturn[i] == '(') cont++;
            else if (sturn[i] == ')') cont--;
        }
        string v1 = sturn.substr(0, ind);
        string v2 = sturn.substr(ind+1);
        return sew(convert(v1), convert(v2));
    }
    else if(ins == "turn") {
        return turn(convert(sturn));
    }
}


int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        vector<string> entradas;
        string entrada_actual;
        char c;
        int cont = 1;
        while (cin.get(c)) {
            if (c == ';') {
                entradas.push_back(entrada_actual);
                entrada_actual.clear();
            } else if (c != ' ' && c != '\n') {
                entrada_actual += c;
            }
        }
        for (auto entrada : entradas) {
            cout << "Quilt " << cont++ << ":" <<  nn;
            vector <vector<char>> v = convert(entrada);
            if (v.size() == 0) {
                cout << "error\n";
                continue;
            }
            imprimir(v);
        }
    }
    return 0;
}