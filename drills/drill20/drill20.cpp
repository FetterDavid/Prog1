#include "../std_lib_facilities.h"

template<typename Iterator>
void print_out(Iterator first,Iterator last)
{
	for(Iterator p = first; p!=last; ++p)
		cout << *p << " ";
	cout << endl;
}

template<typename Iterator>
void increase_by(Iterator first,Iterator last,int incr)
{
	for(Iterator p=first; p!=last; ++p)
	{
		*p=*p+incr;
	}
}

template<typename Iter1, typename Iter2>
void my_copy(Iter1 f1, Iter1 e1, Iter2 f2 )
{
	for (Iter1 p = f1; p != e1; ++p)
	{
		*f2 = *p;
		++f2;
	}
}

int main()
try{
	int a_count=10;

	int a1[a_count] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> v1 = {0,1,2,3,4,5,6,7,8,9};
	list<int> l1 = {0,1,2,3,4,5,6,7,8,9};

	/*int* a2 = a1;
	vector<int> v2 = v1;
	list<int> l2 = l1;*/

	cout << "Array: ";
	print_out(a1,a1+a_count);
	cout << "Vector: ";
	print_out(&v1[0],&v1[0]+v1.size());
	cout << "List: ";
	print_out(l1.begin(),l1.end());
	cout << endl;

	increase_by(a1,a1+a_count,2);
	increase_by(&v1[0],&v1[0]+v1.size(),3);
	increase_by(l1.begin(),l1.end(),5);

	cout << "After increase: " << endl;
	cout << "Array: ";
	print_out(a1,a1+a_count);
	cout << "Vector: ";
	print_out(&v1[0],&v1[0]+v1.size());
	cout << "List: ";
	print_out(l1.begin(),l1.end());
	cout << endl;


	my_copy(a1,a1+a_count,&v1[0]);
	my_copy(l1.begin(),l1.end(),a1);

	cout << "After copy: " << endl;
	cout << "Array: ";
	print_out(a1,a1+a_count);
	cout << "Vector: ";
	print_out(&v1[0],&v1[0]+v1.size());
	cout << "List: ";
	print_out(l1.begin(),l1.end());
	cout << endl;

	auto it = find(&v1[0],&v1[0]+v1.size(),3);
	if(it!=&v1[0]+v1.size())
		cout << "The vector contains the value 3, at " << it - &v1[0] << " position" << endl;
	else cout << "The vector do not contains the value 3." << endl;

	auto it_l = find(l1.begin(),l1.end(),27);
	if(it_l!=l1.end())
	{
		int indx=0;
		for (list<int>::iterator iter = l1.begin(); iter!=it_l; ++iter)
		{
			indx++;
		}
		cout << "The list contains the value 27, at " << indx  << " position" << endl;
	}
	else cout << "The list do not contains the value 27." << endl;

}catch(exception& e){
	cerr << e.what() << endl;
	return 1;
}catch(...){
	cerr << "Exception" << endl;
	return 2;
}