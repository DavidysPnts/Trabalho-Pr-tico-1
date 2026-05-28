#ifndef CONSUMPTION_PRODUCT_HPP
#define CONSUMPTION_PRODUCT_HPP

#include <string>
#include <iostream>

// Representa um produto ou serviço consumido pelo hóspede
class ConsumptionProduct {
private:
    std::string description_;
    float price_;

public:
    // Construtor com lista de inicialização
    ConsumptionProduct(std::string description, float price)
        : description_(description), price_(price) {
        std::cout << "ConsumptionProduct(\"" << description_ << "\") criado\n";
    }

    // Destrutor explícito e observável
    ~ConsumptionProduct() {
        std::cout << "~ConsumptionProduct(\"" << description_ << "\") destruido\n";
    }

    // Getters const
    std::string get_description() const { return description_; }
    float get_price() const { return price_; }

    // Exibe informações do produto
    void display_info() const {
        std::cout << "  Produto: " << description_ << " - R$ " << price_ << "\n";
    }
};

#endif