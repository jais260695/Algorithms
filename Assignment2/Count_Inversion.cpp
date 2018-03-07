#include<bits/stdc++.h>
using namespace std;


long long int merge(vector<int>& v, int low, int mid, int high){
	long long int inv_count=0;
	int ln=mid-low;
    int rn=high-(mid+1);
    int L[ln+1];
    int R[rn+1];
    
    for(int i=0;i<=ln;i++){
        L[i]=v[low+i];
    }
    for(int i=0;i<=rn;i++){
        R[i]=v[mid+1+i];
        
    }
    int i=0,j=0,k=low;
    while(i<=ln && j<=rn){
        if(L[i]<=R[j]){
            v[k]=L[i];
            k++;
            i++;
        }
        else{
        	inv_count+=(ln-i+1);
            v[k]=R[j];
            j++;
            k++;
        }
    }
    while(i<=ln){
        v[k]=L[i];
        i++;
        k++;
    }
    while(j<=rn){
        v[k]=R[j];
        j++;
        k++;
    }
    return inv_count;
}

long long int mergesort(vector<int>& v, int low, int high){
	long long int count=0;
	if(low>=high){ return 0;}
		int mid=low+(high-low)/2;
		count=mergesort(v,low,mid);
		count+=mergesort(v,mid+1,high);
		count+=merge(v,low,mid,high);
		return count;

}
int main(){
	vector<int> v;
	 string line;
  ifstream myfile ("example.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      v.push_back(atoi(line.c_str()));
    }
    myfile.close();
  }
  

  long long int inversion_count=mergesort(v,0,v.size()-1);
 /*   for(int i=0;i<v.size();i++)
  {
  	cout<<v[i]<<" ";	
  	
  }*/
 // cout<<endl;
  cout<<inversion_count;
	return 0;
}
