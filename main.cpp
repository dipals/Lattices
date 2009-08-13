////////////////////////////////////////////////////////////////////////////////////
//This file implements MAIN function which calls all other functions required     //
//    This is a final version for submission                                    //
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
int level = 1;
int NodeNumber = 1;
Lattice obj;

cout <<"Enter a RootNode for PPRM Expression: "<<endl;
cin.getline(func, 100);

//cout <<"Enter variable: "<<endl;
//cin >> var;
//cin.get();

obj.CreateLL (func, var1, level, NodeNumber);

cout <<"Enter a variable list: "<<endl;
cin.getline(varList, 100);

cout <<"The variable list is: "<<varList<<endl;

           ++level;
           ++NodeNumber;
	   //binary_tree root(a_node(func, varList[0]));
	   char *x = NegativeCofactor (func, varList[0]);

//cout <<"The Negative Cofactor of the function in main: "<< x <<endl;

	   //binary_tree *left = new  binary_tree(a_node(x, '\0'));
	   //root.attach_left(left);
           obj.CreateLL (x, varList[0], level, NodeNumber);

           ++NodeNumber;
	   char *y = PositiveCofactor (func, varList[0]);

//cout <<"The Positive Cofactor of the function is in main: "<< y <<endl;

          //binary_tree *right = new binary_tree(a_node(y, '\0'));
          //root.attach_right(right);
          obj.CreateLL (y, varList[0], level, NodeNumber);
          //std::cout << root << std::endl;

//Display the LL

obj.Printit();
for (int i = 2; varList[i] != '\0'; )
{
int num = obj.FindHighestLelvel();
//cout <<"The num is: " << num <<endl;
obj.CreateNewLevel(varList, i);
++i;
   }//end for

return 0;
   }

//This file implements CreateLL and PrintLL functions//

void Lattice::CreateLL(char *func, char &v, int l, int NN)
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

//cout <<"I am here" <<endl;
}

void Lattice::Printit()
{
Lattice obj;
LatticeNode *temp = head;

         while (temp != NULL)
         {
          cout << "Node" <<"[" <<temp->data.NodeNumber<<"]" << temp->data.func1 << "," << temp->data.var << "," << temp->data.level<< "," << temp->data.NodeNumber << endl;
          temp = temp->next;
            }
}

int Lattice::FindHighestLelvel()
{
Lattice obj;
LatticeNode *temp = head;
int num;

          while (temp != NULL)
          {
           num = temp->data.level;
           temp = temp->next;
             }
return num;
}

void Lattice::CreateNewLevel(char *myVars, int i)
{
Lattice obj;
LatticeNode *temp = head;

          while (temp != NULL)
          {
               if (temp->data.level == i)
               { 
                 //cout <<"The node is: "<< temp->data.func1 <<endl;
                 //char *x = new char [sizeof (NegativeCofactor (temp->data.func1))];
                 //cout <<"The string length is: "<< strlen(temp->data.func1) <<endl;
                 char *x =  NegativeCofactor (temp->data.func1, myVars[i]);
                 obj.CreateLL (x, myVars[i], (temp->data.level)+1, (temp->data.NodeNumber)*2);
                 char *y = PositiveCofactor (temp->data.func1, myVars[i]);
                 obj.CreateLL (y, myVars[i], (temp->data.level)+1, (temp->data.NodeNumber)*2+1);
                 //cout <<"I am here NCF: "<< x <<endl;
                 //cout <<"I am here PCF: "<< y <<endl;
                 temp = temp->next;
                   }
                else
                 temp = temp->next;
                
            }
            obj.Printit();
 }
