/*********************************/
/*Arnaldo A Villarreal
/*CSCE 221 -510
/*Assignment 6, 04-30-2013
/**********************************/
#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include "Edge.h"

using namespace std;

class Graph;
class Edge;

class Vertex {
private:
	vector<Edge*> inList; // source vertex
	vector<Edge*> outList; // end vertex
	int id;
	friend class Graph;
public:

	Vertex(int sid)
	{
		inList.resize(0);
		outList.resize(0);
		id = sid;
	}

	int getID() const{return id;}

	vector<Edge*> getOutEdges() const
	{
		return outList;
	}

	vector<Edge*> getInEdges() const
	{
		return inList;
	}

	bool isAdjacent(Vertex* v){
		for (int i = 0; i < v->outList.size(); ++i) {
			if (this->outList[i]->geteVertP() == v) return true;
		}
		return false;
	}
};

#endif
