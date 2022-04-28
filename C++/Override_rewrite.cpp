#include <iostream>

class A{
    public:
        virtual void func1(){ std::cout << "A" << std::endl; };
        void func2(){ std::cout << "A" << std::endl; };
};

class B : public A{
    public:
        void func1() override { std::cout << "B" << std::endl; };  //override
        void func2(){ std::cout << "B" << std::endl; };   // rewrite
};

int main(){
    A* a = new B();
    a->func1();   //B
    a->func2();   //A
    B* b = new B();  //B
    b->func1();   //B
    b->func2();

    return 0;
}