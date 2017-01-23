#include "PerformanceMonitor.h"
#include <iostream>

void PerformanceMonitor::StartProfiling()
{
	m_profiling = true;
	m_time = std::chrono::high_resolution_clock::now();
}

void PerformanceMonitor::StopProfiling()
{
	m_profiling = false;
	std::chrono::high_resolution_clock::time_point current_time = std::chrono::high_resolution_clock::now();
	m_duration = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - m_time).count();
	std::cout << "The operation took " << m_duration / 1000 << " seconds to complete.\n";
}

double PerformanceMonitor::ExecutionTime()
{
	return m_duration;
}

bool PerformanceMonitor::IsProfiling()
{
	return m_profiling;
}
