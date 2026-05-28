#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include <iostream>
#include <vector>
#include "guest.hpp"
#include "room.hpp"
#include "consumption_product.hpp"

// Representa uma reserva feita por um hóspede para um quarto
class Reservation {
private:
    int id_;
    Guest& guest_;
    Room& room_;
    int nights_;
    std::vector<ConsumptionProduct> products_;

public:
    Reservation(int id, Guest& guest, Room& room, int nights)
        : id_(id), guest_(guest), room_(room), nights_(nights) {
        room_.set_occupied(true);
        std::cout << "Reservation(" << id_ << ") criada\n";
    }

    ~Reservation() {
        room_.set_occupied(false);
        std::cout << "~Reservation(" << id_ << ") destruida\n";
    }

    // Getters const
    int get_id() const { return id_; }

    // Adiciona um produto de consumo à reserva
    void add_product(const ConsumptionProduct& product) {
        products_.emplace_back(product);
    }

    // Calcula o total da reserva: diárias + produtos
    float calculate_total() const {
        float total = room_.get_price_per_night() * nights_;
        for (const auto& p : products_) {
            total += p.get_price();
        }
        return total;
    }

    // Exibe o resumo da reserva
    void display_summary() const {
        std::cout << "Reserva #" << id_ << "\n";
        std::cout << "  Hospede: " << guest_.get_name() << "\n";
        std::cout << "  Quarto: " << room_.get_number()
                  << " | " << nights_ << " noite(s)\n";
        std::cout << "  Produtos consumidos:\n";
        for (const auto& p : products_) {
            p.display_info();
        }
        std::cout << "  Total: R$ " << calculate_total() << "\n";
    }
};

#endif