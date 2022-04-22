#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

void tyr_sqrt(int n)
{	
	if(n<0) cout << "no square root" << endl;
	else cout << "sqrt(" << n << ") = " <<sqrt(n) << endl;
}

int main()
try{

	cout << "sizeof:\n";
	cout << "char:\t\t" << sizeof(char) << endl;
	cout << "short:\t\t" << sizeof(short) << endl;
	cout << "int:\t\t" << sizeof(int) << endl;
	cout << "long:\t\t" << sizeof(long) << endl;
	cout << "float:\t\t" << sizeof(float) << endl;
	cout << "double:\t\t" << sizeof(double) << endl;
	cout << "int*:\t\t" << sizeof(int*) << endl;
	cout << "double*:\t" << sizeof(double*) << endl;

	cout << "\nMatrix sizes:\n";
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10,10);
	Matrix<int, 3> e(10,10,10);

	cout << "1D int, 10 elem\t\t\t" << sizeof(a) <<'\n';
	cout << "1D int, 100 elem\t\t" << sizeof(b) <<'\n';
	cout << "1D double, 10 elem\t\t" << sizeof(c) <<'\n';
	cout << "2D int, 10*10 elem\t\t" << sizeof(d) <<'\n';
	cout << "3D int, 10*10*10 elem\t\t" << sizeof(e) <<'\n';

	cout << "\nNumber of elements: \n";
	cout << "a:\t" << a.size() << "\n";
	cout << "b:\t" << b.size() << "\n";
	cout << "c:\t" << c.size() << "\n";
	cout << "d:\t" << d.size() << "\n";
	cout << "e:\t" << e.size() << "\n";

	cout << "\nEnter ints for sqrt: " <<endl;
	int n = 0;
	while(cin >> n)
	{
		tyr_sqrt(n);
	}

	cin.clear();
	cin.ignore();

	Matrix<double> dm(10);
	n = 0;
	double x = 0;

	cout << "\nEnter 10 double: " << endl;
	while(cin >> x && n < dm.size())
	{
		dm[n] = x;
		n++;
	}

	cout << dm << endl;

	int m;

	cout << "\nEnter n: ";
	cin >> n;
	cout << "\nEnter m: ";
	cin >> m;

	Matrix<int, 2> mat(n,m);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			mat[i][j]=i*j;
			cout << setw(5) << mat(i,j);
		}
		cout << endl;
	}

    Matrix<complex<double>> mc(10);

    cout << "\nEnter 10 complex numbers (Re,Im): ";
    complex<double> comp;
    for (int i = 0; i<10; ++i) 
    {
        cin >> comp;
        if (!cin) throw runtime_error("problem reading complex number");
        mc[i] = comp;
    }
	cout << mc;


    complex<double> sum;

    for (Index i = 0; i<mc.size(); ++i)
        sum += mc[i];

    cout << "\nSum: " << sum << '\n';

    cout << "\nEnter 6 int: " << endl;

    Matrix<int,2> m2(2,3);
	int temp = 0;

    for (int i = 0; i < 2; ++i)
    {
    	for (int j = 0; j < 3; ++j)
    	{
    		cin >> temp;
    		m2[i][j] = temp;
    	}
    }

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << setw(5) << m2[i][j];
		}
		cout << endl;
	}    

	return 0;
}catch(exception& e){
	cerr << e.what() << endl;
	return 1;
}catch(...){
	cerr << "Exception" << endl;
	return 2;
}