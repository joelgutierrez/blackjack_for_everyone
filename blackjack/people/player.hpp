//
//  player.hpp
//  blackjack
//
//  Created by Joel Gutierrez on 10/17/17.
//  Copyright © 2017 Joel Gutierrez. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include "person.hpp"
#include "deck.hpp"

class Player : public Person {
  public:
    Player(Deck *);
    bool is_requesting_card();
    void print_win_lose_tie_vs_dealer_count(int);
    void print_win();
    void print_lose();
    void print_tie();
    void display_user_options();
};

#endif /* player_hpp */
