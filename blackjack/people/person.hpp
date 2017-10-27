//
//  person.hpp
//  blackjack
//
//  Created by Joel Gutierrez on 10/17/17.
//  Copyright © 2017 Joel Gutierrez. All rights reserved.
//

#ifndef person_hpp
#define person_hpp

#include <iostream>
#include <stdio.h>
#include "deck.hpp"

class Person {
public:
    Person(Deck *);
    virtual ~Person();
    int get_hand_count();
    void make_decisions_for_turn();
    void set_hand_count(int);
    void update_game_status();
    void print_lose_if_went_over_count_limit();
    void print_card_value_from_hit();
    bool get_turn_status();
    bool get_game_status();
    bool is_player_eligible();
    virtual bool is_requesting_card() = 0;
    virtual void print_win() = 0;
    virtual void print_lose() = 0;
    virtual void print_tie() = 0;
    virtual void display_user_options() = 0;
    
protected:
    Deck *deck;
    int hit();
    void stay();
    bool turn_status;
    bool game_status;
    int hand_count;
    bool first_decision_done;
    int card_value_from_hit;
};

#endif /* person_hpp */
