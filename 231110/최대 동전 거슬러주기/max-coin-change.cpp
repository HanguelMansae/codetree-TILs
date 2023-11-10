#include <iostream>
#include <climits>
using namespace std;

int numbers[101]; // 동전 종류를 저장할 배열
int dp[10001]; // m원까지 최대 동전 사용 개수를 저장할 배열
int main() {
    int n,m; // 갯수와 금액
    cin >> n >> m;
    for(int i =0 ;i < n; i++){
        cin >> numbers[i];
    }
    for(int i =0 ; i <=m; i++){
        dp[i] = INT_MIN; // i원을 만들어 줄 수 없을 경우를 대비해 INT_MIN으로 구분해둠
    }
    dp[0] = 0; // 초기값 초기화
    for(int i = 1; i <= m; i++){ //1원부터 m원까지
        for(int j = 0; j < n; j++){ // 동전들을 탐색하면서
            // 만약 i원에서 특정 동전을 추가하기 전 금액을 만들 수 있다면
            if(i - numbers[j] >= 0 && dp[i-numbers[j]] != INT_MIN){
                dp[i] = max(dp[i], dp[i-numbers[j]] + 1);
                // i원에서 최대 동전 개수는 지금까지의 갯수와 i - 특정 동전의 갯수 + 1 중 최댓값
            }
        }
    }
    if(dp[m] == INT_MIN){cout << -1;}
    else{cout << dp[m];}
    return 0;
}