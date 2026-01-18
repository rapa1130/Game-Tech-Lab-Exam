#include<iostream>
#include<algorithm>
// 정렬 함수에 함수를 골라 쓰는 방식으로 해보자
using namespace std;

bool Compare_Large(int a,int b){
    return a>b;
}
bool Compare_Small(int a,int b){
    return a<b;
}

void SelectionSort(int* arr,int size, bool (*compare)(int,int)){
    for(int i=0; i < size-1; i++){
        int smallestIndex = i;
        for(int j = i+1; j < size; j++){
            if(compare(arr[smallestIndex] ,arr[j])){
                swap(arr[smallestIndex],arr[j]);
            }
        }
    }
}

void PrintArr(int* arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[10]={1,10,2,9,3,7,4,6,5,8};
    PrintArr(arr,10);
    SelectionSort(arr,10,Compare_Large);
    PrintArr(arr,10);
    SelectionSort(arr,10,Compare_Small);
    PrintArr(arr,10);
}