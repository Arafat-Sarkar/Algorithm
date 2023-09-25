#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int ar[n];
	    for(int i=0 ; i<n;i++)
	    {
	        cin>>ar[i];
	    }
	    for(int i=1;i<n;i++)
	    {
	        if(ar[i]<ar[i-1])
	        {
	            cout<<"No"<<endl; 
	           
	        }
            else{
                cout<<"Yes"<<endl;
            }

	    }
	     
	}
	return 0;
}
