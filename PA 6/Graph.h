/*********************************/
/*Arnaldo A Villarreal
/*CSCE 221 -510
/*Assignment 6, 04-30-2013
/**********************************/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Vertex.h"
#include "Edge.h"
#include "PQueueHeap.h"

using namespace std;

class Edge;
class Vertex;

class Graph{
private:
	vector<Vertex*> vertList;
	vector<Edge*> edgeList;
public:

	Graph(string filename) {
		ifstream ifs(filename.c_str());
		int vertnum;
		ifs>>vertnum;
		for(int i=0;i<vertnum;i++) // push all vertices into the vertex vector before assigning the in and out list
		{
			Vertex *vert = new Vertex(i+1);
			vertList.push_back(vert);
		}
		int svert,evert,weit;
		ifs>>svert;
		while(svert!=-1)
		{
			ifs>>evert;
			while(evert!=-1)
			{
				ifs>>weit; // one weight means one edge
				Edge *tempedge = new Edge(vertList[svert-1],vertList[evert-1],weit); // new edge
				edgeList.push_back(tempedge);
				vertList[svert-1]->outList.push_back(tempedge);
				vertList[evert-1]->inList.push_back(tempedge);
				ifs>>evert;
			}
			ifs>>svert;
		}
		ifs.close();
	}
	~Graph() {
		for(int i = 0; i < vertList.size(); i++)
			delete vertList[i];
		for(int i = 0; i < edgeList.size(); i++)
			delete edgeList[i];
	}
	vector<Vertex*> getVertices() const {
		return vertList;
	}

	vector<Edge*> getEdges() const {
		return edgeList;
	}

	void addVertex(Vertex* newVert)
	{
		vertList.push_back(newVert);
	}

	void addEdge(Edge* edge)
	{
		edgeList.push_back(edge);
	}

	int sizeGraph()
	{
		return this->vertList.size();
	}

	Vertex* getVertex(int i)
	{
		return vertList[i];
	}

	vector<Vertex*> getAdjacentVerts(Vertex* vert)
	{
		vector<Edge*> outEdges = vert->getOutEdges();
		vector<Vertex*> adjVert;
		for (int i = 0; i < outEdges.size(); i++) {
			adjVert.push_back(outEdges[i]->geteVertP());
		}

		return adjVert;
	}

	void PrintGraph() //Print out according to instructions
	{
		cout << vertList.size();
		for (int i = 0; i < vertList.size(); i++){
			cout << "\r\n" << i+1 << " ";
			vector<Edge*> outEdge = vertList[i]->getOutEdges();

			for (int j = 0; j < outEdge.size(); j++) {
				Vertex* endVert = outEdge[j]->geteVertP();
				cout << endVert->getID() << " ";
				cout << outEdge[j]->getWeight() << " ";
			}
			cout << "-1";
		}
		cout << "\r\n-1\n";
	}

	void printPath(vector<Vertex*> par, Vertex* s, Vertex* e, Vertex* prev)
	{
		if (e == s) cout << s->getID();
		else{
			printPath(par, s, par[e->getID()-1], prev);
			cout << " ----> " << e->getID();
		}
	}

	void dijkstra(int sourceID, int endID)
	{
		int inf = 100000; // "infinity"
		const vector<Vertex*>& vert = this->getVertices();
		PQueueHeap<Vertex*>pq;
		vector<int*> loco(vert.size());
		vector<int> dist(vert.size());
		vector<Vertex*> par(vert.size());
		int decKComp = 0;
		int removeMComp = 0;

		for(int i = 0; i < vert.size(); i++)
		{
			dist[i] = inf; //dist = "infinity"
			par[i] = NULL;
		}

		dist[sourceID] = 0; //set source to 0, all others are still "infinity"

		for(int i = 0; i < vert.size(); i++)
		{
			loco[i] = pq.insert(dist[i], vert[i]);	//create pq with key distance and object vertex, use locator in loco
		}

		cout << "Starting priority queue" << endl;
		pq.printQueue();

		while(!pq.isEmpty())
		{
			Vertex* mini = pq.minElement();	//get a copy of minElement before popping
			removeMComp  += pq.removeMin();
			const vector<Edge*>& outEdge = mini->getOutEdges();

			for(int i = 0; i < outEdge.size(); i++)	//iterate through outEdges
			{
				Vertex* d = outEdge[i]->geteVertP();
				int w = outEdge[i]->getWeight();

				if ((dist[mini->getID()-1] + w) < dist[d->getID()-1])//relax
				{
					dist[d->getID()-1] = dist[mini->getID()-1] + w;
					par[d->getID()-1] = mini;
					int decrease = pq.decreaseKey(loco[d->getID()-1], dist[d->getID()-1]);
					decKComp = decKComp + decrease;
				}
			}
			cout << "Iteration complete, this is the PQ now: " << endl;
			pq.printQueue();
		}

		cout << "\nShortest path:\n";
		printPath(par, vert[sourceID], vert[endID], vert[sourceID]);

		cout << "\nTotal weight of the shortest path from " << sourceID + 1 << " to " << endID + 1 << " = " << dist[endID] << "\n";
		cout << "Total comparisons = " << vert.size() + decKComp + removeMComp << endl;
	}
};
#endif
