#include <iostream>
#include "hotel.hpp"
#include "guest.hpp"
#include "room.hpp"
#include "reservation.hpp"
#include "consumption_product.hpp"

int main() {
    // Criando o hotel
    Hotel hotel("Palace Hotel");

    // Criando quartos
    Room room1(101, 150.0);
    Room room2(102, 200.0);

    // Criando hóspedes
    Guest guest1("Davidys Pontes", "123.456.789-00");
    Guest guest2("Carlos Silva", "987.654.321-00");

    // Adicionando quartos e hóspedes ao hotel (agregação)
    hotel.add_room(&room1);
    hotel.add_room(&room2);
    hotel.add_guest(&guest1);
    hotel.add_guest(&guest2);

    hotel.display_status();
    std::cout << "\n";

    // ---- Demonstração de composição ----
    // Reservation é dona dos ConsumptionProducts
    // Ao sair do bloco, a reserva é destruída junto com seus produtos
    std::cout << "---- Demonstracao de Composicao ----\n";
    {
        Reservation reservation(1, &guest1, &room1, 3);
        reservation.add_product(ConsumptionProduct("Cafe da manha", 25.0));
        reservation.add_product(ConsumptionProduct("Servico de quarto", 45.0));
        reservation.display_summary();
        std::cout << "\n[saindo do bloco - reservation sera destruida]\n";
    }
    std::cout << "[fora do bloco]\n\n";

    // --- Demonstração de agregação ---
    // Room e Guest existem independentemente da Reservation
    std::cout << "---- Demonstracao de Agregacao ----\n";
    std::cout << "Quarto e hospede ainda existem apos destruicao da reserva:\n";
    room1.display_info();
    guest1.display_info();

    std::cout << "\n";
    return 0;
}