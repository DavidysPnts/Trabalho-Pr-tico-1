# Sistema de Hotel

**Nome:** Davidys Cavalcante de Pontes
**Matrícula:** 20250019035

## Descrição

Este projeto se resume a um sistema de gerenciamento de hotel. O hotel possui quartos que podem ser reservados por hóspedes, cada reserva pertence a um hóspede e a um quarto específico, e pode conter itens de consumo, como serviços adicionais. O sistema permite realizar reservas e calcular o valor total a pagar.

## Diagrama UML

```mermaid
classDiagram
    class Hotel {
        -string name_
        -vector~Room*~ rooms_
        -vector~Guest*~ guests_
        +Hotel(string)
        +~Hotel()
        +add_room(Room*) void
        +add_guest(Guest*) void
        +display_status() void
    }

    class Room {
        -int number_
        -float price_per_night_
        -bool occupied_
        +Room(int, float)
        +~Room()
        +get_number() int
        +get_price_per_night() float
        +is_occupied() bool
        +set_occupied(bool) void
    }

    class Guest {
        -string name_
        -string cpf_
        +Guest(string, string)
        +~Guest()
        +get_name() string
        +get_cpf() string
    }

    class Reservation {
        -int id_
        -Guest* guest_
        -Room* room_
        -int nights_
        -vector~ConsumptionProduct~ products_
        +Reservation(int, Guest*, Room*, int)
        +~Reservation()
        +add_product(ConsumptionProduct) void
        +calculate_total() float
        +display_summary() void
    }

    class ConsumptionProduct {
        -string description_
        -float price_
        +ConsumptionProduct(string, float)
        +~ConsumptionProduct()
        +get_description() string
        +get_price() float
    }

    Hotel "1" o-- "0..*" Guest : agrega
    Hotel "1" o-- "1..*" Room : agrega
    Reservation "1" *-- "0..*" ConsumptionProduct : contém
    Reservation --> Guest : referencia
    Reservation --> Room : referencia
```