#ifndef NODE_H
#define NODE_H

#include <vector>

#include "Edge.h"

using namespace std;

class Node
{
    public:
        Node();
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

        /*
         * Don't think I need this stuff
         *
        vector<Edge*> getOutDegrees(){ return outdegrees; }
        void addOutDegree(Edge* edge){ outdegrees.push_back(edge); }
        void removeOutDegree(Edge* edge){
            // loop through outdegrees to find given edge
            for(unsigned i = 0; i < outdegrees.size(); i++){
                if(edge == outdegrees[i]){
                    outdegrees.erase(outdegrees.begin() + i);
                    break;
                }
            }
        }
        */

        double getOutputValue(){ return outputValue; }
        void setOutputValue(double value){ outputValue = value; }

        double activate();

    protected:
        double calculateInput();

    private:
        vector<Edge*> indegrees;
        //vector<Edge*> outdegrees;

        double outputValue;
};

#endif // NODE_H
