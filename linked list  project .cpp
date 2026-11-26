#include <iostream>
using namespace std;

struct Policy {
    int policy_id;
    string customer_name;
    string insurance_type;
    double insurance_amount;
    string status;

    Policy* next;
};
Policy* head = NULL;

void addpolicy() {
    Policy* new_node = new Policy;

    cout << "Inter Your Policy Id :";
    cin >> new_node->policy_id;

    cout << "Inter Your Customer Name :";
    cin >> new_node->customer_name;

    cout << "Inter Your Insurance Type :";
    cin >> new_node->insurance_type;

    cout << "Inter Your Insurance  Amount :";
    cin >> new_node->insurance_amount;

    cout << "Inter Your Statue :";
    cin >> new_node->status;

    if (head == NULL) {
        head = new_node;
        new_node->next = NULL;
    }
    else {
        Policy* last;
        last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = NULL;
    }

    cout << "~~~~~Done✅\nPolices Informations is saved \n";
}

void display() {
    Policy* current_node;  int count = 1;

    if (head == NULL) {
        cout << "linked list is empty.\n";
    }
    else {
        current_node = head;
        while (current_node != NULL)
        {
            cout << "==============>Policy Number :" << count << endl;
            cout << "Policy ID: " << current_node->policy_id << endl;
            cout << "Customer Name: " << current_node->customer_name << endl;
            cout << "Insurance Type: " << current_node->insurance_type << endl;
            cout << "Insurance Amount: " << current_node->insurance_amount << endl;
            cout << "Status: " << current_node->status << endl;
            cout << "-----------------------" << endl;
            count++;
            current_node = current_node->next;
        }
       
    }
}

bool search_policy() {

    Policy* current = head; int id;

    cout << "Inter Policy Id :";
    cin >> id;

    while (current != NULL) {
        if (current->policy_id == id) {
            cout << "  " << endl;
            cout << ">>>>>>>>>>>>>>> Policy Search Successfully✅  .  Policy Found <<<<<<<<<<<<<<<<<<<<<<<<<<  \n";
           
            cout << "Customer Name :" << current->customer_name << endl;
            cout << "Insurance Type :" << current->insurance_type << endl;
            cout << "Insurance Amount :" << current->insurance_amount << endl;
            cout << "Status :" << current->status << endl;
            return true;
        }
           
        current = current->next;
    }

    cout << ">>>>>>>>>>>>>>>>>>>> Policy Search  Failed ❌  .  Policy Not Found <<<<<<<<<<<<<<<<<<<<<<<<<<<<< \n";
 
    return false;
}


Policy* search_by_id() {

    Policy* current = head; int id;
    cout << "Enter Policy Id :";
    cin >> id;
    cout << " \n";
    while (current != NULL) {
        if (current->policy_id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
Policy* search_by_name() {

    Policy* current = head; string name;
    cout << "Enter Custormer Name :";
    cin >>  name;
    cout << " \n";
    while (current != NULL) {
        if (current->customer_name == name) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void Update_Policy() {

    int cc_choise; Policy* current = NULL;

    cout << "1- Search by Policy ID\n";
    cout << "2- Search by Customer Name\n";
    cout << " Choose :";
    cin >> cc_choise;
    cout << " \n";
    switch (cc_choise) {

    case 1:
        
       current= search_by_id();
        break;

    case 2:
        current =search_by_name();
        break;

    default:
        cout << "Invalid Choice!\n";
        return;

    }

    if (current == NULL) {
        cout << "Policy NOt Found ❌\n";
        return;
    }

      int update_choise;
      cout << "" << endl;
    cout << "1- Update Customer Name\n";
    cout << "2- Update Policy Id \n";
    cout << "3- Update Insurance Type\n";
    cout << "4- Update Insurance Amount\n";
    cout << "5- Update Status\n";
    cout << "6- Update All Information\n";

    cout << "Choose: ";
    cin >> update_choise;

    switch (update_choise) {

    case 1:
        cout << "Enter New Customer Name: ";
        cin >> current->customer_name;
        cout << "Done✅\n";
        break;

    case 2:
        cout << "Enter New Policy Id: ";
        cin >> current->policy_id;
        cout << "Done✅\n";
        break;
    case 3 :
        cout << "Enter New Insurance Type :";
        cin >> current->insurance_type;
        cout << "Done✅\n";
        break;

    case 4:
        cout << "Enter New Insurance Amount: ";
        cin >> current->insurance_amount;
        cout << "Done✅\n";
        break;


    case 5:
        cout << "Enter New Status: ";
        cin >> current->status;
        cout << "Done✅\n";
        break;

    case 6:
        cout << "Enter New Customer Name: ";
        cin >> current->customer_name;

        cout << "Enter New Policy Id: ";
        cin >> current->policy_id;

        cout << "Enter New Insurance Type :";
        cin >> current->insurance_type;

        cout << "Enter New Insurance Amount: ";
        cin >> current->insurance_amount;

        cout << "Enter New Status: ";
        cin >> current->status;
        cout << "Done✅\n-------------------\n";

        break;
    }


}


void delet_policy() {

    int id;

    cout << "Enter Policy Id You Want to Delet :";
    cin >> id;

    Policy* current = head;
    Policy* previous = NULL;

    while (current != NULL && current->policy_id != id) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        cout << "Policy Not Found" << endl;
    }
    else if (previous == NULL) {
        head = current->next;
    }
    else {
        previous->next = current->next;
    }delete(current);
    cout << ">>>>>>>>>>>>>>>>>>Policy Delet Successfully ✅" << endl;
}

int main() {

    int choice;

    while (true) {
        cout << "1- Add New Policy \n";
        cout << "2- Display All Policies\n";
        cout << "3- Search Policy\n";
        cout << "4- Update Policy\n";
        cout << "5- Delete Policy\n";
        cout << "6- Exit\n";

        cout << "Choose: ";
        cin >> choice;

        switch (choice) {

        case 1:
            addpolicy();
            cout << "-------------------------------\n";
            break;

        case 2:
            display();
     
            break;
         
        case 3:
            search_policy();
            cout << "-------------------------------\n";
            break;
        case 4:

            Update_Policy();
            cout << "-------------------------------\n";
            break;

        case  5:

            delet_policy();
            cout << "-------------------------------\n";
            break;
        case 6:
            return 0;

        default:
            cout << "Invalid Choice!" << endl;
        }

    }

    return 0;
}