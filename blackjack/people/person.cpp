//
//  person.cpp
//  blackjack
//
//  Created by Joel Gutierrez on 10/17/17.
//  Copyright © 2017 Joel Gutierrez. All rights reserved.
//

#include "person.hpp"

Person::Person(Deck *deck){
    hand_count = 0;
    turn_status = true;
    game_status = true;
    first_decision_done = false;
    card_value_from_hit = 0;
    this->deck = deck;
}

Person::~Person() {}

void Person::make_decisions_for_turn() {
    while(is_player_eligible()) {
        if(first_decision_done) {
            print_card_value_from_hit();
        }
        display_user_options();
        if(is_requesting_card()) {
            card_value_from_hit = hit();
            first_decision_done = true;
        } else {
            stay();
        }
        update_game_status();
        print_lose_if_went_over_count_limit();
    }
}

void Person::print_lose_if_went_over_count_limit() {
    if (!get_game_status()) {
        print_card_value_from_hit();
        std::cout << "hand count of " << get_hand_count() << " loses" << std::endl;
    }
}

void Person::print_card_value_from_hit() {
    std::cout << "Card value received from hit: " << card_value_from_hit << std::endl;
}

bool Person::is_player_eligible() {
    return ( get_turn_status() && get_game_status() );
}

int Person::hit() {
    int top_card_value = deck->get_top_card_and_make_bookkeeping_updates();
    hand_count = hand_count + top_card_value;
    return top_card_value;
}

void Person::stay() {
    turn_status = false;
}

int Person::get_hand_count() {
    return hand_count;
}
void Person::set_hand_count(int count) {
    hand_count = count;
}

bool Person::get_turn_status() {
    return turn_status;
}

bool Person::get_game_status() {
    
    return game_status;
}

void Person::update_game_status() {
    game_status = hand_count <= MAX_CARD_COUNT;
}
