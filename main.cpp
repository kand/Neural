#include <iostream>

#include <Graph.h>

using namespace std;

int main()
{
    // Build a 4 node perceptron

    Graph g;

    // Input nodes
    Node* i_node1 = new Node();
    g.addNode(i_node1);
    Node* i_node2 = new Node();
    g.addNode(i_node2);

    // Output node
    Node* o_node3 = new Node();
    g.addNode(o_node3);

    // dummy edge for learning
    Node* i_node0 = new Node();
    i_node0->setOutputValue(1);
    Edge* edge0 = new Edge(i_node0,o_node3,0);

    Edge* edge1 = new Edge(i_node1,o_node3,0);
    Edge* edge3 = new Edge(i_node2,o_node3,0);

    o_node3->addInDegree(edge0);
    o_node3->addInDegree(edge1);
    o_node3->addInDegree(edge3);

    // learn NAND
    cout << " x1 | x2 | y | error | corr | w0 | w1 | w2 |" << endl;

    // training set {x1,x2,y}
    double training[4][3] = {{0,0,1},{0,1,1},{1,0,1},{1,1,0}};
    double learnRate = 0.1;
    unsigned trainingIterations = 9;

    unsigned sizei = sizeof(training)/sizeof(double[3]);

    for(unsigned round = 0; round < trainingIterations; round++){

        cout << "----------- round " << round << " -----------" << endl;

        for(unsigned i = 0; i < sizei; i++){

            // set input
            i_node1->setOutputValue(training[i][0]);
            i_node2->setOutputValue(training[i][1]);

            // activate node, collect data
            double result = o_node3->activate();

            double error = training[i][2] - result;
            double correction = learnRate * error;

            cout << " | " << training[i][0] << " | " << training[i][1] << " | " << result << " | " << error << " | " << correction << " | ";

            // modify weights
            for(unsigned j = 0; j < o_node3->getInDegrees().size(); j++){
                double incomingGuess = o_node3->getInDegrees()[j]->getOrigin()->getOutputValue();
                double incomingWeight = o_node3->getInDegrees()[j]->getWeight();

                if((correction > 0 && incomingGuess == training[i][2])              // overall guess right, reward those edges that guessed correctly
                        || (correction < 0 && incomingGuess != training[i][2])){    // overall guess wrong, hurt those edges that guessed wrong
                    // modify weights appropriately
                    double newWeight = incomingWeight + correction;

                    o_node3->getInDegrees()[j]->setWeight(newWeight);
                }

                cout << o_node3->getInDegrees()[j]->getWeight() << " | ";
            }

            cout << endl;
        }
    }

    return 0;
}
