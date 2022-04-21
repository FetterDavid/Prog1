#include "../std_lib_facilities.h"

struct Item
{
	Item(string n,int i, double v): name(n), iid(i), value(v) {}

	string name;
	int iid;
	double value;
};

ostream& operator<<(ostream& is, const vector<Item>& vi)
{
	for(auto& e : vi)
		is << e.name << ", " << e.iid << ", " << e.value << endl; 

	return is;
}

int main()
try{

	vector<Item> vi;

	ifstream mf("data.txt");

	string name = "";
	int iid = 0;
	double value = 0.0;
	while(mf >> name >> iid >> value)
	{
		vi.push_back(Item{name,iid,value});
	}

	cout << "Before sort: \n";
	cout << vi;

	sort(vi.begin(),vi.end(),[](const Item& a, const Item& b){return a.name < b.name;});
	sort(vi.begin(),vi.end(),[](const Item& a, const Item& b){return a.iid < b.iid;});
	sort(vi.begin(),vi.end(),[](const Item& a, const Item& b){return a.value > b.value;});

	cout << "\nAfter sort: \n";
	cout << vi;

	vi.push_back(Item{"horse shoe",99,12.34});
	vi.push_back(Item{"Canon S400", 9988,499.95});

	cout << "\nAfter insert: \n";
	cout << vi;

	vi.erase(find_if(vi.begin(),vi.end(),[](Item it){return it.name == "horse shoe";}));
	vi.erase(find_if(vi.begin(),vi.end(),[](Item it){return it.name == "Canon S400";}));
	vi.erase(find_if(vi.begin(),vi.end(),[](Item it){return it.iid == 1;}));
	vi.erase(find_if(vi.begin(),vi.end(),[](Item it){return it.iid == 2;}));

	cout << "\nAfter erase: \n";
	cout << vi;

	return 0;
}catch(exception& e){
	cerr << e.what() << endl;
	return 1;
}catch(...){
	cerr << "Exception" << endl;
	return 2;
}