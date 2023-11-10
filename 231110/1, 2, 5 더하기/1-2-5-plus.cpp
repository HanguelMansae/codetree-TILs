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
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    arr[5] = 1;
    
    for(int i =2; i<= n; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k < 3; k++){
                if(j + list[k] == i){arr[i]+= arr[j]; arr[i] %= 10007;}
            }
        }
    }
    cout << arr[n];
    return 0;
}