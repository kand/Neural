#ifndef EDGE_H
#define EDGE_H

class Node;
class Edge
{
    public:
        Edge(Node* origin, Node* dest, double weight);
        virtual ~Edge();

        Node* getDest(){ return dest; }
        void setDest(Node* node){ dest = node; }

        Node* getOrigin(){ return origin; }
        void setOrigin(Node* node){ origin = node; }

        double getWeight(){ return weight; }
        void setWeight( double value ){ weight = value; }

    protected:

    private:
        Node* origin;
        Node* dest;

        double weight;
};

#endif // EDGE_H
