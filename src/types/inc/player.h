// Copyright (c) 2023 @authors. GNU GPLv3.

/**
 * @file player.h
 * @brief Defines a struct for a player in a game.
 *
 * ...
 *
 * @authors
 *    Amorese Emanuele
 *    Blanco Lorenzo
 *    Cannito Antonio
 *    Fidanza Simone
 *    Lecini Fabio
 *
 * @date 2023-05-06 13:26
 * @version 1.0
 * @copyright GNU GPLv3
 */

#ifndef PLAYER_TYPE_H
#define PLAYER_TYPE_H

#include <limits.h>

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

/**
 * @brief The initial position of a player.
 */
#define INITIAL_POSITION 0

/**
 * @brief The initial score of a player.
 */
#define INITIAL_SCORE 0

/**
 * @brief The initial turn of a game.
 */
#define INITIAL_TURN 0

/**
 * @brief The value that represents that a player is free to move.
 */
#define NO_TURNS_BLOCKED 0

/**
 * @brief The number of turns to block a player if they land on the inn square.
 */
#define INN_BLOCK 3

/**
 * @brief The value that represents an indefinite blocking.
 */
#define INDEF_BLOCK INT_MAX

/**
 * @brief The dice roll required for a player to escape from a well or prison.
 */
#define ESCAPE_ROLL1 5

/**
 * @brief The alternate dice roll required for a player to escape from a well or
 *        prison.
 */
#define ESCAPE_ROLL2 7

/**
 * @brief The maximum length of a player's username.
 */
#define MAX_USERNAME_LENGTH 3

/**
 * @brief The offset used for generating unique IDs.
 *
 * This constant defines the offset value used for generating unique IDs for
 * players or entities.
 */
#define ID_OFFSET 100

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

/**
 * @brief Defines a struct for a player in the game.
 *
 * This struct contains the information needed to define a player in the game,
 * such as their username, ID, current position, current score, and the
 * number of turns they are blocked for.
 *
 * @var Player::username
 * The username of the player, which must be no more than @c MAX_USERNAME_LENGTH
 * characters long.
 *
 * @var Player::id
 * The identifier that is unique for each player. It's based on the username.
 *
 * @var Player::position
 * The current position of the player on the game board.
 *
 * @var Player::score
 * The current score of the player.
 *
 * @var Player::turns_blocked
 * The number of turns the player is blocked for.
 */
typedef struct Player {
  char username[MAX_USERNAME_LENGTH + 1];  ///< The username of the player.
  int id;                                  ///< The player's unique identifier
  int position;       ///< The current position of the player.
  int score;          ///< The current score of the player.
  int turns_blocked;  ///< The number of turns the player is blocked for.
} Player;

/**
 * @brief Sets the username of a player.
 *
 * This function sets the username of the specified player to the given value.
 * The username is stored as a string, and it will be truncated to a maximum of
 * @c MAX_USERNAME_LENGTH characters plus a ".3" suffix if it is longer than
 * that.
 *
 * @param[in,out] pl       A pointer to the player whose username will be set.
 * @param[in]     username A pointer to the string containing the new username.
 *
 * @return void.
 */
void set_username(Player *pl, const char *username);

/**
 * @brief Gets the username of a player.
 *
 * This function returns the current username of the specified player as a
 * constant string.
 *
 * @param[in] pl A pointer to the player whose username will be retrieved.
 *
 * @return A pointer to the string containing the player's username.
 */
const char *get_username(const Player *pl);

/**
 * @brief Sets the ID of a player based on their username.
 *
 * This function calculates the ID for the specified player based on their
 * username. The ID is generated by treating the characters of the username as
 * digits of a @c base-ID_OFFSET number. The resulting ID is then assigned to
 * the player.
 *
 * @param[in,out] pl A pointer to the player whose ID will be set.
 *
 * @return void.
 */
void set_id(Player *pl);

/**
 * @brief Gets the ID of a player.
 *
 * This function returns the current ID of the specified player as an integer
 * value.
 *
 * @param[in] pl A pointer to the player whose ID will be retrieved.
 *
 * @return The ID of the player.
 */
const int get_id(Player *pl);

/**
 * @brief Sets the position of a player.
 *
 * This function sets the position of the specified player to the given value.
 * The position represents the current square that the player is on.
 *
 * @param[in,out] pl       A pointer to the player whose position will be set.
 * @param[in]     position The new position for the player.
 *
 * @return void.
 */
void set_position(Player *pl, int position);

/**
 * @brief Gets the position of a player.
 *
 * This function returns the current position of the specified player.
 * The position represents the current square that the player is on.
 *
 * @param[in] pl A pointer to the player whose position will be retrieved.
 *
 * @return The current position of the player.
 */
const int get_position(const Player *pl);

/**
 * @brief Sets the score of a player.
 *
 * This function sets the score of the specified player to the given value.
 * The score represents the number of points that the player has accumulated.
 *
 * @param[in,out] pl    A pointer to the player whose score will be set.
 * @param[in]     score The new score for the player.
 *
 * @return void.
 */
void set_score(Player *pl, int score);

/**
 * @brief Gets the score of a player.
 *
 * This function returns the current score of the specified player.
 * The score represents the number of points that the player has accumulated.
 *
 * @param[in] pl A pointer to the player whose score will be retrieved.
 *
 * @return The current score of the player.
 */
const int get_score(const Player *pl);

/**
 * @brief Sets the number of turns that a player is blocked for.
 *
 * This function sets the number of turns that the specified player is blocked
 * for to the given value. If the player is not blocked, this value should be 0.
 *
 * @param[in, out] pl            A pointer to the player whose turns_blocked
 *                               value will be set.
 * @param[in]      turns_blocked The new number of turns that the player is
 *                               blocked for.
 *
 * @return void.
 */
void set_turns_blocked(Player *pl, int turns_blocked);

/**
 * @brief Gets the number of turns that a player is blocked for.
 *
 * This function returns the number of turns that the specified player is
 * blocked for. If the player is not blocked, this value will be 0.
 *
 * @param[in] pl A pointer to the player whose turns_blocked value will be
 *               retrieved.
 *
 * @return The number of turns that the player is blocked for.
 */
const int get_turns_blocked(const Player *pl);

#endif  // !PLAYER_TYPE_H