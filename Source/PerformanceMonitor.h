#pragma once
#include <chrono>

class PerformanceMonitor
{
private:
	double m_duration;
	bool m_profiling;
	std::chrono::high_resolution_clock::time_point m_time;

public:
	void StartProfiling();
	void StopProfiling();
	double ExecutionTime();
	bool IsProfiling();

	PerformanceMonitor() {
		m_duration = 0;
		m_profiling = false;
	};
};
