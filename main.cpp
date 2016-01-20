#include <stdio>
#include <vector>
#include <cstdlib>
#include <random>
#include "neural_network.h"

using namespace std;

int main(){


    vector<unsigned int> network;
    network.push_back(5);
    network.push_back(3);
    network.push_back(2);
    cout << network.size() << endl;

    Net myNet(network);

    return 0;
};
