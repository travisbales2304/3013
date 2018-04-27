//Travis Bales
//Algorithms
//4-13-2018
//Program 4
//This program wills a graph with vertexes containing information about a city.
//You then calculate the closest city to the starting city and add an edge between them.
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


string city = "Lares";
string state = "PR";
string startingcity = city;
string startingstate = state;
double lat = 0;
double lon = 0;
ofstream outfile;

int max_vertices = 3;
int max_edges = 100;
string list2[20000];
vertex* holder;






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
	int counter = 1;

	graph G;

	while (infile)
	{

		getline(infile, temp, ',');
		zip = atoi(temp.c_str());
		//cout << "zip " << zip << endl;
		getline(infile, temp, ',');
		lat = strtod(temp.c_str(), NULL);
		//cout << "lat " << lat << endl;
		getline(infile, temp, ',');
		lon = strtod(temp.c_str(), NULL);
		//cout << "lon " << lon << endl;
		getline(infile, temp, ',');
		city = temp;
		//cout << "city " << city << endl;
		getline(infile, temp, ',');
		state = temp;
		//cout << "state " << state << endl;
		getline(infile, temp);
		county = temp;
		//cout << "county " << county << endl;
		//cout << endl << endl;
		if (lat != 0 || lon != 0 || zip != 0)
		{
			G.addVertex(city, state, lat, lon);
		}
	}
	return G;
	infile.close();
}


int main(int argc, char **argv)
{
	outfile.open("results.txt");
	int count = 0;
	int totalmiles = 0;
	int totaledges = 0;

	for (int x = 0; x < 20000; x++)
	{
		list2[x] = "";
	}





	if (argc > 2) {
		max_vertices = stoi(argv[1]);
		max_edges = stoi(argv[2]);
	}
	else {
		cout << "Usage: ./graph max_vertices max_edges" << endl;
		exit(0);
	}

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


	//-Get's list of closest cities to starting city
	//-connects the closest 2 cities to the starting city if applicable
	//-starts the process over with the closest starting city
	//
	//

	for (int a = 0; a < G.vertexList.size(); a++)
	{

		//get's closest starting cities. and sets all cities found to starting city.
		if (startingstate != "PR")
		{
			double smallest = 50000, current = 60000;
			for (int z = 0; z < G.vertexList.size(); z++)
			{
				int position = 0;
				for (int y = 0; y < G.vertexList.size(); y++)
				{
					if (G.vertexList[y]->city != city && G.vertexList[y]->visited2 != 1) //|| G.vertexList[y]->state != state)
					{
						current = distanceEarth(lat, lon, G.vertexList[y]->loc.lat, G.vertexList[y]->loc.lon);
					}
					if (current < smallest)
					{
						smallest = current;
						position = y;

					}
				}
				smallest = 50000;
				current = 60000;
				for (int f = 0; f < 20000; f++)
				{
					if (list2[f] == "")
					{
						list2[f] = G.vertexList[position]->city;
						break;
					}
				}
				G.vertexList[position]->visited2++;
			}
		}

		if (startingstate == "PR")
		{
			double smallest = 50000, current = 60000;
			for (int z = 0; z < G.vertexList.size(); z++)
			{
				int position = 0;
				for (int y = 0; y < G.vertexList.size(); y++)
				{
					if (G.vertexList[y]->city != city && G.vertexList[y]->visited2 != 1) //|| G.vertexList[y]->state != state)
					{
						
						current = distanceEarth(lat, lon, G.vertexList[y]->loc.lat, G.vertexList[y]->loc.lon);
						
					}
					if (current < smallest && G.vertexList[y]->state == "PR")
					{
						smallest = current;
						position = y;

					}
				}
				
				smallest = 50000;
				current = 60000;
				
				for (int f = 0; f < 20000; f++)
				{
					if (list2[f] == "")
					{
						list2[f] = G.vertexList[position]->city;
						break;
					}
				}
				G.vertexList[position]->visited2++;
			}
		}



		//Resets visited2 to 0 on all vertex;
		//visited2 is a just a counter to see if the vertex has been looked at already
		//visited1 is the amount of edges connected to a vertex
		for (int j = 0; j < G.vertexList.size(); j++)
		{
			G.vertexList[j]->visited2 = 0;
			if (G.vertexList[j]->city == city && G.vertexList[j]->state == state)
			{
				G.vertexList[j]->visited2 = 1;
			}
		}

		//removes the last position on the list because it's the starting city?
		//list2.pop_back();

		//Finds the position of the starting city
		int position2 = -1;
		for (int y = 0; y < B.vertexList.size(); y++)
		{
			if (B.vertexList[y]->city == city && B.vertexList[y]->state == state)
			{
				position2 = y;
			}
		}




		//-Takes the list of cities arranged by distance to the started city
		//and connects the starting city to the two closest applicable cities
		//-resets the starting city to the city it was connected to

		for (int b = 0; b < 20000; b++)
		{
			
			int position = -1;
			for (int x = 0; x < B.vertexList.size(); x++)
			{
				if (B.vertexList[x]->city == list2[b] && B.vertexList[x]->visited < 2)
				{
					position = x;
				}
			}
			if (position != -1)
			{
				double d = distanceEarth(B.vertexList[position2]->loc.lat, B.vertexList[position2]->loc.lon, B.vertexList[position]->loc.lat, B.vertexList[position]->loc.lon);
				B.addEdge(position2, position, (int)d, true);
				totaledges++;
				totalmiles += d;
				B.vertexList[position]->visited++;
				B.vertexList[position2]->visited++;
				
				city = B.vertexList[position]->city;
				state = B.vertexList[position]->state;

			}
			b++;
			for (int x = 0; x < B.vertexList.size(); x++)
			{
				if (B.vertexList[x]->city == list2[b] && B.vertexList[x]->visited < max_vertices)
				{
					position = x;
				}
			}
			if (position != -1)
			{
				double d = distanceEarth(B.vertexList[position2]->loc.lat, B.vertexList[position2]->loc.lon, B.vertexList[position]->loc.lat, B.vertexList[position]->loc.lon);
				B.addEdge(position2, position, (int)d, true);
				totaledges++;
				totalmiles += d;
				B.vertexList[position]->visited++;
				B.vertexList[position2]->visited++;
				city = B.vertexList[position]->city;
				state = B.vertexList[position]->state;
				break;

			}
			position = -1;
		}


		//Resets the list of cities back to nothing.
		for (int z = 0; z <20000; z++)
		{
			list2[z] = "";
		}



	}


	cout << startingcity << ", " << startingstate << endl;
	cout << totalmiles << " miles " << totaledges << " edges " << endl;



	outfile << B.graphViz(false);
	system("pause");
}

