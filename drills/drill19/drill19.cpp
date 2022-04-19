#include "../std_lib_facilities.h"

template<typename T>
struct S
{
public:
	S(T t): val(t) {};
	T& get();
	const T& get() const;
	void set(T t);
	void operator=(const T& t);
	void read_val();
private:
	T val;
};

template<typename T> T& S<T>::get(){return val;}
template<typename T> const T& S<T>::get() const {return val;}

template<typename T> void S<T>::set(T t){val=t;}

template<typename T> void S<T>::operator=(const T& t){val=t;}

template<typename T> void S<T>::read_val(){cin >> val;}

ostream& operator<<(ostream& os, const vector<int>& v)
{
	os << '{';

	for (int i = 0; i < v.size(); ++i)
	{
		os << v[i];
		if(i<v.size()-1)os << ',';
		os<< ' ';
	}

	os << '}' << endl;

	return os;
}

void operator>>(istream& is, vector<int>& v)
{
	char format;

	while(is >> format)
	{
		int n;
		if(cin >> n) v.push_back(n);
		else return;
	}
}

int main()
try{
	S<int> s_int(1);
	S<char> s_char('a');
	S<double> s_double(3.14);
	S<string> s_string("alma");
	S<vector<int>> s_vector(vector<int> {10,20,40});

	cout << "int: " << s_int.get() << endl;
	cout << "char: " << s_char.get() << endl;
	cout << "double: " << s_double.get() << endl;
	cout << "string: " << s_string.get() << endl;
	cout<< "vector<int>: "<< s_vector.get() << endl;	

	/*cout<< "Enter an int value: ";
	s_int.read_val();
	cout<< "Enter a char value: ";
	s_char.read_val();
	cout<< "Enter a double value: ";
	s_double.read_val();
	cout<< "Enter a string value: ";
	s_string.read_val();*/
	cout<< "Enter a int valus in {int, int, int} format: ";
	cin >> s_vector.get();

	/*cout << "int: " << s_int.get() << endl;
	cout << "char: " << s_char.get() << endl;
	cout << "double: " << s_double.get() << endl;
	cout << "string: " << s_string.get() << endl;*/
	cout<< "vector<int>: "<< s_vector.get() << endl;

}catch(exception& e){
	cerr << e.what() << endl;
	return 1;
}catch(...){
	cerr << "Exception" << endl;
	return 2;
}