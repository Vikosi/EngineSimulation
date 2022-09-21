#pragma once
#include <vector>
using namespace std;

namespace simulationEngines {
	struct Engine1Struct
	{
		double I = 0.1;
		int over_T = 110;
		double Hm = 0.01;
		double Hv = 0.0001;
		double C = 0.1;
		vector<int> M = { 20, 75, 100, 105, 75, 0 };
		double m = M[0];
		vector<int> V = { 0, 75, 150, 200, 250, 300 };
		double v = V[0];
		double Vc(double envir_T, double engine_T);
		double Vh();
		bool Start;
		int timeStart;

	};
};