#include<iostream>
#include<vector>
using namespace std;

class Interface{
    public:
        virtual void Promise1() = 0;
        virtual void Promise2() = 0;
        virtual ~Interface(){
            cout<<"Interface Destucrtor"<<endl;
        }
};

class Implementation1 : public Interface{
    public:
        void Promise1() override{
            cout<<"1 : Promise1()"<<endl;
        }
        void Promise2() override{
            cout<<"1 : Promise2()"<<endl;
        }
        ~Implementation1(){
            cout<<"Implementation1 Destucrtor"<<endl;
        }
};

class Implementation2 : public Interface{
    public:
        void Promise1(){
            cout<<"2 : Promise1()"<<endl;
        }
        void Promise2(){
            cout<<"2 : Promise2()"<<endl;
        }
        ~Implementation2(){
            cout<<"Implementation2 Destucrtor"<<endl;
        }
};

int main(){
    vector<Interface*> inters;
    inters.push_back(new Implementation1());
    inters.push_back(new Implementation2());

    for(const auto& iter : inters){
        iter->Promise1();
        iter->Promise2();
    }
    
    for(auto& iter : inters){
        delete iter;
    }
}