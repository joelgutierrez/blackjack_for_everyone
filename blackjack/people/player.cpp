//
//  player.cpp
//  blackjack
//
//  Created by Joel Gutierrez on 10/17/17.
//  Copyright © 2017 Joel Gutierrez. All rights reserved.
//

#include "player.hpp"

Player::Player(Deck *deck)
: Person(deck)
{}

bool Player::is_requesting_card() {
    int user_request;
    while(true) {
        if(std::cin >> user_request) {
            if(user_request == 0) {
                return false;
            } else if (user_request == 1) {
                return true;
            } else {
                display_user_options();
            }
        } else { //user input is wrong
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            display_user_options();
        }
    }
}

void Player::display_user_options() {
    std::cout << "Current count: " << get_hand_count() << std::endl;
    std::cout << "Enter 1 (hit) or 0 (stay)" << std::endl;
}

void Player::print_win_lose_tie_vs_dealer_count(int dealer_count) {
    if(get_hand_count() == dealer_count) {
        print_tie();
    } else if(get_hand_count() > dealer_count) {
        print_win();
    } else {
        print_lose();
    }
}

void Player::print_win() {
    std::cout << get_hand_count() << " beats dealer" << std::endl;
}

void Player::print_lose() {
    std::cout << get_hand_count() << " loses to dealer" << std::endl;
}

void Player::print_tie() {
    std::cout << get_hand_count() << " ties with dealer" << std::endl;
}
