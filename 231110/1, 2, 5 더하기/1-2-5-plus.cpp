#include <iostream>
using namespace std;

int arr[1001];
int list[3] = {1,2,5};
int main() {
    int n;
    cin >> n;
    for(int i =0 ;i <= n; i++){
        arr[i] = 0;
    }
    arr[0] = 1; // 0을 만들 수 있는 방법은 아무것도 더하지 않는다라는 1가지의 방법 존재 && 
    
    //arr[i] = 합이 i가 될 때 만들 수 있는 경우의 갯수
    //=> arr[i]는 i-1,-2,-5를 통해 만들 수 있는 값들에 1,2,5를 더해서 만들어진 값이므로 arr[i-1, -2, -5]들의 합

    for(int i =1; i<= n; i++){    
        for(int j = 0; j < 3; j++){
            if(i - list[j] >= 0){arr[i]+= arr[i - list[j]]; arr[i] %= 10007;}
        }
    }
    cout << arr[n];
    return 0;
}