#include<iostream>
#include <fstream>
#include<string>
#include<sstream>
using namespace std;


class Mushteri
{
	static int id;
	string name;
	string hesab_n = "99400000";
	int forid=0;
	double balans=0;

public:
	
	void setName(string name) { this->name = name;}
	string getName() { return name; }
	void setHN(string hesab_n) { this->hesab_n = hesab_n; }
	string getHN(){ return hesab_n; }
	 int getId(){ return forid; }


	void newCustomer(string name)
	{
		
		this->name = name;
		id++;	
		this->forid = id;
		static int h = stoi(this->hesab_n);
		
		 h++;
		this->hesab_n = to_string(h);
		this->balans = GetBalance();
		
		

	}
	string GetAccountNumber() //hesab nomresini qaytaran method
	{
		return hesab_n;
	}
	void setBalance(double balans) { this->balans = balans; }
	double GetBalance() // balansi qaytaran method
	{
		return balans;
	}

	void AddToBalance(double balans) //balansa pul elave etmek ucun method
	{
		this->balans+= balans;

	}
	
	void GetCash(double balans) //balansdan pul cixarmaq ucun method

	{
		this->balans -= balans;
	}
	
};


int Mushteri::id = 0;



class MushteriList
{
	Mushteri* Customers;
	int sum = 0;

	

public:
	void setSum(int sum) { this->sum = sum; }

	int setSum(){ return sum;}

	MushteriList(int size)

	{ 
		Customers = new Mushteri[size];
	}

	void addCustomer(Mushteri add,int size)
	{
		for (int i=size-1; i < size; i++)
		{
			
			
				Customers[i] = add;
				sum++;
			
		}

	}
	
	void showCustomer(int size)
	{

		for (int i = 0; i < size; i++)
		{
			cout << Customers[i].getId() <<"\t"<< Customers[i].getName() << "\t" << Customers[i].getHN() << "\t"<< Customers[i].GetBalance()<<endl;

		}
		
	}
	
	void delCustomer(int id)
	{

		
	}
	~MushteriList() 
	{
		delete[] Customers;
		Customers = nullptr;
	}
};
class Search
{

	

public:

	void searchCustomer()
	{


		
	}

};


int main()
{
	MushteriList list(10);
	Mushteri a;
	a.newCustomer("Anar");
	a.GetBalance();
	a.setBalance(77);
	a.AddToBalance(15);
	a.GetCash(12);
	list.addCustomer(a, a.getId());

	Mushteri b;
	b.newCustomer("Orxan");
	b.GetBalance();
	b.setBalance(12);
	b.AddToBalance(45);
	b.GetCash(5);
	list.addCustomer(b, b.getId());

	Mushteri c;
	c.newCustomer("Veli");
	c.GetBalance();
	c.setBalance(52);
	c.AddToBalance(98);
	c.GetCash(15);
	list.addCustomer(c, c.getId());

	Mushteri d;

	d.newCustomer("Seymur");
	d.GetBalance();
	d.setBalance(56);
	d.AddToBalance(22);
	d.GetCash(56);
	list.addCustomer(d, d.getId());
	

	list.delCustomer(1);

	list.showCustomer(list.setSum());

	
	
	
	
	

}