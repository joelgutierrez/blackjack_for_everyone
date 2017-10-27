//
//  deck.cpp
//  blackjack
//
//  Created by Joel Gutierrez on 10/17/17.
//  Copyright © 2017 Joel Gutierrez. All rights reserved.
//

#include "deck.hpp"

Deck::Deck()
: top_index(0), deck_size(NUM_CARDS)
{
    initialize_cards_with_values();
    shuffle_deck();
    initialize_count_left_for_each_value();
};

void Deck::initialize_cards_with_values() {    
    for (int i = 0; i < NUM_CARDS;) {
        card[i++] = ACE;
        card[i++] = TWO;
        card[i++] = THREE;
        card[i++] = FOUR;
        card[i++] = FIVE;
        card[i++] = SIX;
        card[i++] = SEVEN;
        card[i++] = EIGHT;
        card[i++] = NINE;
        card[i++] = TEN;
        card[i++] = JACK;
        card[i++] = QUEEN;
        card[i++] = KING;
    }
}

void Deck::initialize_count_left_for_each_value() {
    aces_left = NUM_FACE_TYPES; twos_left = NUM_FACE_TYPES; threes_left = NUM_FACE_TYPES; fours_left = NUM_FACE_TYPES;
    fives_left = NUM_FACE_TYPES; sixes_left = NUM_FACE_TYPES; sevens_left = NUM_FACE_TYPES; eights_left = NUM_FACE_TYPES;
    nines_left = NUM_FACE_TYPES; tens_left = TOTAL_CARDS_OF_VALUE_TEN;
}

void Deck::shuffle_deck() {
    srand( static_cast<unsigned int>(time(0)) );
    for(int i = 0; i < NUM_CARDS; i++) {
        int random_index = rand() % NUM_CARDS;
        int curr_i_val = card[i];
        card[i] = card[random_index];
        card[random_index] = curr_i_val;
    }
}

int Deck::get_top_card_and_make_bookkeeping_updates() {
    int top_card_value = card[top_index];
    update_card_counts(top_card_value);
    top_index++;
    deck_size--;
    return top_card_value;
}

int Deck::get_deck_size() {
    return deck_size;
}

void Deck::update_card_counts(int card_val) {
    if(card_val == ACE) {
        aces_left--;
    } else if (card_val == TWO) {
        twos_left--;
    } else if (card_val == THREE) {
        threes_left--;
    } else if (card_val == FOUR) {
        fours_left--;
    } else if (card_val == FIVE) {
        fives_left--;
    } else if (card_val == SIX) {
        sixes_left--;
    } else if (card_val == SEVEN) {
        sevens_left--;
    } else if (card_val == EIGHT) {
        eights_left--;
    } else if (card_val == NINE) {
        nines_left--;
    } else if (card_val == TEN) {
        tens_left--;
    }
}

void Deck::print_remaining_vals_in_deck() {
    for(int i = 0; i < NUM_CARDS; i++) {
        std::cout << get_top_card_and_make_bookkeeping_updates() << std::endl;
        std::cout << std::endl;
    }
}

void Deck::print_remaining_card_counts() {
    std::cout << "Remaining quantities: " << std::endl;
    std::cout << "aces: " << std::setw(4) << aces_left << std::endl;
    std::cout << "twos: " << std::setw(4) << twos_left << std::endl;
    std::cout << "threes: " << std::setw(2) << threes_left << std::endl;
    std::cout << "fours: " << std::setw(3) << fours_left << std::endl;
    std::cout << "fives: " << std::setw(3) << fives_left << std::endl;
    std::cout << "sixes: " << std::setw(3) << sixes_left << std::endl;
    std::cout << "sevens: " << std::setw(2) << sevens_left << std::endl;
    std::cout << "eights: " << std::setw(2) << eights_left << std::endl;
    std::cout << "nines: " << std::setw(3) << nines_left << std::endl;
    std::cout << "tens: " << std::setw(4) << tens_left << std::endl;
    std::cout << std::endl;
}

