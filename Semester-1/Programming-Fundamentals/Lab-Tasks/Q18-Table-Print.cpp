//Print/Calculate table of entered number

#include<iostream>
using namespace std;

int main()
{
  int num;
  cout<<"Enter number:"<<endl;
  cin>>num;
  cout<<"Table of:"<<num<<endl;
  
  for(int i=1;i<=10;i++)
  {
cout<<num<<"x"<<i<<"="<<num*i<<endl;
  }
  return 0;
}




