#include<iostream>
#include <cstdint>
#include <iostream>
#include <limits>
#include <list>
#include <memory>

class Test{
    private:
        Test(){};
        static Test* instance;
    public:
        static Test* getinstance(){
            if(instance == nullptr){
                instance = new Test();
                return instance;
            }
            else{
                return instance;
            }
        }
        void returnval(){
                std::cout << "Inside retun val"<< std::endl;
        }
};

Test* Test ::instance = NULL;

int main(){
    Test* x = Test::getinstance();
    x->returnval();
    return 0;
}

