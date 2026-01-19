#include<iostream>
using namespace std;

class Base{
    public:
        Base() :base(0) {}
        Base(int b):base(b){}
        virtual void Print(){
            cout << "Base : " << base << endl;
        }
    private:
        int base;
};

class Derived : public Base{
    public:
        Derived() : Base(0),derived(0){}
        Derived(int b,int d) : Base(b),derived(d){}
        void Print() override{
            Base::Print();
            cout << "Derived : " << derived << endl;
        }
    private:
        int derived;
};

int main(){
    Derived de1;
    Derived de2(1,2);
    de1.Print();
    de2.Print();
}