/** cpp-todo-list
* Small console based application in C++ to demonstrate a basic Todo application
* @erikyuzwa
* License: MIT
*/

#include <iostream>
#include <string>
#include <list>
#include <ctime>
using namespace std;

class TodoItem {
private:
    int id;
    string description;
    bool completed;

public:
    TodoItem() : id(0), description(""), completed(false) {}
    ~TodoItem() = default;

    bool create(std::string new_description) {
        // generates a random integer between 1 and 100
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }

    int getId() { return id; }
    string getDescription() { return description; }
    bool isCompleted() { return completed; }

    void setCompleted(bool val) { completed = val; }

};

int main()
{
    char input_option;
    int input_id;
    string input_description;
    string version = "v0.2.0";
    list<TodoItem> todoItems;
    list<TodoItem>::iterator it;

    srand(time(NULL));

    todoItems.clear();

    while (1) {
        system("cls");
        cout << "Todo List Maker - " << version << endl;
        cout << endl << endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) {

            string completed = it->isCompleted() ? "done" : "not done";

            cout << it->getId() << " ** " << it->getDescription() << " ----> "
                << completed <<endl;
        }

        if (todoItems.empty()) {
           cout << "Add your first todo!" << std::endl;
        }

        cout << endl <<endl;

        cout << "[a]dd a new Todo" << endl;
        cout << "[c]omplete a Todo" << endl;
        cout << "[q]uit" << endl;

        cout << "choice: ";

        std::cin >> input_option;

        if (input_option == 'q') {
            cout << "Have a great day now!" << endl;
            break;
        }
        else if (input_option == 'a') {
            cout << "Add a new description: ";
            cin.clear();
            cin.ignore();
            getline(cin, input_description);

            TodoItem newItem;
            newItem.create(input_description);
            todoItems.push_back(newItem);

        }
        else if (input_option == 'c') {
            cout << "Enter id to mark completed: ";
            cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++) {

                if (input_id == it->getId()) {
                    it->setCompleted(true);
                    break;
                }
            }

        }

    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file