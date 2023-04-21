#pragma once
#include<iostream>
#include<vector>
using namespace std;

class PriorityQueue {
public:
	PriorityQueue() {} 
	~PriorityQueue() {} 
	void push(int value, int priority); 
	void pop(); 
	int top(); 
	void clear(); 
	void printAsArray(); 
	void printAsTree(); 
	
private:
	vector<pair<int,int>> queue;
	void shift_up(int pos); 
	void shift_down(int pos); 
};
