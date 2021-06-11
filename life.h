#pragma once

/**
 * @brief Print usage and exit with code 1
 */
void usage_and_die();

/**
 * @brief Read clip mode from the command linea arguments
 *
 * @param argc Number of args
 * @param argv Array of arguments
 * @return true if mode = clip, false if circular
 */
bool is_clip(int argc, char **argv);

/**
 * @brief Handle SDL events to see if the app should close
 * @returns whether app should close
 */
bool should_quit();