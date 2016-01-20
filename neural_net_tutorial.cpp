#include "neural_network.h"

Neuron::Neuron(uint &numOut){
	m_outVal = 0;
	for (uint i = 0; i < numOut; ++i ){
		m_weights.push_back(randGen());
		m_deltaWeights.push_back(randGen());
	}
}

void Neuron::set(double val) { m_outVal = val; };
void Neuron::feedForward(const Layer &prevLayer) {};
double Neuron::randGen(){ return (double) rand()/RAND_MAX; };


Net::Net(vector<uint> &network){
	topology = network;

	for (uint num_layer=0; num_layer < topology.size()-1; ++num_layer){
		m_layers.push_back(Layer());
        uint numOut = num_layer == topology.size()-1 ? 0: topology[num_layer+1];

		for (uint num_neuron=0; num_neuron <= topology[num_layer]; ++num_neuron){
			m_layers.back().push_back(Neuron(numOut));
		}
	}
};

void Net::feedForward(const vector<double> &inputVal){
	uint num_layer = 0;	cout << topology.size() << endl;

	//clamp input layer neurons to inputVal
	for (uint i = 0; i < topology[0]; ++i){
		m_layers[0][i].set(inputVal[i]);
	}

	double outVal;
	for (uint num_layer = 1; num_layer <= topology.size()-1; ++num_layer){
		Layer &prevLayer = m_layers[num_layer-1];
		for (uint i = 0; i < topology[num_layer]; ++i){
			m_layers[num_layer][i].feedForward(prevLayer);
		}
	}
}; 
