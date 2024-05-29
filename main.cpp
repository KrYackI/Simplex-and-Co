#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "data.hpp"
#include "simplex_v2.hpp"
using namespace std;


int main()
{
	ifstream in;
	in.open("input.txt");
	Data d;
	d.readUserData(in);
	in.close();

	ofstream out;
	out.open("output.txt");
	gomori::gomoriAlgorithm(&d, out);
	out.close();
	system("pause");
    
}