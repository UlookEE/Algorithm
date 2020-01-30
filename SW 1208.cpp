#include<iostream>
#include<string.h>
using namespace std;
 
int arr[101];
int input;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int test = 1; test <= 10; test++) {
        register int N; cin >> N;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < 100; i++) {
            cin >> input;
            arr[input]++;
        }
             
        register int left = 1;
        register int right = 100;
        while (true) {
            while (arr[left] == 0)
                left++;
            while (arr[right] == 0)
                right--;
            
            int plus = arr[right] <= arr[left] ? arr[right] : arr[left];
            arr[left + 1] += plus;
            arr[left] -= plus;
            arr[right - 1] += plus;
            arr[right] -= plus;
            N -= plus;
            if (N < 0)
                break;
        }
        cout << '#' << test << ' ' << right - left << '\n';
    }
     
    return 0;
}
