#include <iostream>
#include <climits>
using namespace std;

int numbers[101];
int dp[10001];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i =0; i <= m; i++){
        dp[i] = INT_MIN;
    }
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    dp[0] = 0;
    for(int i =0;i < n; i++){
        for(int j= m;j >= 0; j--){
            if(j - numbers[i] >= 0 && dp[j-numbers[i]] != INT_MIN){
                dp[j] = 0;

            }
        }
    }
    /*
    for(int i =0 ;i < m; i++){
        cout << dp[i] << " ";
    }cout << endl;
    */
    cout << (dp[m] == 0 ? "Yes" : "No");
    return 0;
}