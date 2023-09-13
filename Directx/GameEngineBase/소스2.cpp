#include <iostream>
#include <typeinfo>

class Base {
public:
	virtual void adex() {}
};

class Derived : public Base {};

class Base2 {

};

class A {
public:
	virtual void vf() {}
};
class B : public A {};
class C : public A {};
class D : public A {};



using namespace std;
int main() {
	Derived* pd = new Derived;
	Base* pb = pd;
	Base2* pdd = new Base2;
	cout << typeid(pdd).name() << endl;
	cout << typeid(*pdd).name() << endl;

	cout << typeid(pb).name() << endl;   //prints "class Base *"
	cout << typeid(*pb).name() << endl;   //prints "class Derived"
	cout << typeid(pd).name() << endl;   //prints "class Derived *"
	cout << typeid(*pd).name() << endl;   //prints "class Derived"
	delete pd;

	B* b = new B;
	C* c = new C;
	D* d = new D;
	A* a[] = { b, c, d };

	cout << typeid(*a[0]).name() << endl;
	cout << typeid(*a[1]).name() << endl;
	cout << typeid(*a[2]).name() << endl;

	cout << typeid(a[0]).name() << endl;
	cout << typeid(a[1]).name() << endl;
	cout << typeid(a[2]).name() << endl;
}