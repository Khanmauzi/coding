#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void swap(int &a, int &b){
	int temp =a;
	a=b;
	b=temp;
}
void selectionSort(vector<int>&v) {
	int minIndex = 0;
	for(int i=0;i<v.size();i++){
		minIndex=i;
		for(int j=i+1;j<v.size();j++){
			if(v[minIndex]>v[j]){
				minIndex = j;
			}
		}
		swap(v[i],v[minIndex]);
	}
}
void display(vector<int>v);
int main(){
	ifstream fin;
	fin.open("data.txt");
	int a;
	vector<int>v;
	while(!fin.eof()){
		fin>>a;
		v.push_back(a);
	}
	selectionSort(v);
	display(v);
	return 0;
}

void display(vector<int>v){
	for(int i=0;i<v.size(); i++){
		cout<<v[i]<< " ";
	}
}

