/*
    g++ drill15class.cpp -o drill15class
*/
#include "../std_lib_facilities.h"

struct Person
{
public:
	Person(){};
	Person(string fn,string ln,int a)
	{
		set_name(fn,ln);
		set_age(a);
	}

	string get_name() const { return first_name+" "+last_name; }
	void set_name(string fn,string ln);

	int get_age() const { return age; }
	void set_age(int a);

private:
	string first_name;
	string last_name;
	int age;
};

void Person::set_name(string fn,string ln) 
{
	vector<char> invalid_chars {';', ':', '"', '[', ']', '*', '&', '^', '%', '$', '#', '@', '!'};

	for (int i = 0; i < fn.length(); ++i)
	{
		for (int j = 0; j < invalid_chars.size(); ++j)
		{
			if(fn[i]==invalid_chars[j]) error("Invalid character in first name!");
		}
	}

	for (int i = 0; i < ln.length(); ++i)
	{
		for (int j = 0; j < invalid_chars.size(); ++j)
		{
			if(ln[i]==invalid_chars[j]) error("Invalid character in last name!");
		}
	}

	first_name = fn; 
	last_name = ln; 
}

void Person::set_age(int a) 
{ 
	if(a < 0 || a > 150) error("Age must between 0 and 150!");
	age = a; 
}

ostream& operator<<(ostream& os, const Person& p)
{
	os << p.get_name() << ": " << p.get_age() << endl;
	return os;
}

void operator>>(istream& is, Person& p)
{
	string first_name;
	string last_name;
	int age;

	cin >> first_name;
	cin >> last_name;
	cin >> age;

	p.set_name(first_name,last_name);
	p.set_age(age);
}

int main()
try{

	/*Person p("Goofy",63);
	cout << p;
	Person p2;

	cout << "Enter a name and an age for p2: \n";
	cin >> p2;
	cout << p2;*/

	vector<Person> persons;

	int n;
	cout << "Enter the number of the person you want to store: ";
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cout << "Enter the name(first and last name) and the age for " << i+1 << ". person: ";
		Person p;
		cin >> p;
		persons.push_back(p);
	}

	for (int i = 0; i < persons.size(); ++i)
	{
		cout << persons[i];
	}

}catch(exception e){
    cerr << "Exception: " << e.what() << '\n';
}catch(...){
    cerr << "Exception!\n";
}