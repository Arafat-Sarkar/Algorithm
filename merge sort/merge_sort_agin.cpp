#include<bits/stdc++.h>
using namespace std;
void merge(int ar[], int m,int l,int r)
{
    int left_size = m-l+1;
    int right_size = r-m;
    int L[left_size], R[right_size];
    int k=0;
    for(int i =l; i<=m; i++)
    {
        L[k]= ar[i];
        k++;
    }
    k = 0;
    for(int i= m+1; i<=r;i++)
    {
        R[k]= ar[i];
        k++;


    }
    int i= 0, j=0;
    int current = l;
    while(i<left_size && j<right_size)
    {
        if(L[i]<= R[j])
        {
            ar[current]= L[i];
            i++;

        }
        else
        {
            ar[current] = R[j];
            j++;


        }
        current++;
    }
    while(i<left_size)
    {
        ar[current] = L[i];
        i++;
        current++;
    }
    while(j<right_size)
    {
        ar[current] = R[j];
        j++;
        current ++;
    }

}
 void merge_sort(int ar[], int l,int r)
 {
     
     if(l<r)
     {
        int mid = (l+r)/2;
        merge_sort(ar,l,mid);
        merge_sort(ar, mid+1, r);
        merge(ar, l,mid,r);
     }
 }
int main()
{
   int n;
   cin>>n;
   int ar[n];
   for(int i=0; i<n;i++)
   {
    cin>>ar[i];
   } 

   merge_sort(ar,0,n-1);

    for(int i=0;i<n;i++)
   {
    cout<<ar[i]<<" ";
   }
    return 0;
}