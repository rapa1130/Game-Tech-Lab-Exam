#include<iostream>
#include<algorithm>
using namespace std;

class String{
    public:
        //생성자
        String()
            :size(0),capacity(1)
            {
                str = new char[capacity];
            }
        String(const char* charStr) :String(){
            int index = 0;
            while(charStr[index] != '\0'){
                Push_Back(charStr[index]);
                index++;
            }
        }
        String(const String& right){
            str = new char[right.capacity];
            copy_n(right.str,right.size,str);
            size = right.size;
            capacity = right.capacity;
        }
        String operator=(const String& right){
            if(this == &right) return *this;
            str = new char[right.capacity];
            copy_n(right.str,right.size,str);
            capacity = right.capacity;
            size = right.size;
            return *this;
        }
        String operator=(const char* charStr){
            size = 0;
            for(int i=0;charStr[i] !='\0';i++){
                Push_Back(charStr[i]);
            }
            return *this;            
        }

        //기본 메서드
        void Push_Back(const char ch){
            if(size == capacity){
                capacity *= 2;
                char* temp = new char[capacity];
                copy_n(str,size,temp);
                delete[] str;
                str = temp;
            }
            str[size] = ch;
            size++;
        }
        int Size() const{
            return size;
        }
        int Capacity() const{
            return capacity;
        }
        
        //배열 연산자 오버로딩
        char& operator[](int index){
            return str[index];
        }
        const char operator[](int index) const{
            return str[index];
        }
        
        // 입출력 연산자 오버로딩 
        friend ostream& operator<<(ostream& os,const String& str);
        friend istream& operator>>(istream& os,const String& str);

        // + 연산자 오버로딩
        String operator+(const String& right){
            String added;
            delete[] added.str;
            added.capacity = size + right.size + 1;
            added.size = size + right.size;
            added.str = new char[added.capacity];
            copy_n(str, size, added.str);
            copy_n(right.str, right.size, added.str + size);
            return added;
        }
        String operator+(const char* charStr){
            String added(*this);
            for(int i=0;charStr[i] != '\0'; i++){
                added.Push_Back(charStr[i]);
            }
            return added;
        }
        friend String operator+(const char* charStr,const String& objStr);

        // 파괴자
        virtual ~String(){
            delete[] str;
        }
    private:
        char* str;
        int size;
        int capacity;
};
String operator+(const char* charStr,const String& objStr){
    String added(charStr);
    return added + objStr;
}
ostream& operator<<(ostream& os,const String& str){
    for(int i=0;i<str.size;i++){
        os<<str[i];
    }
    return os;
}
istream& operator>>(istream& is,const String& str){
    is>>str;
    return is;
}


int main(){
    String str("Hello");
    String str2(str);
    String str3 = str;
    String str4;
    str4 = str;

    cout<<"str : " << str << endl;
    cout<<"str2 : " << str2 << endl;
    cout<<"str3 : " << str3 << endl;
    cout<<"str4 : " << str4 << endl;

    str = "Bye";
    cout<<"str : " << str << endl;
    cout<<"str2 : " << str2 << endl;
    cout<<"str3 : " << str3 << endl;
    cout<<"str4 : " << str4 << endl;

    String added = str + str2;
    String added2 = str + " Fuck";
    cout<<added<<endl;
    cout<<added2<<endl;
    cout<<"What the " + str;
} 