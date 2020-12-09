/*
ID: elijahj1
TASK: cryptcow
LANG: C++14
*/

#include<bits/stdc++.h>
#include<unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;


using namespace std;
const int maxn = 100;
const int mod = 1e9 + 7;
const int p = 31;
vector<long long> pinv(maxn);
vector<long long> pnorm(maxn);
char originala[48] = "Begin the Escape execution at the Break of Dawn";
string original = "Begin the Escape execution at the Break of Dawn";
gp_hash_table<int,bool> substrings({}, {}, {}, {}, { 1<< 11}), visited({}, {}, {}, {}, { 1<< 19});

long long powm(long long b, long long exp) {
    b %= mod;
    long long res = 1;
    while (exp) {
        if (exp % 2 == 1) {
            res = (res * b) % mod;
        }
        exp >>= 1;
        b = (b * b) % mod;
    }
    return res;
}

void precompute_p() {
    pinv[maxn - 1] = powm(powm(p, maxn - 1), mod - 2);
    for (int i = maxn - 2; i >= 0; i--) {
        pinv[i] = (pinv[i + 1] * p) % mod;
    }
    pnorm[0] = 1;
    for (int i = 1; i < maxn; i++) {
        pnorm[i] = (pnorm[i - 1] * p) % mod;
    }
}

int string_hash(char* s) {
    long long hash = 0;
    for (int i = 0; i < strlen(s); i++) {
        hash = hash + (s[i] - 'a' + 1) * pnorm[i];
    }
    return hash % mod;
}

int string_hash(string s) {
    long long hash = 0;
    for (int i = 0; i < s.length(); i++) {
        hash = hash + (s[i] - 'a' + 1) * pnorm[i];
    }
    return hash % mod;
}

bool solve(char * s, int lo, int hi) {
    if (strcmp(s, originala) == 0) {
        return true;
    }

    int hash = string_hash(s);

    if (visited.find(hash)!=visited.end()) {
        return false;
    }
    else {
        visited.insert({hash, 0});
    }

    int length = strlen(s);
    int st = lo, ed = hi;
    for (; st < 47 && s[st] != 'C'; ++st) {
        if (s[st] != originala[st]) {
            return false;
        }
    }
    for (int i = 47 - length + ed; i >= 0 && s[ed] != 'W'; --i, --ed) {
        if (s[ed] != originala[i]) {
            return false;
        }
    }

    char sub[80];
    sub[0] = '\0';
    for (int i = st + 1; i <= ed; ++i) {
        if (s[i] == 'C' || s[i] == 'O' || s[i] == 'W') {
            if (original.find(sub) == -1) return false;
            sub[0] = '\0';
        }
        else {
            strncat(sub, s + i, 1);
        }
    }

    char s1[72];
    for (int j = 0; j < strlen(s); j++) {
        if (s[j] == 'O') {
            for (int i = 0; i < j; i++) {
                if (s[i] == 'C') {
                    for (int k = strlen(s) - 1; k > j; k--) {
                        if (s[k] == 'W') {
                            s1[0] = '\0';
                            strncat(s1, s, i);
                            strncat(s1, s + j + 1, k - j - 1);
                            strncat(s1, s + i + 1, j - i - 1);
                            strncat(s1, s + k + 1, strlen(s) - k - 1);
                            if (solve(s1,st,ed)) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    precompute_p();
    freopen("cryptcow.in", "r", stdin); freopen("cryptcow.out", "w", stdout);
    char s2[76];
    cin.getline(s2, 76);

    substrings.insert({ 0, 0 });
    for (int i = 0; i < original.length(); i++) {
        for (int j = i; j < original.length(); j++) {
            substrings.insert({ string_hash(original.substr(i, j - i + 1)),0 });
        }
    }

    if (!solve(s2,0,strlen(s2)-1)) {
        cout << 0 << ' ' << 0 << '\n';
    }
    else {
        cout << 1 << ' ' << (strlen(s2) - 47) / 3 << '\n';
    }
}