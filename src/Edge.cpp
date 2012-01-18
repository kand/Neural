#include "Edge.h"

Edge::Edge(Node* origin, Node* dest, double weight){
    this->origin = origin;
    this->dest = dest;
    this->weight = weight;
}

Edge::~Edge(){
}
