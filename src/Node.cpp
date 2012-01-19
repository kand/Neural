#include "Node.h"

#include <math.h>

Node::Node(){
    init(1.0);
}

Node::Node(double initOutputValue){
    init(initOutputValue);
}

Node::~Node(){
}

double Node::logisticActivate(){
    return 1/(1 + exp(this->calculateInput()));
}

double Node::hardThresholdActivate(double threshold){
    if(this->calculateInput() > threshold) return 1;
    return 0;
}

double Node::calculateInput(){
    this->inputValue = 0;

    // add incoming outputs modifed by their edge weight
    for(unsigned i = 0; i < indegrees.size(); i++){
        this->inputValue +=
                indegrees[i]->getWeight()
                * indegrees[i]->getOrigin()->getOutputValue();
    }

    return this->inputValue;
}

void Node::init(double initOutputValue){
    this->outputValue = initOutputValue;
}
