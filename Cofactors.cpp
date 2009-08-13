////////////////////////////////////////////////////////////////////////////////////
//This program will create a positive and a negative cofactors for PPRM expression//
//1. Pass array by eference in this program                                      //
//This is a final submission version                                             //
////////////////////////////////////////////////////////////////////////////////////

char *PositiveCofactor (char *func1, char& var1)
{
	char *func2, *func4;
	func2 = new char [sizeof(func1)];
	func4 = new char [sizeof(func1)];
	int k = 0;
	int j = 0;
	
//cout << "The function is:"<<func1<<endl;
//cout << "The variable is:"<<var1<<endl;

	for (int i=0; func1[i] != '\0'; ++i)
		//cout <<"The location # is: "<<i<<" The variable is: "<<func1[i]<<endl;
	{
		if (func1[i] == var1)
			func2[i] = '1';
		else 
			func2[i] = func1[i];
	}
	//cout << "The PositiveCofactor of the function is: "<<func2<<endl;
	for (; func2[j] != '\0'; ++j)
	{
		if (func2[j] == '@')
			++k;
	}
	//cout << "The number of minterms in the function is: "<<k+1<<endl;
	//cout << "The number characters the function is: "<<j<<endl;
	
        //char func4 [j+1];
	char MyFunc [k+1] [10];
	int n = 0, w = 0;
	
	for (int z=0; func2[z] != '\0';)
	{
         if ((z == 0) && (func2[z+1] == '@') && (func2[z] == '1'))
         {
          MyFunc [n] [w] = func2[z];
          //cout <<"1: "<< MyFunc [n] [w]<<n<<"---"<<w<<endl;
          ++z;
          ++w;
          }
	 else if ((z != 0) && (func2[z] == '@'))
	 {
		 MyFunc [n] [w] = '\0';
		 ++n;
		// cout <<"Number of @ is: "<<n<<endl;
		 w = 0;
	 }
	 else if ((z != 0) && (func2[z] == '1') && (func2[z-1] == '@') && ((func2[z+1] == '@') || (func2[z+1] == '\0')))
         {
          MyFunc [n] [w] = func2[z];
          //cout <<"2: "<< MyFunc [n] [w] <<n<<"---"<<w<<endl;
          ++w;
          ++z;
                }
	 else if (func2[z] != '1')
	 {
	  MyFunc [n] [w] = func2 [z];
          //cout <<"3: "<< MyFunc [n] [w]<<n<<"---"<<w<<endl;
	  ++w;
		// cout <<"Number of minterms are: "<<w<<endl;
		}
	  ++z;
	}
	MyFunc [n] [w] = '\0';
	
	//cout <<"The Positive Cofactor of the function is: ";

        int m = 0;

	for (int i=0; i<k+1; )
	{
	       for (int u=0; MyFunc [i] [u] != '\0'; ++u)
	       {
	         //cout << MyFunc [i] [u];
	         func4 [m] = MyFunc [i] [u];
                 ++m;
		}
		++i;
                if (i < k+1)
                {
                func4 [m] = '@';
                ++m;
                 }
                else 
                ++m;
	}
        func4 [m] = '\0';

        //cout <<"My final Positive Cofactor of the function is: "<<func4<<endl;
        return func4;

}//end function PositiveCofactor

char *NegativeCofactor (char *func3, char& var3)
{
	char *func4, *func5;
	func4 = new char [sizeof(func3)];
	func5 = new char [sizeof(func3)];
	int k = 0;
	int j = 0;
	
	for (int i=0; func3[i] != '\0'; ++i)
		//cout <<"The location # is: "<<i<<" The variable is: "<<func1[i]<<endl;
	{
		if (func3[i] == var3)
			func4[i] = '0';
		else 
			func4[i] = func3[i];
	}
	//cout << "The NegativeCofactor of the function is: "<<func4<<endl;
	
	for (; func4[j] != '\0'; ++j)
	{
		if (func4[j] == '@')
			++k;
	}
	//cout << "The number of minterms in the function is: "<<k+1<<endl;
	//cout << "The number characters the function is: "<<j<<endl;
	
	char MyFunc [k+1] [20];
	int n = 0, w = 0;
	
	for (int z=0; func4 [z] != '\0';)
	{
		if (func4 [z] == '@')
		{
			MyFunc [n] [w] = '\0';
			++n;
			// cout <<"Number of @ is: "<<n<<endl;
			w = 0;
		}
		else 
		{
			MyFunc [n] [w] = func4 [z];
			++w;
			// cout <<"Number of minterms are: "<<w<<endl;
		}
		++z;
	}
	MyFunc [n] [w] = '\0';
	
	char MyFunc1 [k+1] [20];
	char MyFunc2 [k+1] [20];
	
	for (int u = 0; u < k+1; )
	{
		int temp = 0;
                int x = 0, y = 0;
		for (int v = 0; MyFunc [u] [v] != '\0'; )
		{
			if (MyFunc [u] [v] != '0')
			{
			    MyFunc1 [u] [v] = MyFunc [u] [v];
			    //cout <<" HERE1 MyFunc1 is: "<<MyFunc1 [u] [v]<<endl;
			}
			else if (MyFunc [u] [v] == '0')
			{
			    temp = temp + 1;
			    MyFunc1 [u] [v] = MyFunc [u] [v];
			    //cout <<"HERE2 MyFunc1 is: "<<MyFunc1 [u] [v]<<endl;
			}
			++v;
                        MyFunc1 [u] [v] = '\0'; //Magic code for fixing text formating
		}
		
		//cout <<"The value of TEMP is: "<<temp<<endl;

//Above line will determine ZERO minterms
		
		if (temp > 0)
		{
			for (; MyFunc1 [u] [x] != '\0'; )
			{
				MyFunc2 [u] [x] = '0';
				++x;
			}
                        MyFunc2 [u] [x] = '\0';
		}
                
		else if (temp == 0)
		{
			for (; MyFunc1[u] [y] != '\0';)
			{
				MyFunc2 [u] [y] = MyFunc1 [u] [y];
				++y;
			}
			MyFunc2 [u] [y] = '\0';
		}	
		++u;
	}
	
	//cout <<"The Negative Cofactor of the function is: ";
        int m = 0;

	for (int i=0; i<k+1; )
	{
		for (int f=0; MyFunc2 [i] [f] != '\0'; ++f)
		{
                  if (MyFunc2 [i] [f] != '0')
                   {
                     //cout << MyFunc2 [i] [f]; 
                     func5 [m] = MyFunc2 [i] [f]; 
                     ++m;
                   }
		}
		++i;
                if (i < k)
                {
                func5 [m] = '@';
                ++m;
                   }
               // else
                //++m;
	}
        func5 [m] = '\0';

        return func5;
}
