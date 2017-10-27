//
//  BlackjackGame.hpp
//  blackjack
//
//  Created by Joel Gutierrez on 10/18/17.
//  Copyright © 2017 Joel Gutierrez. All rights reserved.
//

#ifndef BlackjackGame_hpp
#define BlackjackGame_hpp

#include <stdio.h>
#include "deck.hpp"
#include "person.hpp"
#include "player.hpp"
#include "dealer.hpp"
#include <vector>

class BlackjackGame {
  public:
    BlackjackGame(int);
    ~BlackjackGame(); 
    void distribute_cards_to_participants();
    void have_each_person_do_decision();
    void print_game_results();
    void print_results_for_dealer_losing();
    void print_results_for_dealer_being_active(int);
    void print_difficulty_level_menu();
    void initialize_difficulty_level();
    bool does_dealer_have_to_go();
    bool is_dealer_over_limit();
    bool is_difficulty_level_within_range(int);
    
  private:
    Deck *deck;
    int dealer_index;
    void do_player_decisions();
    void do_dealer_decisions();
    void initialize_deck();
    void initialize_all_participants(int);
    void initialize_players(int);
    void initialize_dealer();
    void set_dealer_min_hit_count(int);
    std::vector<Person*> participant_list;
};


#endif /* BlackjackGame_hpp */
