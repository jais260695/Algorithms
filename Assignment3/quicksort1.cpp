#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
long long int partition(vector<int>& v,int s, int e,long long int* count){
     int i=s+1,pivot=v[s],temp;
     int j;
    for(j=s+1;j<=e;j++){
    	if(v[j]>=pivot){
    	    //do nothing
    	}
        if(v[j]<pivot){
         
            temp=v[i];
            v[i]=v[j];
            v[j]=temp;
               i++;
             
        }
    }
    temp=v[i-1];
    v[i-1]=pivot;
    v[s]=temp;
    
    return i-1;
}

void quicksort(vector<int>& v,int s, int e,long long int* count){
    if(s>=e)
      return;
    int pivot=partition(v,s,e,count);
    *count+=((pivot-1)-(s)+1);
    quicksort(v,s,pivot-1,count);
    *count+=((e)-(pivot+1)+1);
    quicksort(v,pivot+1,e,count);
    
}

int main() {
	
	vector<int> v;
	
	 string line;
  ifstream myfile ("example2.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      v.push_back(atoi(line.c_str()));
    }
    myfile.close();
  }

	long long int count=0;
	int j,temp,k;
	int n=v.size();
	int i=0;
	quicksort(v,0,n-1,&count);
	for(int j=0;j<n;j++){
	    cout<<v[j]<<" ";
	}
	cout<<endl;
	cout<<count<<endl;
	return 0;
}
