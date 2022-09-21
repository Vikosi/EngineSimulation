
#include <iostream>
#include "InputOutputData.h"
#include "Test.h"
using namespace std;
int main()
{
	double envir_T = dataInputOutput::GetTemperature();
	simulationEngines::Engine1Struct engine;
	testStand::TestStand<simulationEngines::Engine1Struct> stand(engine, envir_T);
	dataInputOutput::WriteTime(stand.RunEngine());
	return 0;
}