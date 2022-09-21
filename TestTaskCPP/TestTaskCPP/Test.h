#pragma once
#include "InitialData.h"

const double ABSOLUTE_ERROR = 10e-1;
const int MAX_TIME = 2000;

namespace testStand
{
	template <typename E>
	class TestStand
	{
		int index;
		double engine_T;
		double envir_T;
		E* engine;

	public:
		int RunEngine();
		TestStand(E& engine, const double envir_T);
	};

	template<typename E>
	TestStand<E>::TestStand(E& engine, const double envir_T)
	{
		index = 0;
		this->engine = &engine;
		this->engine->m = engine.M[index];
		this->engine->v = engine.V[index];
		engine_T = envir_T;
		this->envir_T = envir_T;

	}


	template<typename T>
	int TestStand<T>::RunEngine()
	{
		double a = engine->m / engine->I;
		double eps = engine->over_T - engine_T;
		int time = 0;
		while (eps > ABSOLUTE_ERROR && time < MAX_TIME)
		{
			time++;
			engine->v += a;
			if (index < engine->M.size() - 2) {
				index += engine->v < engine->V[index + 1] ? 0 : 1;
			}
			double up = (engine->v - engine->V[index]);
			double down = (engine->V[index + 1] - engine->V[index]);
			double factor = (engine->M[index + 1] - engine->M[index]);
			engine->m= up / down * factor + engine->M[index];
			engine_T += engine->Vc(envir_T, engine_T) + engine->Vh();

			eps = engine->over_T - engine_T;
			a = engine->m / engine->I;
		}
		return time;
	}

}