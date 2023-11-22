#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[101];
int dp[2][101];
int main() {
    cin >> n;
    for(int i =0 ;i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    dp[1][n-1] = arr[n-1];
    dp[0][n-1] = 0;
    for(int i = n-2; i >= 0; i--){
        if(dp[1][i+1] -dp[0][i+1] - arr[i] < dp[0][i+1] - dp[1][i+1] - arr[i]){
            dp[0][i] = dp[0][i+1] + arr[i];
        }
        else{dp[1][i] = dp[1][i+1] + arr[i];}
    }
    cout << min(dp[0][0], dp[1][0]);
    return 0;
}