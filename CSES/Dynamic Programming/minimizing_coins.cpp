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
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN

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

// int solve(int index, int target, vector<int> &arr, vector<vector<int>> &dp) {
// 	if (index == 0) {
// 		if (target % arr[index] == 0) 
// 			return (target / arr[index]);

// 		return 1e9;
// 	} 

// 	if (dp[index][target] != -1) return dp[index][target];

// 	int take = INT_MAX;

// 	if (arr[index] <= target) 
// 		take = 1 + solve(index, target - arr[index], arr, dp);

// 	int notTake = solve(index - 1, target, arr, dp);

// 	return dp[index][target] = min(take, notTake);
// }

int main() {
    fast_io;

    int n, target; 
    cin >> n >> target;

    vector<int> coins(n);
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for (int i = 0; i < n; i++) cin >> coins[i];

    for (int T = 0; T <= target; T++) {
    	if (T % coins[0] == 0) dp[0][T] = T / coins[0];
    	else dp[0][T] = 1e9;
    }

    for (int ind = 1; ind < n; ind++) {
    	for (int T = 0; T <= target; T++) {
    		int take = INT_MAX;

			if (coins[ind] <= T) 
				take = 1 + dp[ind][T - coins[ind]];

			int notTake = dp[ind - 1][T];

			dp[ind][T] = min(take, notTake);
    	}
    }

	int ans = dp[n - 1][target];
	
	if (ans == 1e9) cout << -1;
	else cout << ans;

    return 0;
}