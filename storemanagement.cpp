#include <iostream>
#include <vector>
#include <string>

class Product {
public:
    Product(int id, const std::string& name, double price) : id(id), name(name), price(price) {}
    
    int getID() const { return id; }
    const std::string& getName() const { return name; }
    double getPrice() const { return price; }

private:
    int id;
    std::string name;
    double price;
};

class ShoppingCart {
public:
    void addProduct(const Product& product) {
        items.push_back(product);
    }
    
    void displayCart() const {
        double total = 0;
        std::cout << "Shopping Cart Contents:\n";
        for (const Product& item : items) {
            std::cout << "ID: " << item.getID() << " | Name: " << item.getName() << " | Price: $" << item.getPrice() << std::endl;
            total += item.getPrice();
        }
        std::cout << "Total: $" << total << std::endl;
    }

private:
    std::vector<Product> items;
};

int main() {
    Product product1(1, "Laptop", 999.99);
    Product product2(2, "Smartphone", 599.99);
    
    ShoppingCart cart;
    cart.addProduct(product1);
    cart.addProduct(product2);
    
    cart.displayCart();
    
    return 0;
}
