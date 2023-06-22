// Copyright (c) 2023 @authors. GNU GPLv3.

#ifndef HELP_MODULE_H
#define HELP_MODULE_H

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

/**
 * @brief Displays the help menu and handles user input for navigating the menu.
 *
 * The help menu displays a set of options and waits for the user to enter a
 * key. The function reads the user's input and performs actions based on the
 * entered key.
 *
 * Available options:
 * - 'r': Displays the rules file.
 * - 'm': Displays the manual file.
 * - 'b': Exits the help menu and returns to the previous menu.
 *
 * @note This function relies on the following helper functions:
 *       - `print_help_menu()`: Displays the help menu options.
 *       - `display_file(const char* filename)`: Displays the contents of a
 *         file on the screen.
 *
 * @note The function uses the `_getch()` function to read a single character
 *       from the input stream.
 *
 * @return void.
 */
void help_menu();

#endif  // !HELP_MODULE_H
