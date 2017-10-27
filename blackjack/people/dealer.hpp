//
//  dealer.hpp
//  blackjack
//
//  Created by Joel Gutierrez on 10/17/17.
//  Copyright © 2017 Joel Gutierrez. All rights reserved.
//

#ifndef dealer_hpp
#define dealer_hpp

#include <stdio.h>
#include "person.hpp"
#include "deck.hpp"

class Dealer : public Person {
  public:
    Dealer(Deck *);
    bool is_requesting_card();
    void set_min_hit_count(int);
    void print_win();
    void print_lose();
    void print_tie();
    void display_user_options();
    
   private:
    int min_hit_count;
    
    
};

#endif /* dealer_hpp */
