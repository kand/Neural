#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

#include "Node.h"

using namespace std;

class Graph
{
    public:
        Graph();
        virtual ~Graph();

        vector<Node*> getNodes(){ return nodes; }
        void addNode(Node* node){ nodes.push_back(node); }
        void removeNode(Node* node){
            // loop through nodes to find given node
            for(unsigned i = 0; i < nodes.size(); i++){
                if(node == nodes[i]){
                    nodes.erase(nodes.begin() + i);
                    break;
                }
            }
        }

    protected:

    private:
        vector<Node*> nodes;
};

#endif // GRAPH_H
