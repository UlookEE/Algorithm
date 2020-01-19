#include<iostream>
using namespace std;

int arr[1001];

void quick_sort(int left, int right){
    int pivot = arr[(left + right)/2];
    int i = left; int j = right;
    while(i<=j){
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i<=j){
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if(left<j)
        quick_sort(left, j);
    if(right > i)
        quick_sort(i,right);
}
int main(){
    int time = 0;
    int N; cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    quick_sort(0,N-1);
    int cost = 0;
    for(int i=0; i<N; i++){
        time +=arr[i];
        cost+=time;
    }
    cout<<cost<<endl;
}
