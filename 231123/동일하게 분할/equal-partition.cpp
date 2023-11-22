#include <iostream>
using namespace std;
bool dp[101][1001];
int arr[101];
int main() {
    int n;
    cin >> n;
    int m = 0;
    for(int i =0; i< n; i++){
        cin >> arr[i];
        m += arr[i];
    }
    
    for(int i =0 ; i < n; i++){
        dp[i][arr[i]] = true;
    }
    for(int i = 1;i < n; i++){
        for(int j = 0; j < 1001; j++){
            if(dp[i-1][j] == true){dp[i][j] = true;}
            if(j - arr[i] >= 0 && dp[i-1][j - arr[i]] == true){dp[i][j] = true;}
        }
    }
    if(m %2 != 0){cout << "No";}
    else if(dp[n-1][m/2]){cout << "Yes";}
    else{cout << "No";}
    return 0;
}