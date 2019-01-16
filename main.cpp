#include <iostream>
#include <cstring>
#include "server_utility/Server.h"
#include "Searcher.h"
#include "BFS.h"
#include "DFS.h"
#include "BestFirstSearch.h"

int main(int argc, char **argv) {

//
//  server_side::boot::Main runMain;
//  runMain.main(++argv);

  ProtocolMatrix pro;
  string val = "1,2,3\n2,3,4\n1,2,1\n0,0\n2,2\n";

MatrixMaze<Point> mat = pro.readProtocol(val);
vector<string> vecToReturn;
BestFirstSearch<Point, vector<string>> best;
best.search(&mat);

//
//  Searchable<Point> * searchable = new MatrixMaze<Point>(mat,start,exit);
//  Searcher<Point, vector<State<Point>*>>* searcher = new BestFirstSearch<Point, vector<State<Point>*>>();
//  vector<State<Point>*> answer;
//  answer = searcher->search(searchable);
//

  return 0;
}


