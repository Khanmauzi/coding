#include<bits/stdc++.h>
using namespace std;


void quickSort(vector<int>&v, int low, int high);
int  partition(vector<int>&v, int low, int high);
void swap(int &a , int &b);
int binarySearch(vector<int>v, int low, int high, int key);
void printResult(int index, int key);
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
	
	quickSort(v,0,v.size()-1);
	printVector(v);
	int dataFound = 55;
	int dataNotFound = 39;
	int index=-1;
	index = binarySearch(v,0,v.size(),dataFound);
	printResult(index, dataFound);
	index = binarySearch(v,0,v.size(),dataNotFound);
	printResult(index, dataNotFound);
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

void printResult(int index, int key){
	if(index>=0){
		cout<<"Found value : "<<key <<" at index: "<<index<<endl;
	} else {
		cout<<"Not found value : "<<key<<endl;
	}
}
int binarySearch(vector<int>v, int low, int high, int key){
	if(low >= high && v[low] != key )
	return -1;
	int m = low+ (high-low)/2;
	if(v[m]==key){
		return m;
	} else if(v[m]>key){
		return binarySearch(v,low,m,key);
	} else {
		return binarySearch(v,m+1,high,key);
	}
}
