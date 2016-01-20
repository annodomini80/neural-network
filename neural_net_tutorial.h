#ifndef _NEURAL_NETWORK_H
#define _NEURAL_NETWORK_H

using namespace std;
typedef unsigned int uint;

class Neuron;
typedef vector<Neuron> Layer;

class Neuron{
	public:
		Neuron(uint &numOut);
		void set(double val);
		void feedForward(const Layer &prevLayer);

	private:
		double m_outVal;
		double randGen();
		vector<double> m_weights;
		vector<double> m_deltaWeights;
};


class Net{
	public:
		Net(vector<uint> &network);
		void feedForward(const vector<double> &inputVal);

	private:
		vector<unsigned int> topology;
		vector<Layer> m_layers;
};

#endif
