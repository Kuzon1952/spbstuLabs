#include "player/my_player.hpp"
#include "core/baseline.hpp"
#include "test_stats.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    std::cout << "Testing MyPlayer vs baseline harder player\n";
    if (argc >= 2) {
        std::srand(atoi(argv[1]));
    }

    
    ttt::my_player::MyPlayer p1("MyPlayer");////поместите вашего игрока сюда
    ttt::game::IPlayer *p2 = ttt::baseline::get_easy_player("BaselineEasy"); //здесь вы можете выбрать между базовыми игроками: сложным и лёгким
    // ttt::game::IPlayer *p2 = ttt::baseline::get_harder_player("BaselineHarder"); //здесь вы можете выбрать между базовыми игроками: сложным и лёгким

    ttt::game::IPlayer *pp1 = &p1, *pp2 = p2;

    // std::swap(pp1, pp2);


    auto result = ttt::test::run_game_tests(*pp1, *pp2, 100); //здесь вы можете изменить количество тестовых итераций ~~ 100
    ttt::test::print_test_results(result, pp1->get_name(), pp2->get_name());
    
    std::swap(pp1, pp2);

    result = ttt::test::run_game_tests(*pp1, *pp2, 100); //здесь вы можете изменить количество тестовых итераций ~~ 100
    ttt::test::print_test_results(result, pp1->get_name(), pp2->get_name());
    
    delete p2;
    return 0;
}