#include<bits/stdc++.h>
using namespace std;
void swap(int &a, int &b){
	int temp =a;
	a=b;
	b=temp;
}
void insertsort(vector<int>&v){
	int temp = 0;
	for(int i=1;i<v.size();i++){
		temp = i-1;
		int value = v[i]; 
		while(temp >= 0 && v[temp]>v[temp+1]){
			v[temp+1]=v[temp];
			v[temp]=value;
			temp--;
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
	insertsort(v);
	cout<<"*******************After sorting****************"<<endl;
	display(v);
	return 0;
}
