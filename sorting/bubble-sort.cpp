#include<bits/stdc++.h>
using namespace std;
void swap(int &a, int &b){
	int temp =a;
	a=b;
	b=temp;
}
void bubblesort(vector<int>&v){
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.size()-1;j++){
			if(v[j]>v[j+1]){
				swap(v[j],v[j+1]);
			}
		}
	}
}
void display(vector<int>v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
int main(){
	ifstream fin;
	fin.open("data.txt");
	vector<int>v;
	int a;
	while(!fin.eof()){
		fin>>a;
		v.push_back(a);
	}
	cout<<"befor sorting.............."<<endl;
	display(v);
	bubblesort(v);
	cout<<"*******************After sorting****************"<<endl;
	display(v);
	return 0;
}
