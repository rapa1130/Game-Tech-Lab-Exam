#include<iostream>
using namespace std;

class First{
    public:
        virtual void Print(){
            cout<<"First"<<endl;
        }
};

class Second : public First{
    public:
        void Print(){
            cout<<"Secnod"<<endl;
        }
};

class Third : public Second{
    public:
        void Print(){
            cout<<"Third"<<endl;
        }
};

int main(){
    Third third;
    First& first = third;
    Second& second = third;

    first.Print();
    second.Print();
    third.Print();
}