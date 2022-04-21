#include "../std_lib_facilities.h"

template<typename T>
ostream& operator<<(ostream& os, const vector<T> v)
{
	for (const auto& e : v)
	{
		os << e << " ";
	}
	os << endl;
	return os;
}

template<typename Iter, typename T>
void my_copy(Iter first, Iter last, vector<T>& v)
{
	while(first != last)
	{
		v.push_back((T) *first);
		++first;
	}
}

template<typename Iter, typename T, typename Predicate >
void my_copy_if(Iter first, Iter last, vector<T>& v, Predicate pred)
{
	while(first != last)
	{
		if(pred(*first))
			v.push_back((T) *first);
		++first;
	}
}

template<typename Iter, typename Iter2>
void prinf_vector_pairs(Iter first, Iter last, Iter2 first2)
{
	while(first != last)
	{
		cout << *first << " - " << *first2 << endl;
		++first;
		++first2;
	}
}

template<typename Iter,typename T>
T my_sum(Iter first, Iter last, T init)
{
	while(first != last)
	{
		init = init + *first;
		++first;
	}

	return init;
}

template<typename Iter,typename T>
T my_avg(Iter first, Iter last, T init)
{
	int o = 0;	

	while(first != last)
	{
		init = init + *first;
		++first;
		++o;
	}

	return init/o;
}

int main()
try{

	vector<double> vd;

	ifstream ifs ("data2.txt");
	double d = 0;
	while(ifs >> d)
		vd.push_back(d);

	cout << "vd: " << endl;
	cout << vd;

	vector<int> vi;
	my_copy(vd.begin(),vd.end(),vi);
	cout << "\nvi: " << endl;
	cout << vi;

	cout << "\nvd - vi: " << endl;
	prinf_vector_pairs(vd.begin(),vd.end(),vi.begin());

	cout << "\nsum(vd): " << endl;
	cout << my_sum(vd.begin(),vd.end(),0.0) << endl;
	
	cout << "\nsum(vd) - sum(vi): " << endl;
	cout << my_sum(vd.begin(),vd.end(),0.0) - my_sum(vi.begin(),vi.end(),0) << endl;

	cout << "\navg(vd): " << endl;
	cout << my_avg(vd.begin(),vd.end(),0.0) << endl;

	vector<double> vd2;

	my_copy_if(vd.begin(),vd.end(),vd2,[vd](double d) 
		{return d > my_avg(vd.begin(),vd.end(),0.0);});
	cout << "\nvd2: " << endl;
	cout << vd2;

	sort(vd.begin(), vd.end());
	cout << "\nvd after sort: " << endl;
	cout << vd;

	return 0;
}catch(exception& e){
	cerr << e.what() << endl;
	return 1;
}catch(...){
	cerr << "Exception" << endl;
	return 2;
}