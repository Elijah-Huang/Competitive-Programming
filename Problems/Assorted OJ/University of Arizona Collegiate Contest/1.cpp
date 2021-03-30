#include<vector>
#include<iostream>
#include<queue>
#include<tuple>
#include<ctime>
#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("s1.txt")
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string filename;
    string next_line;
    string s1, s2;
    cout << "Please enter the file name: ";
    cin >> filename;
    cout << "Please enter the input string: ";
    getline(cin, s2);
    getline(cin, s2);
    freopen(filename.c_str(), "r", stdin);
    while (getline(cin, next_line)) {
        s1 += next_line;
    }
    cout << s1 << '\n';

    cout << s1.length() << '\n';
    int n = s1.length(), m = s2.length();
    vector<int> pf(m);
    for (int i = 1; i < m; i++) {
        int j = pf[i - 1];
        while (j > 0 and s2[i] != s2[j]) {
            j = pf[j - 1];
        }
        pf[i] = j + (s2[i] == s2[j]);
    }

    string s3 = "\t\t";
    for (auto j : s3) {
        cout << j << '\n';
    }

    int j = 0;
    int occurences = 0;
    for (int i = 0; i < n; i++) {
        cout << s1[i] << '\n';
        if (s1[i] == '\t') {
            continue;
        }
        while (j > 0 and s1[i] != s2[j]) {
            j = pf[j - 1];
        }
        j += (s1[i] == s2[j]);
        if (j == m) {
            occurences++;
        }
    }

    cout << occurences << endl;
    return 0;
}