#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define NFENCES_MAX 1005
#define NCOWS_MAX 1005

bool rayHits(long long cx, long long cy,
    long long f1x, long long f1y,
    long long f2x, long long f2y) {
    if ((f1y > cy) ^ (f2y > cy)) {
        return (f1y - f2y < 0) ^ (f2x * (f1y - cy) + f1x * (cy - f2y) > cx * (f1y - f2y));
    }
    else {
        return false;
    }
}

map<pair<int, int>, vector<int> > pointMap;
pair<pair<int, int>, pair<int, int> > fences[NFENCES_MAX];
int cycle[NFENCES_MAX];

char parities[NCOWS_MAX][NFENCES_MAX];

char* parityptrs[NCOWS_MAX];
inline bool ptrcmp(char* a, char* b) {
    return strcmp(a, b) < 0;
}

int main() {
    freopen("crazy.in", "r", stdin);
    freopen("crazy.out", "w", stdout);

    int nFences, nCows;
    scanf("%d", &nFences);
    scanf("%d", &nCows);
    for (int i = 0; i < nFences; i++) {
        pair<int, int> p1, p2;
        scanf("%d", &p1.first);
        scanf("%d", &p1.second);
        scanf("%d", &p2.first);
        scanf("%d", &p2.second);
        pointMap[p1].push_back(i);
        pointMap[p2].push_back(i);
        fences[i] = pair<pair<int, int>, pair<int, int> >(p1, p2);

        cycle[i] = -1;
        memset(parities[i], 0, nCows);
    }
    for (int i = 0; i < nCows; i++) {
        parityptrs[i] = parities[i];
    }

    int nCycles = 0;
    for (int i = 0; i < nFences; i++) {
        if (cycle[i] == -1) {
            int j = i;
            pair<int, int> last = fences[i].first;
            do {
                cycle[j] = nCycles;
                last = fences[j].first == last ? fences[j].second : fences[j].first;
                vector<int> const& v = pointMap[last];
                j = (v[0] == j ? v[1] : v[0]);
            } while (j != i);
            nCycles++;
        }
    }

    for (int i = 0; i < nCows; i++) {
        int cowx, cowy;
        scanf("%d", &cowx);
        scanf("%d", &cowy);
        for (int j = 0; j < nFences; j++) {
            parities[i][cycle[j]] ^= (char)rayHits(cowx, cowy, fences[j].first.first, fences[j].first.second, fences[j].second.first, fences[j].second.second);
        }
        for (int j = 0; j < nCycles; j++) {
            parities[i][j] = parities[i][j] ? '1' : '0';
        }
        parities[i][nCycles] = '\0';
    }

    sort(parityptrs, parityptrs + nCows, ptrcmp);

    int maxans = 0;
    int curcount = 0;
    for (int i = 0; i < nCows; i++) {
        if (i == 0 || strcmp(parityptrs[i], parityptrs[i - 1]) != 0) {
            curcount = 1;
        }
        else {
            curcount++;
        }
        maxans = max(maxans, curcount);
    }
    printf("%d\n", maxans);
}