#pragma once
#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<stdlib.h>

using namespace std;
class Graph
{
public:
	bool isDirected = true;
	unordered_map<string, list<pair<string, int>>> map;
	unordered_map<string, list<pair<string, int>>> B_DFS;
	Graph();
	void AddEdge();
	void Addcity();
	void displaygraphdata();
	void Deletecity();
	void DeleteEdge();
	void mainmenu();
	void updategraph();
	void dijkstra(unordered_map<string, list<pair<string, int>>>, string s, string d);
	void DFS();
	void BFS();
	void EdgeType();
	void saveEdges();
	void loadEdges(unordered_map<string, list<pair<string, int>>>&, unordered_map<string, list<pair<string, int>>>&);
	void savecities();
	void loadCities(unordered_map<string, list<pair<string, int>>>&, unordered_map<string, list<pair<string, int>>>&);
	~Graph();
};



