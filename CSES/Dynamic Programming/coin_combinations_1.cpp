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
 
int solve(int T, vector<int> &coins, vector<int> &dp) {
	if (T == 0) return 1;
	if (T < 0) return 0;
 
	if (dp[T] != -1) return dp[T];
 
	int take = 0;
 
	for (int i = 0; i < coins.size(); i++) {
		if (coins[i] <= T) {
			take += solve(T - coins[i], coins, dp);
			take %= MOD;
		}
	}
 
	return dp[T] = take;
}
 
int main() {
    fast_io;
 
    int n, T; cin >> n >> T;
 
    vector<int> coins(n), dp(T + 1, -1);
 
    for (int i = 0; i < n; i++) cin >> coins[i];
 
    int ans = solve(T, coins, dp);
 
	cout << ans;
 
    return 0;
}
