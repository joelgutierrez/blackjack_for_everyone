//
//  dealer.cpp
//  blackjack
//
//  Created by Joel Gutierrez on 10/17/17.
//  Copyright © 2017 Joel Gutierrez. All rights reserved.
//

#include "dealer.hpp"

Dealer::Dealer(Deck *deck)
: Person(deck), min_hit_count(HARD_MIN_COUNT)
{}

bool Dealer::is_requesting_card() {
    return (turn_status && hand_count < min_hit_count);
}

void Dealer::set_min_hit_count(int min_count_selected) {
    min_hit_count = min_count_selected;
}

void Dealer::print_win() {
}

void Dealer::print_lose() {
    std::cout << "Dealer loses to all active players" << std::endl;
}

void Dealer::print_tie() {
}

void Dealer::display_user_options() {
    std::cout << "Current count: " << get_hand_count() << std::endl;
}
