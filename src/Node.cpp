#include "Node.h"

#include <math.h>

Node::Node(){
    outputValue = 1.0;
}

Node::~Node(){
}

double Node::activate(){
    double output = calculateInput();

    // logistic activation function
    //output = 1/(1+exp(output));

    // hard threshold activation function
    if(output > 0.5) output = 1;
    else output = 0;

    this->outputValue = output;

    return outputValue;
}

double Node::calculateInput(){
    double input = 0;

    // add incoming outputs modifed by their edge weight
    for(unsigned i = 0; i < indegrees.size(); i++){
        input += indegrees[i]->getWeight()
                * indegrees[i]->getOrigin()->getOutputValue();
    }

    return input;
}
