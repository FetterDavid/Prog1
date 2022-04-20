#include <vector>
#include <iostream>

double* get_from_jack(int* count)
{
	double* jack_array = new double[6];

	for (int i = 0; i < 6; ++i)
	{
		jack_array[i]=i*3;
	}

	*count = 6;

	return jack_array;
}

std::vector<double>* get_from_jill()
{
	std::vector<double>* jill_vector = new std::vector<double>;

	*jill_vector = {100,200,300};

	return jill_vector;
}

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
{
	Iterator high = first;
	for(Iterator p=first; p!=last; ++p)
		if(*p > *high) high = p;

	return high;
}

int main()
{
	int jack_count = 0;
	double* jack_data = get_from_jack(&jack_count);

	std::vector<double>* jill_data = get_from_jill();

	std::cout << "Jack data: ";
	for (int i = 0; i < jack_count; ++i)
	{
		std::cout << jack_data[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Jill data: ";
	for(auto e : *jill_data)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	double* jack_high = high(jack_data,jack_data+jack_count);
	std::cout << "Jack high: " << *jack_high << std::endl;
	double* jill_high = high(&(*jill_data)[0],&(*jill_data)[0]+(*jill_data).size());
	std::cout << "Jill high: " << *jill_high << std::endl;


	return 0;
}