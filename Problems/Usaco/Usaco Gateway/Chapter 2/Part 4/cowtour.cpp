/*
ID: joao.c.1
PROG: cowtour
LANG: C++
*/

#include <cmath>
#include <fstream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>

#include <iostream>

using namespace std;

double pastureDistance(pair<double, double> p1, pair<double, double> p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) +
                (p1.second - p2.second) * (p1.second - p2.second));
}

double getSmallestDiameter(vector<pair<double, double> > pastures,
                           vector<vector<bool> > adjacencyMatrix) {
    int N = adjacencyMatrix.size();

    vector<vector<double> > distances =
        vector<vector<double> >(N, vector<double>(N, -1.0));
    vector<double> longestDistance =
        vector<double>(N, -1.0);
    vector<int> pastureIndex =
        vector<int>(N, 0);
    vector<double> fieldDiameter =
        vector<double>(2, 0.0);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (adjacencyMatrix[i][j] || i == j) {
                double dist = pastureDistance(pastures[i], pastures[j]);
                distances[i][j] = dist;
            }

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            if (distances[i][k] >= 0.0)
                for (int j = 0; j < N; j++)
                    if (distances[k][j] >= 0.0) {
                        double dist = distances[i][k] + distances[k][j];
                        if (distances[i][j] < 0.0 || dist < distances[i][j])
                            distances[i][j] = dist;
                    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (distances[i][j] >= 0.0 && distances[i][j] > longestDistance[i])
                longestDistance[i] = distances[i][j];

    for (int i = 1; i < N; i++)
        if (distances[0][i] < 0.0)
            pastureIndex[i] = 1;

    for (int i = 0; i < N; i++)
        if (longestDistance[i] > fieldDiameter[pastureIndex[i]])
            fieldDiameter[pastureIndex[i]] = longestDistance[i];

    double diameter = -1.0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (distances[i][j] < 0.0) {
                double dist = pastureDistance(pastures[i], pastures[j]);
                double tempDiameter = longestDistance[i] + dist + longestDistance[j];
                if (fieldDiameter[pastureIndex[i]] > tempDiameter)
                    tempDiameter = fieldDiameter[pastureIndex[i]];
                if (fieldDiameter[pastureIndex[j]] > tempDiameter)
                    tempDiameter = fieldDiameter[pastureIndex[j]];
                if (diameter < 0.0 || tempDiameter < diameter)
                    diameter = tempDiameter;
            }
        }
    }

    return diameter;
}

int main() {
    ifstream fin("cowtour.in");
    ofstream fout("cowtour.out");

    int N;
    fin >> N;

    vector<pair<double, double> > pastures;
    vector<vector<bool> > adjacencyMatrix =
        vector<vector<bool> >(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        double x, y;
        fin >> x >> y;
        pastures.push_back(make_pair(x, y));
    }

    for (int i = 0; i < N; i++) {
        string l;
        fin >> l;
        for (int j = 0; j < N; j++) {
            if (l[j] == '1')
                adjacencyMatrix[i][j] = true;
        }
    }

    double diameter = getSmallestDiameter(pastures, adjacencyMatrix);

    fout << fixed << setprecision(6) << diameter << endl;

    return 0;
}
