#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class person{
    public:
    string name;
    int age;
    person(){

    }
    person(string n,int a){
        name=n;
        age=a;
    }

    virtual void printname(){
        cout<<"my name is: "<<name<<endl;
    }
    virtual ~person(){
        cout<<"destructor_person\n";
    }
};

class student:public person{
    public:
    int standard;
    student(){}
    student(string n,int a,int c){
        standard=c;
        name=n;
        age=a;
    }
    virtual void printname(){
        cout<<"standard: "<<standard<<endl;
    }
    virtual ~student(){
        cout<<"destructor_student\n";
    }
};

int main(){
    person * s=new student("amit",22,10);
    s->printname();
    delete s;
}