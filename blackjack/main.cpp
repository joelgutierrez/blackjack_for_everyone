//
//  main.cpp
//  blackjack
//
//  Created by Joel Gutierrez on 10/17/17.
//  Copyright © 2017 Joel Gutierrez. All rights reserved.
//

#include <iostream>
#include "deck.hpp"
#include "person.hpp"
#include "player.hpp"
#include "dealer.hpp"
#include "BlackjackGame.hpp"

bool is_num_players_within_range(int);
int get_valid_user_input();

int main(int argc, const char * argv[]) {
    
    int num_of_players = get_valid_user_input();
    BlackjackGame *blackjackgame = new BlackjackGame(num_of_players);
    blackjackgame->initialize_difficulty_level();
    blackjackgame->distribute_cards_to_participants();
    blackjackgame->have_each_person_do_decision();
    blackjackgame->print_game_results();
    
    delete blackjackgame;
    return 0;
}



int get_valid_user_input() {
    int num_of_players = 0;
    while(true) {
        std::cout << "How many players will be playing? (2-5 permitted)" << std::endl;
        std::cout << "Please note that 1 will be a dealer" << std::endl;
        if(std::cin >> num_of_players) {
            if( is_num_players_within_range(num_of_players) ) {
                return num_of_players;
            }
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

bool is_num_players_within_range(int num_of_players) {
    return (num_of_players >= MIN_PLAYERS && num_of_players <= MAX_PLAYERS);
}

