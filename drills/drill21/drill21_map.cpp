#include "../std_lib_facilities.h"

template<typename F, typename S>
ostream& operator<<(ostream& os , const map<F,S>& m)
{

	for(const auto& e: m)
	{
		os << e.first << " : " << e.second << endl;
	}

	return os;
}

void operator>>(istream& is, map<string,int>& m)
{
	cout << "Enter key(string) and value(int) pairs: " << endl;
	string key = "";
	int value = 0;
	while(is >> key >> value)
		m[key] = value;
}

template<typename Iterator>
int sum(Iterator first, Iterator last)
{
	int s = 0;

	while(first!=last)
	{
		s = s + (*first).second;
		++first;
	}

	return s;
}

template<typename Iter, typename F, typename S>
void copy_msi_to_mis(Iter first, Iter last, map<F,S>& m)
{
	m.clear();

	while(first!=last)
	{
		m[first->second] = first->first;
		++first;
	}
}

int main()
try{
	map<string,int> msi;

	msi["Apple"] = 21;
	msi["Grape"] = 4;
	msi["Banana"] = 15;
	msi["Blacberry"] = 300;
	msi["Cherry"] = 210;
	msi["Coconut"] = 5;
	msi["Lemon"] = 31;
	msi["Orange"] = 20;
	msi["Mango"] = 1;
	msi["Melon"] = 45;
	cout << msi;

	msi.clear();

	cin >> msi;
	cout << msi;
	cout << "Sum: " <<sum(msi.begin(),msi.end()) << endl;

	map<int,string> mis;

	copy_msi_to_mis(msi.begin(), msi.end(), mis);

	cout << mis;

	return 0;
}catch(exception& e){
	cerr << e.what() << endl;
	return 1;
}catch(...){
	cerr << "Exception" << endl;
	return 2;
}