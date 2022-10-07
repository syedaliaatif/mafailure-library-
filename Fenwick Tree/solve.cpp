#include "solve.h"
signed main()
{
	cout<<"Enter the size of the array\n";
	int n; 
	cin>>n; 
	vector<int> a(n); 
	cout<<"Enter the values for the array\n"; 
	for(int i=0;i<n;i++)cin>>a[i]; 
	int q; 
	cout<<"Enter the number of tests that you want to run\n"; 
	cin>>q; 
	FenwickTree<int> ft(n+1);  
	for(int i=0;i<n;i++)
	{
		ft.update_cnt(i+1,a[i]); 
	}
	for(int i=0;i<q;i++)
	{
		int l,r; 
		cin>>l>>r; 
		cout<<ft.query_cnt(r,0)-ft.query_cnt(l-1,0)<<endl;  
		
	}
	
	
}
