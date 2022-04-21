#include "../std_lib_facilities.h"

struct Item
{
	Item(string n,int i, double v): name(n), iid(i), value(v) {}

	string name;
	int iid;
	double value;
};

ostream& operator<<(ostream& is, const list<Item>& li)
{
	for(auto& e : li)
		is << e.name << ", " << e.iid << ", " << e.value << endl; 

	return is;
}

int main()
try{

	list<Item> li;

	ifstream mf("data.txt");

	string name = "";
	int iid = 0;
	double value = 0.0;
	while(mf >> name >> iid >> value)
	{
		li.push_back(Item{name,iid,value});
	}

	cout << "Before sort: \n";
	cout << li;

	li.sort([](const Item& a, const Item& b){return a.name < b.name;});
	li.sort([](const Item& a, const Item& b){return a.iid < b.iid;});
	li.sort([](const Item& a, const Item& b){return a.value > b.value;});

	cout << "\nAfter sort: \n";
	cout << li;

	li.push_back(Item{"horse shoe",99,12.34});
	li.push_back(Item{"Canon S400", 9988,499.95});

	cout << "\nAfter insert: \n";
	cout << li;

	li.erase(find_if(li.begin(),li.end(),[](Item it){return it.name == "horse shoe";}));
	li.erase(find_if(li.begin(),li.end(),[](Item it){return it.name == "Canon S400";}));
	li.erase(find_if(li.begin(),li.end(),[](Item it){return it.iid == 1;}));
	li.erase(find_if(li.begin(),li.end(),[](Item it){return it.iid == 2;}));

	cout << "\nAfter erase: \n";
	cout << li;

	return 0;
}catch(exception& e){
	cerr << e.what() << endl;
	return 1;
}catch(...){
	cerr << "Exception" << endl;
	return 2;
}