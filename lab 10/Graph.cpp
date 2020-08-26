#include "Graph.h"

Graph::Graph(ifstream &ifs) {
	int nodes = 0;
  int edges = 0;
  int weight = 0;
	string title = "";
  string adjTitle = "";
	
	ifs >> nodes;
	ifs >> edges;
	
	ifs.ignore();
	
	for (int i = 0; i < nodes; i++) {
		Vertex node;
		string temp = "";
		getline(ifs, temp);
		node.label = temp;
		vertices.push_back(node);
	}
	
	while (ifs >> title) {
		int index = 0, adjIndex = 0;
		
		ifs >> adjTitle;
		ifs >> weight;
		
		for (unsigned int i = 0; i < vertices.size(); i++) {
			if (title == vertices.at(i).label) {
				index = i;
			}
			if (adjTitle == vertices.at(i).label) {
				adjIndex = i;
			}
		}
		
		vertices.at(index).neighbors.push_back(make_pair(adjIndex, weight));
	}
}

Graph::~Graph() {
	vertices.clear();
}

void Graph::output_graph(const string &filename) {
	ofstream fout(filename);
	if (fout.is_open()) {
		fout << "digraph G {" << endl;
		
		for (unsigned int i = 0; i < vertices.size(); i++) {
			if (vertices.at(i).distance != INT_MAX) {
				fout << "	" << vertices.at(i).label << "[label= \"" << vertices.at(i).label << " " << vertices.at(i).distance << "\"];" << endl;
				
				for (auto j = vertices.at(i).neighbors.begin(); j != vertices.at(i).neighbors.end(); j++) {
					fout << "	" << vertices.at(i).label << " -> " << vertices.at(j->first).label << endl;
				}
			}
		}
		
		fout << "}";
		fout.close();
		
		string systemCommand = "dot -T jpg " + filename + " -o pic.jpg";
		system(systemCommand.c_str());
	}
	else {
		cerr << "Could not open " << filename << endl;
	}
}

void Graph::bfs() {
	vertices.at(0).distance = 0;
	
	queue<Vertex*> q;
	q.push(&vertices.at(0));
	
	while (!q.empty()) {
		Vertex* front = q.front();
		q.pop();
		front->color = "GRAY";
		
		for (auto i = front->neighbors.begin(); i != front->neighbors.end(); i++) {
			if (vertices.at(i->first).color == "WHITE") {
				vertices.at(i->first).prev = front;
				vertices.at(i->first).distance = 0;
				vertices.at(i->first).color = "GRAY";
				vertices.at(i->first).distance += vertices.at(i->first).prev->distance + 1;
				q.push(&vertices.at(i->first));
			}
		}
		
		front->color = "BLACK";
	}
}

int Graph::distance(const string &key) const{
  for ( auto it = vertices.begin(); it != vertices.end(); ++it ) {
    if(key == it->label){
      return it->distance;
    }
  }
  return -1;
}

string Graph::previous(const string &key) const{
  for(auto it = vertices.begin(); it != vertices.end(); ++it){
    if (it->label == key){
      if (it->prev){
        return it->prev->label;
      }
      else{
        return "";
      }
    }
  }
  return "";
}