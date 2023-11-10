#include <iostream>
#include <climits>
using namespace std;

pair<int,int> item[101];
int weightdp[101][10001];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i =1;i <= n; i++){
        int w, v;
        cin >> w >> v;
        item[i] = {w, v};
    }
    for(int i =0;i <= n; i++){
        for(int j = 0; j <= m; j++){
            weightdp[i][j] = INT_MIN;
        }
    }
    weightdp[0][0] = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(weightdp[i-1][j] != INT_MIN){weightdp[i][j] = max(weightdp[i][j], weightdp[i-1][j]);}
            if(j - item[i].first >= 0 && weightdp[i-1][j-item[i].first] != INT_MIN){
                weightdp[i][j] = max(weightdp[i][j], weightdp[i-1][j - item[i].first] + item[i].second);
            }
         
        }
    }
    int ans = INT_MIN;
    for(int i = 1; i <= n; i++){
        for(int j =0 ; j <= m; j++){
            ans = max(ans, weightdp[i][j]);
        }
        
    }
    cout << ans;
    return 0;
}