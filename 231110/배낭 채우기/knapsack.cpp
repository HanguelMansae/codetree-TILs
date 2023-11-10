#include <iostream>
#include <climits>
using namespace std;

pair<int,int> item[101];
int weightdp[101][10001]; // i번 아이템까지 결정해서 가방에 담긴 총 무게
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
            // 만약 i-1번째에서 j - item[i].first의 무게만큼을 담았을 때의 경우가 존재한다면
            // i번째 아이템을 담았을 때의 가치와 기존에 가지고 있던 값 중 최댓 값으로 설정
            // 그것과 별개로 i-1번째에서 j만큼의 무게만큼을 선택했을 수도 있기 때문에 [i-1][j]가 존재한다면
            //  선택하지 않았을 때의 가치와 지금 가지고 있는 값 중 최댓값으로 설정
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