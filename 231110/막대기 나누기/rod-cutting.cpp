#include <iostream>
#include <climits>

using namespace std;
int sell[101];
int value[10001];
int main() {
    int n;
    cin >>n;    
    for(int i =1 ; i<= n; i++){
        cin >> sell[i];
    }
    for(int i =0; i <= n; i++){
        value[i] = INT_MIN; 
    }
    value[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j= 0; j < i; j++){
            value[i] = max(value[i], value[j] + sell[i-j]);
        }
    }
    int ans = INT_MIN;
    for(int i = 0; i <= n; i++){
        ans = max(ans, value[i]);
    }
    cout << ans;
    return 0;
}