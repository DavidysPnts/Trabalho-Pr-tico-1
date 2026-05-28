#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>

// Representa um quarto do hotel
class Room {
private:
    int number_;
    float price_per_night_;
    bool occupied_;

public:
    Room(int number, float price_per_night)
        : number_(number), price_per_night_(price_per_night), occupied_(false) {
        std::cout << "Room(" << number_ << ") criado\n";
    }

    ~Room() {
        std::cout << "~Room(" << number_ << ") destruido\n";
    }

    // Getters const
    int get_number() const { return number_; }
    float get_price_per_night() const { return price_per_night_; }
    bool is_occupied() const { return occupied_; }

    // Atualiza o estado de ocupação do quarto
    void set_occupied(bool status) { occupied_ = status; }

    // Exibe informações do quarto
    void display_info() const {
        std::cout << "Quarto " << number_
                  << " | R$ " << price_per_night_ << "/noite"
                  << " | " << (occupied_ ? "Ocupado" : "Disponivel") << "\n";
    }
};

#endif