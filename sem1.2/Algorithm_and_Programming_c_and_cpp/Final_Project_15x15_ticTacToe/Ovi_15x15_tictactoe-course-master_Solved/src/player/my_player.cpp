
#include "my_player.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

namespace ttt::my_player {

using game::State;
using game::Sign;
using game::Point;

void MyPlayer::set_sign(Sign sign) {
  m_sign = sign;//set my sign (X or O)
}

const char *MyPlayer::get_name() const {
  return m_name;//name of the player
}

Sign MyPlayer::get_enemy(Sign s) {//select enemy sign
  return s == Sign::X ? Sign::O : Sign::X;
    //if X is my sign, O is enemy and vice versa
}

bool MyPlayer::is_valid_empty(const State &state, int x, int y) {
  return state.get_value(x, y) == Sign::NONE;//returns true if the cell is empty
}

bool MyPlayer::is_in_bounds(int x, int y, int cols, int rows) {
  return x >= 0 && x < cols && y >= 0 && y < rows;//returns true if the cell is in bounds
}

bool MyPlayer::is_winning_move(State state, int x, int y, Sign sign) {//returns true if the move is winning
  if (!is_valid_empty(state, x, y)) return false;
  if (state.process_move(sign, x, y) == game::MoveResult::ERROR) return false;//invalid move
  return state.get_status() == game::Status::ENDED && state.get_winner() == sign;
}

bool MyPlayer::is_manual_winning_opportunity(const State &state, int x, int y, Sign sign) {//returns true if the move is winning
  if (!is_valid_empty(state, x, y)) return false;
  const int dirs[4][2] = {{1,0}, {0,1}, {1,1}, {1,-1}};//->,top,\,/
  const int win_len = 5;

  for (int d = 0; d < 4; ++d) {//forward
    int count = 1;//simulate

    for (int i = 1; i < win_len; ++i) {
      int nx = x + dirs[d][0]*i;
      int ny = y + dirs[d][1]*i;
      if (!is_in_bounds(nx, ny, state.get_opts().cols, state.get_opts().rows)) break;
      if (state.get_value(nx, ny) == sign) count++;
      else break;
    }

    for (int i = 1; i < win_len; ++i) {
      int nx = x - dirs[d][0]*i;
      int ny = y - dirs[d][1]*i;
      if (!is_in_bounds(nx, ny, state.get_opts().cols, state.get_opts().rows)) break;
      if (state.get_value(nx, ny) == sign) count++;//if the cell contains the same sign 
      else break;
    }
    if (count >= win_len) return true;
  }
  return false;
}


//to understad situatioin
//higher score = better for my bot
//lower score = better for enemy
//using scores
int MyPlayer::evaluate_board(const State &state, Sign self, Sign enemy) {
  static const int dirs[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
  int score = 0;
  
  const int rows = state.get_opts().rows;
  const int cols = state.get_opts().cols;

  for (int y = 0; y < rows; ++y) {//full board
    for (int x = 0; x < cols; ++x) {
      Sign s = state.get_value(x, y);//get sign at position(x,y)
      if (s == Sign::NONE) continue;//skip empty cells

      for (int d = 0; d < 4; ++d) {//5 cells ->top,\,/
        int count = 0, open_ends = 0;//same sign and empty cells

        for (int i = 0; i < 5; ++i) {
          int nx = x + dirs[d][0] * i;
          int ny = y + dirs[d][1] * i;

          if (!is_in_bounds(nx, ny, cols, rows)) break;//stop if out of bounds

          Sign val = state.get_value(nx, ny);
          if (val == s) count++;
          else if (val == Sign::NONE) {
             open_ends++; break;
          }

          else break;//enemy sign : stop
        }

        for (int i = 1; i < 5; ++i) {//4 cells
          int nx = x - dirs[d][0] * i;
          int ny = y - dirs[d][1] * i;
          
          if (!is_in_bounds(nx, ny, cols, rows)) break;
          Sign val = state.get_value(nx, ny);
          
          if (val == s) count++;
          else if (val == Sign::NONE) {
            open_ends++; break;
          }
         
          else break;
        }

        if (count >= 5) return s == self ? 1000000 : -1000000;//max score win

        //heuristic scoring
        int base = 0;
        if (count == 4) base = open_ends == 2 ? 3500 : 1500;
        else if (count == 3) base = open_ends == 2 ? 400 : 120;
        else if (count == 2) base = open_ends == 2 ? 60 : 20;

        else base = count;

       int center_bonus = ((x > cols/3 && x < 2*cols/3) && (y > rows/3 && y < 2*rows/3)) ? 5 : 0;
        if (s == self) score += base + center_bonus;//adding setuation under my sign
        else score -= base * 2;//subtracting enemy good situation

      }
    }
  }
  return score;
}


//recursively evaluates board outcomes using Minimax with alpha-beta pruning
//maximizing = true -> my turn
//maximizing = false -> enemy turn
//alpha = best score for maximizing player
//beta = best score for minimizing player
//returns best score
//depth = 0 -> leaf node normally 
//if not working then depth++
//depth = 1 -> one move ahead
int MyPlayer::minimax(State state, int depth, int alpha, int beta, bool maximizing, Sign self, Sign enemy) {
  if (depth == 0 || state.get_status() == game::Status::ENDED) {
    return evaluate_board(state, self, enemy);
  }

  int best = maximizing ? -1000000 : 1000000;//ini base score : very low for maximizing and very high for minimizing
  const int rows = state.get_opts().rows;
  const int cols = state.get_opts().cols;

  for (int y = 0; y < rows; ++y) {
    for (int x = 0; x < cols; ++x) {
      if (!is_valid_empty(state, x, y)) continue;

      State next = state;//simulate move a new game state

      if (next.process_move(maximizing ? self : enemy, x, y) == game::MoveResult::ERROR) continue;//applying move for either max-ing or min-ing player

      int score = minimax(next, depth - 1, alpha, beta, !maximizing, self, enemy);//recursivly evaluate the next state

      if (maximizing) {//if maximizing : choose the higher score
        if (score > best) best = score;
        if (score > alpha) alpha = score;//update alpha
      } 
      else {//if minimizing : choose the lower score
        if (score < best) best = score;
        if (score < beta) beta = score;//update beta
      }

      if (beta <= alpha) return best;//alpha-beta pruning: cut off branches 
    }
  }

  return best;
}

//decision function
Point MyPlayer::make_move(const State &state) {
 
  const int rows = state.get_opts().rows;
  const int cols = state.get_opts().cols;
 
  Sign enemy = get_enemy(m_sign);//enemy

  
  if (state.get_move_no() == 0) {//center try first
    int cx = cols / 2, cy = rows / 2;
    if (state.get_value(cx, cy) == Sign::NONE) return {cx, cy};
    for (int y = 0; y < rows; ++y)
      for (int x = 0; x < cols; ++x)
        if (is_valid_empty(state, x, y))
          return {x, y};
  }

for (int y = 0; y < rows; ++y) {//checking board position
  for (int x = 0; x < cols; ++x) {
    if (!is_valid_empty(state, x, y)) continue;

    if (is_winning_move(state, x, y, m_sign)) return {x, y};//win
    if (is_winning_move(state, x, y, enemy)) return {x, y};//block win
    if (is_manual_winning_opportunity(state, x, y, m_sign)) return {x, y};
    if (is_manual_winning_opportunity(state, x, y, enemy)) return {x, y};
    if (is_open_four_threat(state, x, y, enemy)) return {x, y};//block _OOOO_
    if (is_critical_threat(state, x, y, enemy)) return {x, y}; //block fork
    if (is_open_four_threat(state, x, y, m_sign)) return {x, y};//create _OOOO_
    if (is_critical_threat(state, x, y, m_sign)) return {x, y};//create fork
  }
}


  struct ScoredCell { int x, y, score; };// evaluate and sort top candidates by board score
  ScoredCell candidates[225];
  int count = 0;

  for (int y = 0; y < rows; ++y) {//generating all possible moves with heuristic scores
    for (int x = 0; x < cols; ++x) {
      if (is_valid_empty(state, x, y)) {
        State next = state;
        if (next.process_move(m_sign, x, y) == game::MoveResult::ERROR) continue;
        int score = evaluate_board(next, m_sign, enemy);
        candidates[count++] = {x, y, score};//storing move and it's score
      }
    }
  }

  //shuffling , partial sorting(same score or not)
  for (int i = count - 1; i > 0; --i) {
    int j = std::rand() % (i + 1);
    ScoredCell tmp = candidates[i];//swp
    candidates[i] = candidates[j];
    candidates[j] = tmp;
  } 

    //sort candidates based on the score
  int limit = (count < 4) ? count : 4;
  for (int i = 0; i < limit; ++i) {
    int max_idx = i;
    for (int j = i + 1; j < count; ++j)
      if (candidates[j].score > candidates[max_idx].score)
        max_idx = j;
    ScoredCell tmp = candidates[i];
    candidates[i] = candidates[max_idx];
    candidates[max_idx] = tmp;
  }

  int best_score = -1000000;
  Point best_move = {0, 0};

    // cout << "top 5 possible moves \n";
    // for (int i = 0; i < limit; ++i) {
    //     cout << "move: (" << candidates[i].x << ", " << candidates[i].y <<")"<< endl;
    // }

    for (int i = 0; i < limit; ++i) {
      int x = candidates[i].x, y = candidates[i].y;
      State next = state;
      if (next.process_move(m_sign, x, y) == game::MoveResult::ERROR) continue;

      int depth = 1; //keeping depth limited
      int score = minimax(next, depth, -1000000, 1000000, false, m_sign, enemy);
      if (score > best_score) {
        best_score = score;
        best_move = {x, y};
      }
  }

  //fallback move if no good candidates found
  if (limit == 0) {
    for (int y = 0; y < rows; ++y)
      for (int x = 0; x < cols; ++x)
        if (is_valid_empty(state, x, y))
          return {x, y};
  }

   //step 9: print best Move
    // cout << "best move: (" << best_move.x << ", " << best_move.y << ") "<< endl;


  return best_move;
}

bool MyPlayer::is_open_four_threat(const State &state, int x, int y, Sign sign) {
  const int dirs[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};

  const int cols = state.get_opts().cols;
  const int rows = state.get_opts().rows;

  for (int d = 0; d < 4; ++d) {//checking all 4 directions
    for (int i = -4; i <= 0; ++i) {
      int count = 0, empty_count = 0;

      for (int j = 0; j < 5; ++j) {
        int nx = x + dirs[d][0] * (i + j);
        int ny = y + dirs[d][1] * (i + j);

        if (!is_in_bounds(nx, ny, cols, rows)) break;

        Sign val = state.get_value(nx, ny);

        if (nx == x && ny == y) val = sign; // simulate placing here
        if (val == sign) count++;//counting empty spot
        else if (val == Sign::NONE) empty_count++;
        else break;
      }
      //_xxxx_
      if (count == 4 && empty_count >= 2) return true;
    }
  }
  return false;
}


bool MyPlayer::is_critical_threat(const State& state, int x, int y, Sign sign) {//returns true if the move is critical threat
  const int dirs[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};//->,top,\,/

  const int cols = state.get_opts().cols;
  const int rows = state.get_opts().rows;

  int threat_count = 0;

  // forward threat
  for (int d = 0; d < 4; ++d) {//checking all 4 directrions
    int count = 1;
    int open_ends = 0;

    for (int i = 1; i < 5; ++i) {//direction
      int nx = x + dirs[d][0]*i;
      int ny = y + dirs[d][1]*i;

      if (!is_in_bounds(nx, ny, cols, rows)) break;//stop if out of bounds
      Sign val = state.get_value(nx, ny);//get sign at position(x,y)
      if (val == sign) count++;
      else if (val == Sign::NONE) { open_ends++; break; }//check if the cell is empty
      else break;
    }


    //backward threat
    for (int i = 1; i < 5; ++i) {
      int nx = x - dirs[d][0]*i;
      int ny = y - dirs[d][1]*i;

      if (!is_in_bounds(nx, ny, cols, rows)) break;//stop if out of bounds
      Sign val = state.get_value(nx, ny);//get sign at position(x,y)
      if (val == sign) count++;
      else if (val == Sign::NONE) { open_ends++; break; }
      else break;
    }
    //_xxxx_
    if (count == 4 && open_ends >= 1) threat_count++;//critical threat
  }

  return threat_count >= 2;//double threat
}


} // namespace ttt::my_player
