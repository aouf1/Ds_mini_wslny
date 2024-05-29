#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<fstream>
#include"Graph.h"
#include<stdlib.h>
using namespace std;
Graph::Graph() {
}
void Graph::Addcity() {
	cout << "Enter  name of the city" << endl;
	string nameofcity;
	cin >> nameofcity;
	if (map.find(nameofcity) == map.end()) {
		map[nameofcity];
		B_DFS[nameofcity];
		cout << " Added \n\n";
	}
	else {
		cout << "This city is already exist!\n\n";
	}
	//add new city 
}
void Graph::AddEdge()
{
	if (map.size() < 2) {
		cout << "Cities is less than 2 ! \n";
		return;
	}
	string city1;
	string city2;
	int weight;
	while (true)
	{
		EdgeType();
		cout << "Enter source:" << endl;
		cin >> city1;
		cout << "Enter distination: " << endl;
		cin >> city2;
		if (city1 != city2)
			break;
		cout << "You can not enter the same source and destination!!\n\n";
	}
	if ((map.find(city1) != map.end() && map.find(city2) != map.end()))
	{
		while (true)
		{
			cout << "Enter distance between cities" << endl;
			cin >> weight;
			cout << "\n";
			if (weight > 0)
				break;
			cout << "You must enter postive value!\n\n";
		}

		bool check = true;
		if (!isDirected) {
			for (auto it : map) {
				for (auto iti : it.second) {

					if ((it.first == city1 && iti.first == city2 && iti.second == weight) ||
						(it.first == city2 && iti.first == city1 && iti.second == weight)) {
						check = false;
						break;
					}
				}
			}
			if (check) {
				map[city1].push_back(make_pair(city2, weight));
				map[city2].push_back(make_pair(city1, weight));
				B_DFS[city1].push_back(make_pair(city2, weight));
				B_DFS[city2].push_back(make_pair(city1, weight));
				cout << " Added \n\n";

			}
			else
				cout << "This data is already added !! \n\n";
		}
		else
		{
			for (auto it : map) {


				for (auto iti : it.second) {

					if ((it.first == city1 && iti.first == city2 && iti.second == weight)) {
						check = false;
						break;
					}
				}
			}
			if (check) {
				map[city1].push_back(make_pair(city2, weight));
				B_DFS[city1].push_back(make_pair(city2, weight));
				B_DFS[city2].push_back(make_pair(city1, weight));
				cout << " Added \n\n";
			}
			else
				cout << "This data is already added !! \n\n";
		}




	}
	else
		cout << "One or the two cities you enterd are not exist please add them !\n\n";
}


void Graph::displaygraphdata() {
	if (map.size() < 1) {
		cout << "No city added ! \n";
		return;
	}
	for (auto it : map) {
		for (auto iti : it.second) {
			cout << it.first << "----> " << iti.first;

			cout << "  " << iti.second << "   \n";
		}

	}
	for (auto it : map)
	{
		cout << " City  " << " :   " << it.first << endl;
	}
}
void Graph::Deletecity()
{
	if (map.size() < 1) {
		cout << "No city added ! \n";
		return;
	}
	cout << "Enter name of the city" << endl;
	string nameofcity;
	cin >> nameofcity;
	if (map.find(nameofcity) != map.end()) {
		map.erase(nameofcity);
		B_DFS.erase(nameofcity);
		cout << "Deleted\n\n";
		for (auto it : map) {

			for (auto iti : it.second) {
				if (iti.first == nameofcity) {
					map[it.first].remove(make_pair(iti.first, iti.second));
				}
			}
		}
		for (auto i : B_DFS) {
			for (auto j : i.second) {
				if (j.first == nameofcity) {
					B_DFS[i.first].remove(make_pair(j.first, j.second));
				}
			}
		}
	}
	else
	{
		cout << "This city is not exist\n\n";
	}
}

void Graph::DeleteEdge()
{
	bool isExist = false;
	for (auto it : map) {
		if (!map[it.first].empty()) {
			isExist = true;
			break;
		}
	}
	if (!isExist) {
		cout << "There is no edge to delete ! \n";
		return;
	}
	string city1;
	string city2;
	int weight;
	while (true)
	{
		cout << "Enter source:" << endl;
		cin >> city1;
		cout << "Enter distination: " << endl;
		cin >> city2;
		if (city1 != city2)
			break;
		cout << "You can not enter the same source and destination!!\n\n";
	}
	if ((map.find(city1) != map.end() && map.find(city2) != map.end()))
	{
		while (true)
		{

			cout << "Enter distance between cities" << endl;
			cin >> weight;
			cout << "\n";
			if (weight > 0)
				break;
			cout << "You must enter postive value!\n\n";
		}
		bool check = false;
		for (auto it : map) {
			for (auto iti : it.second) {

				if ((it.first == city1 && iti.first == city2 && iti.second == weight) ||
					(it.first == city2 && iti.first == city1 && iti.second == weight)) {
					check = true;
					break;
				}
			}
		}
		if (check) {
			map[city1].remove(make_pair(city2, weight));
			map[city2].remove(make_pair(city1, weight));
			B_DFS[city1].remove(make_pair(city2, weight));
			B_DFS[city2].remove(make_pair(city1, weight));

			cout << "Deleted" << endl;
		}
		else
		{
			cout << "Edge not exist" << endl;
		}
	}

	else
		cout << "One or the two cities you enterd are not exist please add them !\n\n";

}
void Graph::mainmenu() {
	string press;
	while (true) {
		cout << endl << "-----------> main menu <------------" << endl;
		cout << "Press 1 to add city" << endl;
		cout << "Press 2 to add edge" << endl;
		cout << "Press 3 to display data" << endl;
		cout << "Press 4 to update graph" << endl;
		cout << "Press 5 to apply dijkstra\n";
		cout << "Press 6 to apply BFS\n";
		cout << "Press 7 to applly DFS\n";
		cout << "Press 8 to exit" << endl;
		cin >> press;
		if (press == "1") {
			system("cls");
			Addcity();
		}
		else if (press == "2") {
			system("cls");

			AddEdge();
		}

		else if (press == "3") {
			system("cls");

			displaygraphdata();
		}
		else if (press == "4") {
			system("cls");

			updategraph();
		}
		else if (press == "5") {
			system("cls");
			if (map.size() < 1) {
				cout << "No city added ! \n";
				continue;
			}
			cout << "Enter source: ";
			string s, d;
			cin >> s;
			cout << "Enter destination: ";
			cin >> d;
			dijkstra(map, s, d);
		}
		else if (press == "6") {
			system("cls");
			BFS();
		}
		else if (press == "7") {
			system("cls");
			DFS();
		}
		else if (press == "8") {
			system("cls");
			savecities();
			saveEdges();
			break;

		}
		else
			cout << "Invalid Input!!\n";
	}
}
void Graph::updategraph() {
	if (map.size() < 1) {
		cout << "No city added ! \n";
		return;
	}
	string press;
	while (true) {
		cout << endl << "-----------> update menu <------------" << endl;
		cout << "Press 1 to add new city" << endl;
		cout << "Press 2 to add new edge" << endl;
		cout << "Press 3 to remove city" << endl;
		cout << "Press 4 to remove edge" << endl;
		cout << "Press 5 to exit" << endl;
		cin >> press;

		if (press == "1") {
			system("cls");
			Addcity();

		}
		else if (press == "2") {
			system("cls");
			AddEdge();
		}
		else if (press == "3") {
			system("cls");
			Deletecity();
		}
		else if (press == "4") {
			system("cls");
			DeleteEdge();
		}
		else if (press == "5") {
			system("cls");
			break;
		}
		else
		{
			cout << "invalid input !!\n\n";
		}
	}
}

void Graph::dijkstra(unordered_map<string, list<pair<string, int>>>map, string s, string d)
{

	unordered_map<string, bool>visited;
	unordered_map<string, int>distanceforeachvertex;
	unordered_map<string, string>parent;
	string current;
	if (map.find(s) != map.end() && map.find(d) != map.end()) {
		for (auto it : map) {
			if (it.first != s) {
				distanceforeachvertex[it.first] = INT_MAX;
				visited[it.first] = false;
			}
			else {
				distanceforeachvertex[it.first] = 0;
				visited[it.first] = true;
				current = s;


			}
		}

		for (int i = 0; i < map.size() - 1; i++) {
			int shortestdistance = INT_MAX;
			for (auto i : map) {
				if (i.first != s) {
					if (!visited[i.first] && distanceforeachvertex[i.first] < shortestdistance) {
						current = i.first;
						shortestdistance = distanceforeachvertex[i.first];
					}
				}
			}
			
				visited[current] = true;


			for (auto j : map[current]) {
				if (!visited[j.first]) {
					int totaldistance = j.second + distanceforeachvertex[current];
					if (totaldistance < distanceforeachvertex[j.first]) {
						distanceforeachvertex[j.first] = totaldistance;
						parent[j.first] = current;

					}
				}
			}
		}
		if (distanceforeachvertex[d] < INT_MAX && distanceforeachvertex[d] >= 0) {
			cout << "Shortest distance between " << s << " and " << d << " is " << distanceforeachvertex[d] << endl;
			cout << "shortest path is: ";

			vector<string>shortestpath;
			string current = d;
			while (current != s) {
				shortestpath.push_back(current);
				current = parent[current];
			}
			shortestpath.push_back(s);
			reverse(shortestpath.begin(), shortestpath.end());
			for (auto path : shortestpath)
				cout << path << " ";
		}
		else
			cout << "there is no path" << endl;
	}

	else
		cout << "Either one of cities or both of them is not found" << endl;

}
void Graph::BFS()
{
	if (B_DFS.size() < 1) {
		cout << "No city added ! \n";
		return;
	}
	string start;
	cout << " Enter the starting city to apply BFS" << endl;
	cin >> start;
	if (B_DFS.find(start) == B_DFS.end())
	{
		cout << "This city is not found" << endl;
	}
	else
	{
		unordered_map<string, bool>visited;
		queue<string> queue;
		queue.push(start);
		cout << "Following is Breadth First Traversal (starting from  \" " << start << " \" ) " << endl;
		while (!queue.empty())
		{
			string temp = queue.front();
			queue.pop();

			if (!visited[temp])
			{
				cout << temp << endl;
				visited[temp] = true;
			}
			for (auto it : B_DFS[temp])
			{
				if (!visited[it.first])
				{
					queue.push(it.first);
				}
			}
		}
	}
}
void Graph::DFS()
{
	if (B_DFS.size() < 1) {
		cout << "No city added ! \n";
		return;
	}
	string start;
	cout << " Enter the starting city to apply DFS" << endl;
	cin >> start;
	if (B_DFS.find(start) == B_DFS.end())
	{
		cout << "This city is not found" << endl;
	}
	else
	{
		unordered_map<string, bool>visited;
		stack<string> stack;
		stack.push(start);
		cout << "Following is Depth First Traversal (starting from  \" " << start << " \" ) " << endl;
		while (!stack.empty())
		{
			string temp = stack.top();
			stack.pop();

			if (!visited[temp])
			{
				cout << temp << endl;
				visited[temp] = true;
			}
			for (auto it : B_DFS[temp])
			{
				if (!visited[it.first])
				{
					stack.push(it.first);
				}
			}
		}
	}
}
void Graph::EdgeType()
{
	string press;


	cout << "press 1 for directed Graph" << endl;
	cout << "press 2 for Undirected Graph" << endl;
	cout << "press 3 to exit" << endl;

	cin >> press;
	if (press == "1") {
		isDirected = true;
	}
	else if (press == "2") {

		isDirected = false;
	}
	else if (press == "3") {
		mainmenu();
	}

	else
	{
		cout << "invalid input !!\n\n";
		EdgeType();
	}
}
void Graph::saveEdges()
{
	ofstream file1("graph.txt", ios::trunc);
	if (file1.is_open()) {

		for (auto& i : map)
		{
			for (auto& j : i.second)
			{
				file1 << i.first << " ";
				file1 << j.first << " " << j.second << endl;
			}
		}

	}
	file1.close();
	ofstream file2("graphBfs.txt", ios::trunc);
	if (file2.is_open()) {

		for (auto& i : B_DFS)
		{


			for (auto& j : i.second)
			{
				file2 << i.first << " ";
				file2 << j.first << " " << j.second << endl;
			}
		}
	}
	file2.close();
}
void Graph::loadEdges(unordered_map<string, list<pair<string, int>>>& my_map, unordered_map<string, list<pair<string, int>>>& D_bfs)
{
	ifstream infile1("graph.txt");
	if (infile1.is_open()) {
		string outer_key, inner_key;
		int value;
		while (infile1 >> outer_key >> inner_key >> value) {
			my_map[outer_key].push_back(make_pair(inner_key, value));
		}
	}
	infile1.close();
	ifstream infile2("graphBfs.txt");
	if (infile2.is_open()) {
		string outer_key, inner_key;
		int value;
		while (infile2 >> outer_key >> inner_key >> value) {
			D_bfs[outer_key].push_back(make_pair(inner_key, value));
		}
	}
	infile2.close();
}
void Graph::savecities()
{
	ofstream file1("city.txt", ios::trunc);

	if (file1.is_open()) {

		for (auto& i : map)
		{
			file1 << i.first << "\n";
		}
	}	
	file1.close();
	ofstream file2("cityBFS.txt", ios::trunc);

	if (file2.is_open()) {

		for (auto& i : B_DFS)
		{
			file2 << i.first << "\n";
		}
	}
	file2.close();
}
void Graph::loadCities(unordered_map<string, list<pair<string, int>>>& my_map, unordered_map<string, list<pair<string, int>>>& bdfs)
{
	ifstream infile1("city.txt");
	if (infile1.is_open()) {
		string city;
		while (infile1 >> city) {
			my_map[city];
		}
	}
	infile1.close();
	ifstream infile2("cityBFS.txt");
	if (infile2.is_open()) {
		string city;
		while (infile2 >> city) {
			bdfs[city];
		}
	}
	infile2.close();
}
Graph::~Graph()
{
}