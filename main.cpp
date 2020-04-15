#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h> 


using namespace std;

struct Deck {
    int num;
    int suit;
    std::vector<string> pulled_cards {};
    public:
        void build_card();
        int insert_card_in_deck(string);
};


void Deck::build_card() {
    int build_num = rand() % 13 + 2;
    int build_suit = rand() % 4 + 1;
    string build_num_s = to_string(build_num);
    string build_suit_s = to_string(build_suit);

    string new_card = build_num_s + build_suit_s;

    int check_deck_status = insert_card_in_deck(new_card);

    if(check_deck_status == 0) {
        num = build_num;
        suit = build_suit;
    } 
    // else {
    //     build_card();
    // }
}

bool check_deck(string card, const std::vector<string> pulled_array) {
    return std::find(pulled_array.begin(), pulled_array.end(), card) != pulled_array.end();
}

int Deck::insert_card_in_deck(string card) {
    if(check_deck(card, pulled_cards) == 0) {
        pulled_cards.insert(pulled_cards.begin(), card);
        return 0;
    } else {
        return 1;
    }
}

int main() {
    string spades;
    string clubs;
    string hearts;
    string diamonds;
    int build_num;
    int build_suit;
    string suit_out;
    string face_card;
    string exercise;
    
    std::cout << "Enter an exercise for Spades\n";
    std::cin >> spades;

    std::cout << "Enter an exercise for Clubs\n";
    std::cin >> clubs;

    std::cout << "Enter an exercise for Hearts\n";
    std::cin >> hearts;

    std::cout << "Enter an exercise for Diamonds\n";
    std::cin >> diamonds;
    
    srand(time(0));
    Deck new_card;
    
    while(new_card.pulled_cards.size() < 52) {
        new_card.build_card();

        switch(new_card.suit) {
            case 1:
                suit_out = "Spades";
                exercise = spades;
                break;
            case 2:
                suit_out = "Clubs";
                exercise = clubs;
                break;
            case 3:
                suit_out = "Hearts";
                exercise = hearts;
                break;
            case 4:
                suit_out = "Diamonds";
                exercise = diamonds;
                break;
            default:
                suit_out = "error!";
        }

        switch(new_card.num) {
            case 11:
                face_card = "Jack";
                break;
            case 12:
                face_card = "Queen";
                break;
            case 13:
                face_card = "King";
                break;
            case 14:
                face_card = "Ace";
                break;
            default:
                face_card = "error!";
        }

        if(new_card.num > 10) {
            std::cout << face_card << " of " << suit_out << "\n";
            std::cout << "Do " << new_card.num << " " << exercise << "s\n";
        } else {
            std::cout << new_card.num << " of " << suit_out << "\n";
            std::cout << "Do " << new_card.num << " " << exercise << "s\n";
        }

        // this loop checks to see that cards are being inserted into vector - to delete before finishing program
        for (int i = 0; i < new_card.pulled_cards.size(); i++) {
		    std::cout << new_card.pulled_cards.at(i) << ' ';
	    }
        
        string cont_exercise;

        std::cout << "Did you do it? Press Y to continue or Q to quit\n";
        std::cin >> cont_exercise;

        if(cont_exercise == "y") {
            continue;
        } else if(cont_exercise == "q") {
            std::cout << "Nice going!   ....quitter\n";
            break;
        }
    }
}