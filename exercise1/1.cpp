#include<iostream>
using namespace std;
/* 这是华峰测控的C++关于类的题，自己敲一遍试试，同时通过vscode管理版本更舒服 */
class A {
    public:
    A():m_num(3){m_num = num1();}
    int num0() const {return 1;}
    virtual int num1() const {return 1;}
    int num() const {return m_num;}
    private:
    int m_num;
};
class B : public A {
    public:
    int num0()const {return 2;}
    virtual int num1() const {return 2;}
};
int main()
{
    A a; B b;
    A* pa = &a; B* pb = &b; A* p = pb;
    cout<<pa->num0()<<endl<<pb->num0()<<endl<<p->num0()<<endl;

    cout<<pa->num1()<<endl<<pb->num1()<<endl<<p->num1()<<endl;

    cout<<pa->num()<<endl<<pb->num()<<endl<<p->num()<<endl;
    system("pause");
    return 0;
}