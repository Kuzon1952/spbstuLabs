#pragma once

#include "core/game.hpp"

namespace ttt::my_player {

using game::Event;
using game::IPlayer;
using game::Point;
using game::Sign;
using game::State;

//AI player for Tic Tac Toe 15X15 (mine)
class MyPlayer : public IPlayer {
  
  Sign m_sign = Sign::NONE;//my sign (X or O)
  const char *m_name;//name 

private:
  //utility functions 

  static Sign get_enemy(Sign s);//enemy sign
  static bool is_valid_empty(const State &state, int x, int y);//returns true if the cell is empty
  static bool is_in_bounds(int x, int y, int cols, int rows);//returns true if the cell is in bounds
  static bool is_winning_move(State state, int x, int y, Sign sign);//returns true if the move is winning
  static bool is_manual_winning_opportunity(const State &state, int x, int y, Sign sign);//returns true if the move is winning

  static int evaluate_board(const State &state, Sign self, Sign enemy);//evaluate the board
  static int minimax(State state, int depth, int alpha, int beta, bool maximizing, Sign self, Sign enemy);//recursively evaluates board outcomes using Minimax with alpha-beta pruning
  bool is_open_four_threat(const game::State& state, int x, int y, game::Sign sign);//_OOOO_ threat
  bool is_critical_threat(const State& state, int x, int y, Sign sign);//returns true if the move is critical threat


  public:
  //interface functions

  MyPlayer(const char *name) : m_sign(Sign::NONE), m_name(name) {}//name constructor
  void set_sign(Sign sign) override;//X or O
  Point make_move(const State &game) override;//main decision function
  const char *get_name() const override;//returns name 
};

};//namespace ttt::my_player