#include<bits/stdc++.h>
using namespace std;


void mergeSort(vector<int>&v, int l, int r);
void merger(vector<int>&v, int l, int m , int r);
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
	mergeSort(v,0,v.size()-1);
	cout<<"*************** After Sorting *************"<<endl;
	printVector(v);
	return 0;
}

void mergeSort(vector<int>&v, int l, int r){
	
	if(l>=r)
	return;
	if(r>l){
		int m = l + (r-l)/2;
		mergeSort(v,l,m);
		mergeSort(v,m+1,r);
		merger(v,l,m,r);
	}
}

void merger(vector<int>&v, int l ,int m , int r){
	vector<int>left;
	vector<int>right;
	int leftCount = m - l +1;
	int rightCount = r - m;
	
	for(int i=0;i<leftCount;i++){
		left.push_back(v[i+l]);
	}
	for(int i=0;i<rightCount;i++){
		right.push_back(v[m+1+i]);
	}
	int index = l;
	int cnt = 0 ;
	int leftIndex = 0;
	int rightIndex = 0;
	while(leftIndex < leftCount && rightIndex < rightCount){
		if(left[leftIndex] < right[rightIndex]){
			v[index++] = left[leftIndex++];
		} else {
			v[index++] = right[rightIndex++];
		}
	}
	while(leftIndex < leftCount){
		v[index++] = left[leftIndex++];
	}
	while(rightIndex < rightCount){
		v[index++] = right[rightIndex++];
	}
}
