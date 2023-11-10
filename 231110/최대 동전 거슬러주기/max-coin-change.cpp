#include <iostream>
#include <climits>
using namespace std;

int numbers[101];
int dp[10001];
int main() {
    int n,m;
    cin >> n >> m;
    for(int i =0 ;i < n; i++){
        cin >> numbers[i];
    }
    for(int i =0 ; i <=m; i++){
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < n; j++){
            if(i - numbers[j] >= 0 && dp[i-numbers[j]] != INT_MIN){
                dp[i] = max(dp[i], dp[i-numbers[j]] + 1);
            }
        }
    }
    if(dp[m] == INT_MAX){cout << -1;}
    else{cout << dp[m];}
    return 0;
}