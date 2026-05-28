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

    // Exibindo status do hotel
    hotel.display_status();

    std::cout << "\n";

    // Criando uma reserva (composição com ConsumptionProduct)
    Reservation reservation(1, &guest1, &room1, 3);

    // Adicionando produtos à reserva
    reservation.add_product(ConsumptionProduct("Cafe da manha", 25.0));
    reservation.add_product(ConsumptionProduct("Servico de quarto", 45.0));

    // Exibindo resumo da reserva
    reservation.display_summary();

    std::cout << "\n";

    return 0;
}