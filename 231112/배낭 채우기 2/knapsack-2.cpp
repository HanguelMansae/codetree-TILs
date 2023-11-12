#include <iostream>
#include <climits>
using namespace std;

int n, m;
pair<int,int> list[101]; // 아이템의 무게와 가치를 담을 배열
int arr[10001]; // 무게별로 최대 가치를 담을 배열 arr[j] => j만큼 무게를 담았을 때 최대 가치


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
                //만약 해당 아이템의 가치를 담기 전의 무게가 있다면 => 그 무게로 담을 수 있는게 있다면, 거기다가 아이템의 가치만큼 더한걸 현재 값이랑 비교해서 넣음
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