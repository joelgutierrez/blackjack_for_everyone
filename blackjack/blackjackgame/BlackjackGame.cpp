//
//  BlackjackGame.cpp
//  blackjack
//
//  Created by Joel Gutierrez on 10/18/17.
//  Copyright © 2017 Joel Gutierrez. All rights reserved.
//

#include "BlackjackGame.hpp"

BlackjackGame::BlackjackGame(int num_of_players) {
    initialize_deck();
    initialize_all_participants(num_of_players);
}

BlackjackGame::~BlackjackGame() {
    for(int i = 0; i < participant_list.size(); i++) {
        delete participant_list[i];
    }
    delete deck;
}

void BlackjackGame::initialize_deck() {
        deck = new Deck();
}

void BlackjackGame::initialize_all_participants(int num_of_players) {
    initialize_players(num_of_players);
    initialize_dealer();
    dealer_index = num_of_players - 1;
}

void BlackjackGame::initialize_dealer() {
    Dealer *dealer = new Dealer(deck);
    participant_list.push_back(dealer);
}

void BlackjackGame::initialize_players(int num_of_players) {
    for(int i = 0; i < num_of_players - DEALER; i++) {
        Person *player = new Player(deck);
        participant_list.push_back(player);
    }
}

void BlackjackGame::distribute_cards_to_participants() {
    for (int i = 0; i < participant_list.size(); i++) {
        int card_one = deck->get_top_card_and_make_bookkeeping_updates();
        int card_two = deck->get_top_card_and_make_bookkeeping_updates();
        int cards_sum = card_one + card_two;
        participant_list[i]->set_hand_count(cards_sum);
    }
}

void BlackjackGame::have_each_person_do_decision() {
    do_player_decisions();
    do_dealer_decisions();
}

void BlackjackGame::do_player_decisions() {
    for (int i = 0; i < participant_list.size() - DEALER; i++) {
        std::cout << std::endl << std::endl;
        std::cout << "Player " << i+1 << " turn" << std::endl;
        participant_list[i]->make_decisions_for_turn();
    }
}

void BlackjackGame::do_dealer_decisions() {
    if(does_dealer_have_to_go()) {
        std::cout << std::endl << std::endl;
        std::cout << "Dealers turn" << std::endl;
        participant_list[dealer_index]->make_decisions_for_turn();
    }
    std::cout << std::endl;
}

bool BlackjackGame::does_dealer_have_to_go() {
    for (int i = 0; i < participant_list.size() - DEALER; i++) {
        if(participant_list[i]->get_game_status()) {
            return true;
        }
    }
    return false;
}

void BlackjackGame::initialize_difficulty_level() {
    int user_difficulty_selected;
    while(true) {
        print_difficulty_level_menu();
        if(std::cin >> user_difficulty_selected) {
            if( is_difficulty_level_within_range(user_difficulty_selected) ) {
                set_dealer_min_hit_count(user_difficulty_selected);
                break;
            }
        } else { //user input is wrong
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

bool BlackjackGame::is_difficulty_level_within_range(int user_difficulty_selected) {
    bool within_range = false;
    if(user_difficulty_selected == EASY || user_difficulty_selected == MEDIUM || user_difficulty_selected == HARD) {
        within_range = true;
    }
    return within_range;
}

void BlackjackGame::set_dealer_min_hit_count(int min_count) {
    Dealer* dealer_temp = static_cast<Dealer*>(participant_list[dealer_index]);
    if(min_count == EASY) {
        dealer_temp->set_min_hit_count(EASY_MIN_COUNT);
    } else if (min_count == MEDIUM) {
        dealer_temp->set_min_hit_count(MEDIUM_MIN_COUNT);
    } else {
        dealer_temp->set_min_hit_count(HARD_MIN_COUNT);
    }
}

void BlackjackGame::print_difficulty_level_menu() {
    std::cout << "Choose a difficulty level" << std::endl;
    std::cout << "1 (easy), 2 (medium), 3(hard)" << std::endl;
}

void BlackjackGame::print_game_results() {
    std::cout << "-----------------------------------" << std::endl;
    std::cout << std::endl;
    int dealer_hand_count = participant_list[dealer_index]->get_hand_count();
    std::cout << "Dealer score: " << dealer_hand_count << std::endl;
    if(is_dealer_over_limit()) {
        print_results_for_dealer_losing();
    } else {
        print_results_for_dealer_being_active(dealer_hand_count);
    }
    std::cout << "-----------------------------------" << std::endl;
}

bool BlackjackGame::is_dealer_over_limit() {
    return !participant_list[dealer_index]->get_game_status();
}

void BlackjackGame::print_results_for_dealer_losing() {
    participant_list[dealer_index]->print_lose();
    for(int i = 0; i < participant_list.size() - DEALER; i++) {
        std::cout << "Player " << i + 1 << " score: ";
        if( participant_list[i]->get_game_status() ) {
            participant_list[i]->print_win();
        } else {
            participant_list[i]->print_lose();
        }
    }
    std::cout << std::endl;
}

void BlackjackGame::print_results_for_dealer_being_active(int dealer_count) {
    for(int i = 0; i < participant_list.size() - DEALER; i++) {
        std::cout << "Player " << i + 1 << " score: ";
        if( participant_list[i]->get_game_status() ) {
            (dynamic_cast<Player*>(participant_list[i]))->print_win_lose_tie_vs_dealer_count(dealer_count);
        } else {
            participant_list[i]->print_lose();
        }
    }
    std::cout << std::endl;
}
