#include "InitialData.h"

namespace simulationEngines
{
	double Engine1Struct::Vc(double envir_T, double engine_T)
	{
		return C*(envir_T-engine_T);
	}
	double Engine1Struct::Vh()
	{
		return m*Hm + (v*v)*Hv;
	}
}