#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void longsubarrdivik(int arr[],int n,int k)
{
   unordered_map<int,int> um;
   int mod_arr[n],max=0,curr_sum=0;
   for(int i=0;i<n;i++)
   {
   	 curr_sum += arr[i];
   	 mod_arr[i] = (((curr_sum % k)+k)%k);
   }
   for(int i=0;i<n;i++)
   {
   	 if(mod_arr[i] == 0)
   	   max = i+1;
   	 else if(um.find(mod_arr[i]) == um.end())
		um[mod_arr[i]] = i;
     else
	   if(max < (i-um[mod_arr[i]]))	
	     max = i-um[mod_arr[i]];	  
   }
   return max;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	   int n;
	   cin >> n;
	   int arr[n];
	   for(int i=0;i<n;i++)
	      cin >> arr[i];
	    int k;
		cin >> k;
		longsubarrdivik(arr,n,k);	  	
	}
	return 0;
}
