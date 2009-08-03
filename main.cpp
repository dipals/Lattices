////////////////////////////////////////////////////////////////////////////////////
//This file implements MAIN function which calls all other functions required     //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

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
char varList[100];
char var;
char var1 = 'R';
int level = 0;
int NodeNumber = 0;
Lattice obj;

cout <<"Enter a RootNode for PPRM Expression: "<<endl;
cin.getline(func, 100);

cout <<"Enter variable: "<<endl;
cin >> var;
cin.get();

obj.CreateLL (func, var1, level, NodeNumber);

cout <<"Enter a variable list: "<<endl;
cin.getline(varList, 100);

cout <<"The variable list is: "<<varList<<endl;

//cout <<"The function you have entered:"<<func<<endl;
//cout <<"The variable you have entered:"<<var<<endl;
//Code for iteratively syntehsize function

//for (int i = 0; varList[i] != '\0'; ++i)
//{
           ++level;
           ++NodeNumber;
	   //binary_tree root(a_node(func, varList[0]));
	   char *x = NegativeCofactor (func, varList[0]);

cout <<"The Negative Cofactor of the function in main: "<< x <<endl;

	   //binary_tree *left = new  binary_tree(a_node(x, '\0'));
	   //root.attach_left(left);
           obj.CreateLL (x, varList[0], level, NodeNumber);

           ++NodeNumber;
	   char *y = PositiveCofactor (func, varList[0]);

cout <<"The Positive Cofactor of the function is in main: "<< y <<endl;

          //binary_tree *right = new binary_tree(a_node(y, '\0'));
          //root.attach_right(right);
          obj.CreateLL (y, varList[0], level, NodeNumber);
          //std::cout << root << std::endl;

   //}//end for

//Display the LL

obj.Printit();
obj.FindHighestLevel(varList);

return 0;
   }

//This file implements CreateLL and PrintLL functions//

void Lattice::CreateLL(char *func, char &v, int &l, int &NN)
{
Lattice obj;
LatticeNode *temp, *temp2;
temp = new LatticeNode;

strcpy (temp->data.func1, func);
temp->data.var = v;
temp->data.level = l;
temp->data.NodeNumber = NN;
temp->next = NULL;

if (head == NULL)
{
   head = temp;
  }

else
   {
        temp2 = head;
        while (temp2->next != NULL)
        {
        temp2 = temp2->next;
        }
        temp2->next = temp;
   }

}

void Lattice::Printit()
{
Lattice obj;
LatticeNode *temp = head;

         while (temp != NULL)
         {
          cout << "The Linked List Node: " << temp->data.func1 << "," << temp->data.var << "," << temp->data.level<< "," << temp->data.NodeNumber << endl;
          temp = temp->next;
            }
}

void Lattice::FindHighestLevel(char *myVars)
{
Lattice obj;
LatticeNode *temp = head;
int num;
        
          while (temp != NULL)
          {
           num = temp->data.level;
           temp = temp->next;
             }

cout <<"The highest level in the Lattice is: "<< num <<endl;
cout <<"The list of varibales is: "<< myVars <<endl;

LatticeNode *temp1 = head;

          while (temp1 != NULL)
          {
               if (temp1->data.level == num)
               { 
                 char *x;
                 x = new char [sizeof (NegativeCofactor (temp1->data.func1, myVars[num]))];
                 strcpy (x, NegativeCofactor (temp1->data.func1, myVars[num]));
                 cout <<"The value of x is: "<< x <<endl;
                 obj.CreateLL (x, myVars[num], (temp1->data.level)+1, (temp1->data.NodeNumber)*2);
                 //char *y = PositiveCofactor (temp1->data.func1, myVars[num]);
                 //obj.CreateLL (y, myVars[num], (temp1->data.level)+1, (temp1->data.NodeNumber)*2+1);
                 temp1 = temp1->next;
                 //cout <<"I am here NCF: "<< x <<endl;
                 //cout <<"I am here PCF: "<< y <<endl;
                   }
                else
                temp1 = temp1->next;
              }
 }







