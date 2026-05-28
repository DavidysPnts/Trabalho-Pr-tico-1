#ifndef HOTEL_HPP
#define HOTEL_HPP

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "room.hpp"
#include "guest.hpp"

// Representa o hotel, que agrega quartos e hóspedes
class Hotel {
private:
    std::string name_;
    std::vector<std::shared_ptr<Room>> rooms_;
    std::vector<std::shared_ptr<Guest>> guests_;

public:
    Hotel(std::string name)
        : name_(name) {
        std::cout << "Hotel(\"" << name_ << "\") criado\n";
    }

    ~Hotel() {
        std::cout << "~Hotel(\"" << name_ << "\") destruido\n";
    }

    // Getters const
    std::string get_name() const { return name_; }

    // Adiciona um quarto ao hotel (agregação)
    void add_room(std::shared_ptr<Room> room) {
        rooms_.push_back(room);
    }

    // Adiciona um hóspede ao hotel (agregação)
    void add_guest(std::shared_ptr<Guest> guest) {
        guests_.push_back(guest);
    }

    // Exibe o status geral do hotel
    void display_status() const {
        std::cout << "Hotel " << name_ << " \n";
        std::cout << "Quartos:\n";
        for (const auto& r : rooms_) {
            r->display_info();
        }
        std::cout << "Hospedes cadastrados:\n";
        for (const auto& g : guests_) {
            g->display_info();
        }
    }
};

#endif