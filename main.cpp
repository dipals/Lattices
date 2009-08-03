////////////////////////////////////////////////////////////////////////////////////
//This file implements MAIN function which calls all other functions required//
//
////////////////////////////////////////////////////////////////////////////////////

//Callses for Lattice is in file Lattice.h

//#include Lattice.h
#include <iostream>
#include <string>
#include <fstream>

#include "binary_tree.h"

char *PositiveCofactor (char *func1, char& var1);
char *NegativeCofactor (char *func3, char& var3);

using namespace std;

int main ()
   {
char func[100];
char TempFunc[100];
char var;

cout <<"Enter a RootNode for PPRM Expression"<<endl;
cin.getline(func, 100);

cout <<"Enter a variable"<<endl;
           cin >> var;
           cin.get();

//cout <<"The function you have entered:"<<func<<endl;
//cout <<"The variable you have entered:"<<var<<endl;

	   binary_tree root(a_node(func, var));

	   char *x = NegativeCofactor (func, var);

	   // cout <<"The Positive Cofactor of the function in main: "<<PositiveCofactor (func, var)<<endl;
cout <<"The Negative Cofactor of the function in main: "<< x <<endl;

	   binary_tree left(a_node(x, '\0'));
	   root.attach_left(&left);
	   x = PositiveCofactor (func, var);
	   // cout <<"The Nagative Cofactor of the function is in main: "<<NegativeCofactor (func, var)<<endl;
cout <<"The Positive Cofactor of the function is in main: "<< x<<endl;

          binary_tree right(a_node(x, '\0'));
          root.attach_right(&right);
          std::cout << root << std::endl;

return 0;
   }
