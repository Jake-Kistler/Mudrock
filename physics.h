#pragma once

/**
 * @brief Calculates the pressure of a reservoir cell at the next timestep.
 *
 * @param left_pressure Pressure(in PSI) of the neighboring cell to the left.
 * @param center_pressure Current pressure(in PSI) of the center cell.
 * @param right_pressure Pressure(in PSI) of the neighboring cell to the right.
 * @param r Numerical timestep coefficient.
 *
 * @return Updated pressure of the center cell.
 */

/*
 * Conceptually, each pressure value represents a small cell of porous rock
 * inside the reservoir. The cells are not isolated from one another; fluid
 * can move through the connected pore spaces in the rock.
 *
 * Example:
 *
 *     [ Left Cell ] [ Center Cell ] [ Right Cell ]
 *        3000 psi       1500 psi        1000 psi
 *
 * The higher-pressure left cell tends to push fluid toward the center cell,
 * increasing its pressure. At the same time, the center cell tends to push
 * fluid toward the lower-pressure right cell, decreasing its pressure.
 *
 * In this example, the pressure difference on the left side is larger than
 * the pressure difference on the right side, so the center cell experiences
 * a net increase in pressure.
 *
 * This function calculates the center cell's pressure after one small
 * simulation timestep based on those neighboring pressure differences.
 */
double next_pressure(double left_pressure,double center_pressure,double right_pressure,double r){
    // Finite-difference pressure update for one interior reservoir cell.
    // r controls how strongly neighboring pressure differences affect this timestep.
    return center_pressure + r * (right_pressure - 2 * center_pressure + left_pressure);
}
