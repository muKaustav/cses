#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef vector<pii> vpii;
typedef vector<pci> vpci;
typedef vector<psi> vpsi;
typedef map<int, int> mii;
typedef unordered_map<char, int> mci;
typedef unordered_map<string, int> msi;
#define imax INT_MAX
#define imin INT_MIN
const int MOD = 1000000007;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

class TreeNode {
public:
	TreeNode *left, *right;
	int data;

	TreeNode (int val) {
		left = right = NULL;
		data = val;
	}
};

// int solve(int index, int T, vector<int> &coins, vector<vector<int>> &dp) {
// 	if (T == 0) return 1;
// 	if (T < 0 || index < 0) return 0;

// 	if (dp[index][T] != -1) return dp[index][T];

// 	int take = 0;

// 	if (coins[index] <= T) 
// 		take = solve(index, T - coins[index], coins, dp);

// 	int notTake = solve(index - 1, T, coins, dp);

// 	return dp[index][T] = (take + notTake) % MOD;
// }

int main() {
    fast_io;

    int n, T; cin >> n >> T;

    vector<int> coins(n);
    vector<vector<int>> dp(n, vector<int>(T + 1, 0));

    for (int i = 0; i < n; i++) cin >> coins[i];

    for (int i = 0; i < n; i++) dp[i][0] = 1;

    for (int ind = 0; ind < n; ind++) {
    	for (int j = 1; j <= T; j++) {
    		int take = (coins[ind] <= j) ? dp[ind][j - coins[ind]] : 0;

    		int notTake = (ind > 0) ? dp[ind - 1][j] : 0;

    		dp[ind][j] = (take + notTake) % MOD;
    	}
    }

    int ans = dp[n - 1][T];

	cout << ans;

    return 0;
}









