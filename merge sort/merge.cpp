#include<bits/stdc++.h>
using namespace std;
void merge(int ar[],int l, int m,int r)
{
    int left_size = m-l+1;
    int right_zise = r - m;
    int  L[left_size], R[right_zise];
    int k =0;
    for(int i=l; i<=m; i++)
    {
       L[k]= ar[i];
       k++;
    }
    k =0;
    for( int i= m+1;i<=r;i++)
    {
        R[k]= ar[i];
        k++;
    }
    int i=0, j=0;
    int current = l;
    while( i<left_size && j<right_zise)
    {
        if( L[i]<=R[j])
        {
            ar[current]= L[i];
            i++;
           
        }
        else
        {
            ar[current]=R[j];
            j++;
        }
    
        current++;
    
    }
    while(i<left_size)
    {
        ar[current]= L[i];
        i++;
        current++;
    }
    while(j<left_size)
    {
        ar[current]= R[j];
        j++;
        current++;
    }


}
int main()
{
   int n;
   cin>>n;
   int ar[n];
   for( int i=0; i<n;i++)
   {
    cin>>ar[i];
   } 
   merge(ar,0,3,n-1);
   for(int i=0; i<n; i++)
   {
     cout<<ar[i]<<" ";
   }
    return 0;
}