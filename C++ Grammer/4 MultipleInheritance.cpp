#include<iostream>
using namespace std;

//다중상속( 일반, virtual)
class Animal{
    public:
        void Walk(){
            cout<<"Animal Walk"<<endl;
        }

        // Polymorphysm Example (virtual vs not virtual)
        virtual void Hunt(){
            cout<<"Animal Hunt"<<endl;
        };
        void voice(){
            cout<<"Animal voice"<<endl;
        }
};

class FlyingAnimal : virtual public Animal{
    public:
        void Fly(){
            cout<<"Walk"<<endl;
        }
        void voice(){
            cout<<"Flying Animal voice"<<endl;
        }
};

class MammalAnimal : virtual public Animal{
    public:
        void Nurse(){
            cout<<"Nurse"<<endl;
        }
        void voice(){
            cout<<"Mammal Animal voice"<<endl;
        }
};

class Bird : public FlyingAnimal, public MammalAnimal {
    public:
        void Hunt() override {
            cout<<"Bird Hunt"<<endl;
        }
        void voice(){
            cout<<"Bird voice"<<endl;
        }
};

int main(){
    
    Animal* am = new Bird();
    am->voice();
    am->Hunt();

    Bird bird;
    bird.Walk();
    bird.Hunt();
    bird.voice();

    
}

