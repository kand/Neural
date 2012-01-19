#ifndef NODE_H
#define NODE_H

#include <vector>

#include "Edge.h"

using namespace std;

class Node
{
    public:
        Node();
        Node(double initOutputValue);
        virtual ~Node();

        vector<Edge*> getInDegrees(){ return indegrees; }
        void addInDegree(Edge* edge){ indegrees.push_back(edge); }
        void removeInDegree(Edge* edge){
            // loop through indegrees to find given edge
            for(unsigned i = 0; i < indegrees.size(); i++){
                if(edge == indegrees[i]){
                    indegrees.erase(indegrees.begin() + i);
                    break;
                }
            }
        }

        double getInputValue(){ return inputValue; }

        void setOutputValue(double value){ outputValue = value; }
        double getOutputValue(){ return outputValue; }

        double calculateInput();

        double logisticActivate();
        double hardThresholdActivate(double threshold);

    protected:

    private:
        void init(double initOutputValue);

        vector<Edge*> indegrees;

        double inputValue;
        double outputValue;
};

#endif // NODE_H
