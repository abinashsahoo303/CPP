#include<iostream>
#include <cstdint>
#include <iostream>
#include <limits>
#include <list>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

//Abstract method
class Observer{
    public:
        virtual void update(int number) = 0;
};

//Abstract method
class Subject{
    public:
        virtual void registerObserver(Observer *obj) = 0;
        virtual void removeObserver(Observer *obj) = 0;
        virtual void notify() = 0;
};

class UpdateData : public Subject{
    std::vector<Observer *> objs;

    int val = 0;
    int anotehrval=0;
    public:
        void registerObserver(Observer *obj) override{
            objs.push_back(obj);
        }
        void removeObserver(Observer *obj) override{
            auto iterator = std::find(objs.begin(), objs.end(), obj);
            if(iterator != objs.end()){
                objs.erase(iterator);
            }
        }
        void notify() override{
        for(Observer *temp : objs){
            temp->update(val);
        }
        }
        void setVal(int temp,int temp2){
            this->val = temp;
            this->anotehrval = temp2;
            notify();
        }

        void printval(){
            cout <<" Values are : "<< val << "\t" << anotehrval << std::endl;
        }
};


//Subscribers to be registered with the Subject
class Subscribers : public Observer{

    public:
    int id;
    Subscribers(int id){
        this->id = id;
    }
    virtual void update(int val) override{
        std::cout << "Client (" << id << ") Data : \t" << val << std::endl;
    }
};


int main(){

    UpdateData upobj;

    Subscribers one(1), two(2);
    cout << "Client : "<< one.id << std::endl;
    cout << "Client : "<< two.id << std::endl;
    int val,val2;
    upobj.registerObserver(&one);
    upobj.registerObserver(&two);

    cout << "ANy update needed in val, Please enter" << std::endl;
    cin >> val;
    cout << "ANy update needed in anotherval, Please enter" << std::endl;
    cin >> val2;
    upobj.setVal(val,val2);
    upobj.printval();
    

    return 0;
}

