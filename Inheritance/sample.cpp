#include <iostream>
using namespace std;

class Parent
{
public:
	void pPublicMem();
protected:
	void pProtectedMem();
private:
	void pPrivateMem();
friend class Child3;	//friend class
};

void Parent::pPublicMem()
{
	cout << "This is a public member of class Parent."<<endl;
}

void Parent::pProtectedMem()
{
	cout << "This is a protected member of class Parent."<<endl;
}

void Parent::pPrivateMem()
{
	cout << "This is a private member of class Parent."<<endl;
}

class Child1 : public Parent
{
public:
	void ch1CallingPublicMem()
	{
		pPublicMem();
		cout << "Public member of Parent is called from first Child." << endl;
	}
	void ch1CallingProtectedMem()
	{
		pProtectedMem();
		cout << "Protected member of Parent is called from first Child." << endl;
	}
	void ch1CallingPrivateMem()
	{
		//pPrivateMem();	returns error because private member of parent is not accessible.
	}
};

//hierarchical inheritance : more than one sub class inherits from a superclass.
class Child2 : protected Parent
{
public:
	void ch2CallingPublicMem()
	{
		pPublicMem();
		cout << "Public member of Parent is called from second Child." << endl;
	}
	void ch2CallingProtectedMem()
	{
		pProtectedMem();
		cout << "Protected member of Parent is called from second Child." << endl;
	}
};

class Child3 : private Parent
{
public:
	void ch3CallingPublicMem()
	{
		pPublicMem();
		cout << "Public member of Parent is called from third Child." << endl;
	}
	void ch3CallingProtectedMem()
	{
		pProtectedMem();
		cout << "Protected member of Parent is called from third Child." << endl;
	}
	void ch3CallingPrivateMem()
	{
		pPrivateMem();		//private member is accessible because because this sub class is friend of the super class.
		cout << "Private member of Parent is called from third Child." << endl;
	}
};

class Child4 : public Child3	//multilevel inheritance : a sub class inherits from a class which has inherited from another super class
{
	void ch4CallingPublicMem()
	{
		//pPublicMem(); returns error because although this member is public in Parent class but 
						//the inheritance mode is private in Child3 and it's access modifier has changed to private.
	}
};

int main()
{
	Child1 c1;
	Child2 c2;
	Child3 c3;

	c1.pPublicMem();
	//c1.pProtectedMem();	returns error because of hierarchy. 
						   //The protected member of parent class can be called only in the child class not out of it.
	//c1.pPrivateMem();		returns error because private member of parent class can not be accessible in child class.
	c1.ch1CallingPublicMem();
	c1.ch1CallingProtectedMem();


	//c2.pPublicMem();		returns error because mode of inheritance of Child2 is protected so 
						   //the public members of parent will be protected in child class and can be accessible only inner the class.
	c2.ch2CallingPublicMem();
	c2.ch2CallingProtectedMem();


	//c3.pPublicMem();		returns error because mode of inheritance of Child3 is private so 
						   //the public members of parent will be private in child class and can be accessible only inner the class.
	
	c3.ch3CallingPublicMem();
	c3.ch3CallingProtectedMem();
	c3.ch3CallingPrivateMem();
	
}
