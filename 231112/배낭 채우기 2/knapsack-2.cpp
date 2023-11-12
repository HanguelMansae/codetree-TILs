#include <iostream>
#include <climits>
using namespace std;

int n, m;
pair<int,int> list[101];
int arr[10001];


int main() {
    cin >> n >> m;
    for(int i= 0;i < n ;i++){
        int w, v;
        cin >> w >> v;
        list[i] = {w, v};
    }
    
    for(int i = 0; i <= m; i++){
        for(int j= 0; j < n; j++){
            arr[i] = INT_MIN;
        }
    }
    arr[0] = 0;
    for(int i = 0; i <= m; i++){
        for(int j =0 ; j < n; j++){
            if(i - list[j].first >= 0 && arr[i-list[j].first] != INT_MIN){
                arr[i] = max(arr[i], arr[i-list[j].first] + list[j].second);
            }
        }
    }
    int ans = INT_MIN;
    for(int i =0; i <= m; i++){
        ans = max(ans, arr[i]);
        
    }
    cout << ans;
    return 0;
}