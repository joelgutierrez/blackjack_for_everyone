//
//  deck.hpp
//  blackjack
//
//  Created by Joel Gutierrez on 10/17/17.
//  Copyright © 2017 Joel Gutierrez. All rights reserved.
//

#ifndef deck_hpp
#define deck_hpp

#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>

enum {
    ACE = 11,
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK = 10,
    QUEEN = 10,
    KING = 10,
    NUM_FACE_TYPES = 4,
    FACES = 13,
    NUM_CARDS = 52,
    TOTAL_CARDS_OF_VALUE_TEN = 16,
    MAX_CARD_COUNT = 21,
    DEALER = 1,
    MIN_PLAYERS = 2,
    MAX_PLAYERS = 5,
    EASY = 1,
    MEDIUM = 2,
    HARD = 3,
    HARD_MIN_COUNT = 17,
    MEDIUM_MIN_COUNT = 18,
    EASY_MIN_COUNT = 19
};

class Deck {
  public:
    Deck();
    void shuffle_deck();
    int get_top_card_and_make_bookkeeping_updates();
    int get_deck_size();
    void print_remaining_vals_in_deck();
    void print_remaining_card_counts();
    
  private:
    void initialize_cards_with_values();
    void initialize_count_left_for_each_value();
    int card[52];
    int top_index;
    int deck_size;
    void update_card_counts(int);
    int aces_left, twos_left, threes_left, fours_left, fives_left;
    int sixes_left, sevens_left, eights_left, nines_left, tens_left;
};

#endif /* deck_hpp */
