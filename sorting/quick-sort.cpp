#include<bits/stdc++.h>
using namespace std;


void quickSort(vector<int>&v, int low, int high);
int  partition(vector<int>&v, int low, int high);
void swap(int &a , int &b);
void printVector(vector<int>v){
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<< " ";
	}
	cout<<endl;
}
int main(){
	ifstream fin;
	fin.open("data.txt");
	int a;
	vector<int>v;
	while(!fin.eof()){
		fin>>a;
		v.push_back(a);
	}
	cout<<"****************Befor Sorting ************"<<endl;
	printVector(v);
	quickSort(v,0,v.size()-1);
	cout<<"*************** After Sorting *************"<<endl;
	printVector(v);
	return 0;
}

void quickSort(vector<int>&v, int low, int high){
	
	if(low<high){
	
		int p = partition(v, low, high);
		quickSort(v,low,p-1);
		quickSort(v,p+1,high);
	}
}

int partition(vector<int>&v, int low ,int high){
	int pivot = v[high];
	int i = low - 1;
	for(int j = low;j<high;j++){
		if(v[j]<pivot){
			i++;
			swap(v[i],v[j]);
		}
	}
	swap(v[i+1],v[high]);
	return (i+1);
}

void swap(int &a, int &b){
	int temp = a;
	a=b;
	b=temp;
}
