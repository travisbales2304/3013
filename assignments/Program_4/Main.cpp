
#include "graph.h"
#include "windows.h"
#include"edge_heap.h"
#include<iostream>
#include <queue>
#include <vector>
using namespace std;


void randomEdges(graph &g, int numEdges) {
	int r1, r2;
	latlon from;
	latlon to;
	double d;
	for (int i = 0; i<numEdges; i++) {
		r1 = rand() % g.vertexList.size();
		r2 = rand() % g.vertexList.size();
		from = g.vertexList[r1]->loc;
		to = g.vertexList[r2]->loc;
		d = distanceEarth(from.lat, from.lon, to.lat, to.lon);
		g.addEdge(r1, r2, (int)d, true);
	}




}
/**
* loadGraphCSV - loads a graph with the given csv
* Params:
*     string filename  - filename to open
* Returns
*     graph
*/
graph loadGraphCSV(string filename, int max = 0)
{
	int zip;
	double lat;
	double lon;
	string city;
	string state;
	string county;


	strMapInt cityCheck;

	int i = 0;

	graph G;

	ifstream file(filename);

	for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
	{
		zip = stoi((*loop)[0]);
		if ((*loop)[1].length() > 0)
		{
			lat = stod((*loop)[1]);
		}
		else
		{
			lat = 0.0;
		}

		if ((*loop)[2].length() > 0)
		{
			lon = stod((*loop)[2]);
		}
		else
		{
			lon = 0.0;
		}

		city = (*loop)[3];
		state = (*loop)[4];
		county = (*loop)[5];


		if (cityCheck.find(city) == cityCheck.end())
		{
			// Add the city as a key to the map.
			cityCheck[city] = 0;

			if (state != "PR") {
				G.addVertex(city, state, lat, lon);
				i++;
			}
		}

		if (i > max && max != 0) {
			return G;
		}

	}

	return G;
}
/**
* filterDups - filters out duplicate cities and creates new output file
* Params:
*     string filename  - filename to open
*     string outfile   - filename to write to
* Returns
*     graph
*/
void filterDups(string filename, string outfile)
{
	int zip;
	double lat;
	double lon;
	string city;
	string state;
	string county;

	strMapInt cityCheck;

	int i = 0;


	ifstream file(filename);
	ofstream out(outfile);

	for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
	{
		zip = stoi((*loop)[0]);
		if ((*loop)[1].length() > 0)
		{
			lat = stod((*loop)[1]);
		}
		else
		{
			lat = 0.0;
		}

		if ((*loop)[2].length() > 0)
		{
			lon = stod((*loop)[2]);
		}
		else
		{
			lon = 0.0;
		}

		city = (*loop)[3];
		state = (*loop)[4];
		county = (*loop)[5];


		if (cityCheck.find(city) == cityCheck.end())
		{
			// Add the city as a key to the map.
			cityCheck[city] = 0;
			out << zip << "," << lat << "," << lon << "," << city << "," << state << "," << county << "\n";

		}


	}

}








graph Fillgraph(string filename)
{
	ifstream infile(filename);
	int zip = 0;
	string city = "";
	string state = "";
	string county = "";
	double lat = 0;
	double lon = 0;
	string temp = "";

	graph G;
	int counter = 0;
	while (!infile.eof())
	{
		if (counter != 5)
		{
			getline(infile, temp, ',');
		}
		else if (counter == 5)
		{
			getline(infile, temp);
		}
		if (counter == 0)
		{
			zip = stoi(temp);
			counter++;
		}
		else if (counter == 1)
		{
			lat = stod(temp);
			counter++;
		}
		else if (counter == 2)
		{
			lon = stod(temp);
			counter++;
		}
		else if (counter == 3)
		{
			city = temp;
			counter++;
		}
		else if (counter == 4)
		{
			state = temp;
			counter++;
		}
		else if (counter == 5)
		{
			county = temp;
			G.addVertex(city, state, lat, lon);
			counter = 0;
		}

	}
	infile.close();
	return G;
}
// Test Driver
int main(/*int argc, char **argv*/)
{

	string city = "San Juan";
	string state = "PR";
	double lat = 0;
	double lon = 0;
	ofstream outfile;
	outfile.open("results.txt");
	int max_vertices = 3;
	int max_edges = 100;
	vector<string> list2;
	vertex* holder;
	vector<string>::iterator it;
	
	/*
	if (argc > 2) {
		max_vertices = stoi(argv[1]);
		max_edges = stoi(argv[2]);
	}
	else {
		cout << "Usage: ./graph max_vertices max_edges" << endl;
		exit(0);
	}
	*/
	graph G = Fillgraph("filtered_cities.csv");
	graph B = Fillgraph("filtered_cities.csv");



	//gets lat and lon for starting city
	for (int x = 0; x < G.vertexList.size(); x++)
	{
		if (G.vertexList[x]->city == city && G.vertexList[x]->state == state)
		{
			holder = G.vertexList[x];
			lon = holder->loc.lon;
			lat = holder->loc.lat;
		}
	}




	int count = 0;
	int totalmiles = 0;
	int totaledges = 0;


	/*
	-Get's closest starting cities and puts in a list.
	-Checks list of starting cities and connects one if possible.
	-resets list.
	*/
	for (int a = 0; a < G.vertexList.size(); a++)
	{

		//get's closest starting cities. and sets all cities found to starting city.
		if (state == "PR")
		{
			double smallest = 50000, current = 60000;
			for (int z = 0; z < G.vertexList.size(); z++)
			{
				int position = 0;
				for (int y = 0; y < G.vertexList.size(); y++)
				{
					if (G.vertexList[y]->state == "PR")
					{
						if (G.vertexList[y]->city != city && G.vertexList[y]->visited2 != 1) //|| G.vertexList[y]->state != state)
						{
							//cout << G.vertexList[y]->city << endl;
							current = distanceEarth(lat, lon, G.vertexList[y]->loc.lat, G.vertexList[y]->loc.lon);
							//cout << current << endl;
						}
						if (current < smallest)
						{
							smallest = current;
							position = y;

						}
					}
				}
				//cout << *G.vertexList[position] << endl;
				smallest = 50000;
				current = 60000;
				//pushes cities into a list from closest to farthest
				list2.push_back(G.vertexList[position]->city);
				G.vertexList[position]->visited2++;
				//system("cls");
				//count++;
				//cout << count << endl;
			}
		}

		else
		{
			double smallest = 50000, current = 60000;
			for (int z = 0; z < G.vertexList.size(); z++)
			{
				int position = 0;
				for (int y = 0; y < G.vertexList.size(); y++)
				{
					if (G.vertexList[y]->city != city && G.vertexList[y]->visited2 != 1) //|| G.vertexList[y]->state != state)
					{
						//cout << G.vertexList[y]->city << endl;
						current = distanceEarth(lat, lon, G.vertexList[y]->loc.lat, G.vertexList[y]->loc.lon);
						//cout << current << endl;
					}
					if (current < smallest)
					{
						smallest = current;
						position = y;
					}
				}
				//cout << *G.vertexList[position] << endl;
				smallest = 50000;
				current = 60000;
				//pushes cities into a list from closest to farthest
				list2.push_back(G.vertexList[position]->city);
				G.vertexList[position]->visited2++;
				//system("cls");
				//count++;
				//cout << count << endl;
			}


		}






		//Resets visited2 to 0 on all vertex;
		for (int j = 0; j < G.vertexList.size(); j++)
		{
			G.vertexList[j]->visited2 = 0;
			if (G.vertexList[j]->city == city && G.vertexList[j]->state == state)
			{
				G.vertexList[j]->visited2 = 1;
			}
		}

		//removes the last position on the list because it's the starting city?
		list2.pop_back();


		//TEST
		/*


		for (it = list2.begin(); it != list2.end(); it++)
		{
			cout << *it << endl;
		}



		for (int j = 0; j < B.vertexList.size(); j++)
		{
		cout << B.vertexList[j]->city << endl;
		}


		*/
		

		//Finds the position of the starting city
		int position2 = -1;
		for (int y = 0; y < B.vertexList.size(); y++)
		{
			if (B.vertexList[y]->city == city && B.vertexList[y]->state == state)
			{
				position2 = y;
			}
		}



		/*
		-Takes the list of cities arranged by distance to the started city
		and connects the starting city to the two closest applicable cities
		-resets the starting city to the city it was connected to
		*/
		for (it = list2.begin(); it != list2.end(); it++)
		{
			//cout << "the iterator is at " << *it << endl;
			int position = -1;
			for (int x = 0; x < B.vertexList.size(); x++)
			{
				if (B.vertexList[x]->city == *it && B.vertexList[x]->visited < 2)
				{
					position = x;
				}
		
			}
			if (position != -1)
			{
				double d = distanceEarth(B.vertexList[position2]->loc.lat, B.vertexList[position2]->loc.lon, B.vertexList[position]->loc.lat, B.vertexList[position]->loc.lon);
				totalmiles += d;
				totaledges++;
				//cout << totaledges << " edges" << endl;
				//cout << totalmiles << " miles" << endl;
				B.addEdge(position2, position, (int)d, true);
				B.vertexList[position]->visited++;
				B.vertexList[position2]->visited++;
				//cout << city << " , ";
				city = B.vertexList[position]->city;
				state = B.vertexList[position]->state;
				//cout << "City change " << city << endl;
				

			}
			it++;


			for (int x = 0; x < B.vertexList.size(); x++)
			{
				if (B.vertexList[x]->city == *it && B.vertexList[x]->visited < 2)
				{
					position = x;
				}
			}
			if (position != -1)
			{
				double d = distanceEarth(B.vertexList[position2]->loc.lat, B.vertexList[position2]->loc.lon, B.vertexList[position]->loc.lat, B.vertexList[position]->loc.lon);
				B.addEdge(position2, position, (int)d, true);
				totalmiles += d;
				totaledges++;
				//cout << totaledges << " edges" << endl;
				//cout << totalmiles << " miles" << endl;
				B.vertexList[position]->visited++;
				B.vertexList[position2]->visited++;
				//cout << city << " , ";
				city = B.vertexList[position]->city;
				state = B.vertexList[position]->state;
				//cout << "City change " << city << endl;
				break;

			}
			position = -1;
		}


		//Resets the list of cities back to nothing.
		for (int z = 0; z < list2.size(); z++)
		{
			list2.clear();
		}
	}
outfile << B.graphViz(false) << endl;
	outfile << B.graphViz(false);
	system("pause");
}

