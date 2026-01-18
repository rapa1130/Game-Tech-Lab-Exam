#include<iostream>
using namespace std;

class IntPlus{
    public:
        IntPlus(int a,int b)
            :a(a),b(b){}
        int operator()(int a, int b){
            return a+b;
        }
    private:
        int a,b;
};

class IntPrint{
    public:
        IntPrint(){}
        void operator()(int i){
            cout<<i<<endl;
        }
    private:
        int i;
};

template<class Func>
void FOR_EACH(int* start,int* last,Func func){
    for(int* ptr = start; ptr != last ; ptr++){
        func(*ptr);
    }
}

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    FOR_EACH(arr,arr+10,IntPrint());
}