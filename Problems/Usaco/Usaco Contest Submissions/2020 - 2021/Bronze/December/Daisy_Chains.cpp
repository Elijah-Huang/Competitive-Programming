#include<bits/stdc++.h>
using namespace std;

int N = 0;
vector<int> flowers;

int main()
{
    cin >> N;

    int temp = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        flowers.push_back(temp);
    }

    long long count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            int sum = 0;
            for (int k = 0; k <= j - i; k++)
            {
                sum = sum + flowers[i + k];
            }
            if (sum % (j - i + 1) == 0 && find(flowers.begin() + i, flowers.begin() + j+1, sum / (j - i + 1)) != flowers.begin() + j+1)
            {
                count++;
            }
        }
    }
    
    cout << count;
}