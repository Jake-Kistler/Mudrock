#pragma once


double next_pressure(double left_pressure,double center_pressure,double right_pressure,double r);

std::vector<double> next_pressure_state(const std::vector<double>& current_pressures, double r);
