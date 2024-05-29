#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include"Graph.h"
#include<stdlib.h>

using namespace std;
Graph g;
int main() {
	string press;
	g.loadCities(g.map, g.B_DFS);
	g.loadEdges(g.map, g.B_DFS);
	while (true) {

		cout << "press 1 to mainmenu" << endl;
		cout << "press 2 to exit" << endl;
		cin >> press;
		if (press == "1") {
			system("cls");
			g.mainmenu();
		}
		else if (press == "2")

			break;
		else
		{
			cout << "invalid input !!\n\n";
		}
	}
	return 0;

}

