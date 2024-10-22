#include <iostream>
#include <vector>
#include <string>
//got a lot of this from cplusplus.com
using namespace std;
int choice;
int playerGold = 150;
int menuChoice;

// Structure to represent an item in the inventory
struct Item {
    string name;
    int quantity;
    int price;
};

struct playerItem {
    string name;
    int quantity;
    int price;
};

int askNumber(int high, int low) {
    int num = 0;
    do {
        cout << "please enter a number " << "(" << low << " _ " << high << "): ";
        std::cin >> num;
    } while (num > high || num < low);
    return num;
}

// Function to display the merchant's inventory
void displayInventory(const vector<Item>& inventory) {
    cout << "Merchant's Inventory:\n";
    for (size_t i = 0; i < inventory.size(); ++i) {
        cout << i + 1 << ". " << inventory[i].name << " (Quantity: " << inventory[i].quantity << ", Price: " << inventory[i].price << ")\n";
    }
}

void displayPlayerInventory(vector<playerItem> inventory) {

    vector<playerItem>::const_iterator iter;

    cout << "you have " << inventory.size() << " items\n";

    cout << "\nyour items: \n";

    for (iter = inventory.begin(); iter != inventory.end(); iter++) {
        cout << iter->name << std::endl;
    }
}

// Function to handle player interaction with the inventory thankt you cplusplus.com
void interactWithInventory(vector<Item>& inventory) {
    displayInventory(inventory);

    
    cout << "W#hat do you want to buy (or 0 to exit): ";
    cin >> choice;

    if (choice == 0) {
        return; // Exit the interaction
    }

    if (choice > 0 && choice <= inventory.size()) {
        int itemIndex = choice - 1; // Adjust index for vector
        
        if (choice > 0 && choice <= inventory.size()) {

            int itemIndex = choice - 1; // Adjust index for vector

            if (inventory[itemIndex].quantity != 0)
            {
                if (playerGold >= inventory[itemIndex].price) {
                    // Player has enough gold
                    cout << "\nYou bought " << inventory[itemIndex].name << "!\n";
                    playerGold -= inventory[itemIndex].price;
                    inventory[itemIndex].quantity--;
                    if (inventory[itemIndex].quantity == 0)
                    {
                        inventory[itemIndex].name = "Soldout";
                    }
                    cout << "\nYou have " << playerGold << " gold left.\n";
                }
                else {
                    // Player doesn't have enough gold
                    cout << "\nYou need more gold squirt.\n";
                }
            }
            else {
                cout << "ItemSold Out\n";
            }
        }
    }
    else {
        cout << "\nI don't know how that would help in the mines.\n";
    }
}

int main() {
    vector<Item> merchantInventory = {
        {"Sword", 1, 20},
        {"Shield", 3, 15},
        {"Potion", 10, 5},
        {"Leather Armor", 2, 30},
        {"Basic Gemlock Pistol", 1, 100}
    };
    vector<playerItem> inventory;
    inventory.push_back({ "Loose Wrench", 1, 0 });
    inventory.push_back({ "Worn-Out Smithing Hammer", 1, 0 });
    inventory.push_back({ "Rusty Pickaxe", 1, 0 });
    do{
        cout << "what do you want to do?\n";
        cout << "1. buy\n";
        cout << "2. check your inventory\n";
        cout << "3. leave\n";
        menuChoice = askNumber(3, 1);
        if (menuChoice == 1) {
            interactWithInventory(merchantInventory);
        }
        else if (menuChoice == 2) {
            displayPlayerInventory(inventory);
        }
        
    } while (menuChoice != 3);
    

    return 0;
} 