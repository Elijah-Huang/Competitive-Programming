#include<bits/stdc++.h>
using namespace std;

const int maxn = 501;
const int mod = 998244353;
int n, k; 
long long ans = 0;

int dp[maxn][maxn][2], dp2[maxn][maxn][2]; // mx || curr len | curr end
long long tot[maxn], ptot[maxn];

int main() 
{
	cin >> n >> k;

	dp[1][1][0] = dp[1][1][1] = 1;

	for (int pos = 0; pos < n-1; pos++) 
	{
		memset(dp2, 0, sizeof(dp2));

		for (int i = 1; i <= pos+1; i++)
		{
			for (int j = 1; j <= pos+1; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					dp2[max(i, j + 1)][j + 1][k] = (dp2[max(i, j + 1)][j + 1][k] + dp[i][j][k]) % mod;
					dp2[i][1][k ^ 1] = (dp2[i][1][k ^ 1] + dp[i][j][k]) % mod;
				}
			}
		}

		memcpy(dp, dp2, sizeof(dp));
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				tot[i] = (tot[i] + dp[i][j][k]) % mod;
			}
		}
	}

	for (int i = 1; i <= n; i++) 
	{
		ptot[i] = (tot[i] + ptot[i - 1]) % mod;
	}

	for (int i = 1; i <= n; i++) 
	{
		int j = (k - 1) / i;
		j = min(n, j);

		ans = (ans + tot[i] * ptot[j]) % mod;
	}

	cout << ans * 499122177 % mod;
}