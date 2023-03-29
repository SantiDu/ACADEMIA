//============================================================================
// File Name   : main.cpp
// Author      : Jinrui Du
// Copyright   : Copyright 2023 Jinrui Du
// Description : This is an address book.
// Disclaimer  : This is assignment 3.
// Revision History:
// Date              Version     Change ID         Author             Comment
// 06-Mar-2023         1.0          001           Jinrui Du        Initial creation
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

class Name {
    private:
        string first_name;
        string last_name;
    public:
        static const string DEFAULT_LAST_NAME;
        static const string DEFAULT_FIRST_NAME;

        Name();
        Name(string first_name, string last_name);
        ~Name();

        string get_first_name() const;
        void set_first_name(string first_name);
        string get_last_name() const;
        void set_last_name(string last_name);

        bool operator==(const Name & right) const;
        bool operator<(const Name & right) const;
        friend ostream & operator<<(ostream & os, const Name & name);
};

class Contact {          
    private:
        Contact * next;
    protected:
        Name name;
        string phone;
        string email;
        int location;
    public:
        static const string DEFAULT_PHONE;
        static const string DEFAULT_EMAIL;
        static const int DEFAULT_LOCATION;

        Contact();
        Contact(string first_name,
                string last_name,
                string phone,
                string email,
                int location);
        virtual ~Contact();

        const Name & get_name() const;
        void set_name(const Name & name);
        string get_phone() const;
        void set_phone(string phone);
        string get_email() const;
        void set_email(string email);
        int get_location() const;
        void set_location(int location);
        Contact * get_next() const;
        void set_next(Contact * p_contact);

        virtual void ShowContact() const = 0;
};

class EmployeeContact : public Contact {
    private:
        string title;
        string department;
    public:
        static const string DEFAULT_TITLE;
        static const string DEFAULT_DEPARTMENT;

        EmployeeContact();
        EmployeeContact(string first_name,
                        string last_name,
                        string phone,
                        string email,
                        int location,
                        string title,
                        string department);
        virtual ~EmployeeContact();

        string get_title() const;
        void set_title(string title);
        string get_department() const;
        void set_department(string department);

        virtual void ShowContact() const;
};

class ContractorContact : public Contact {
    private:
        string company;
        int assignment_duration;
    public:
        static const string DEFAULT_COMPANY;
        static const int DEFAULT_ASSIGNMENT_DURATION;

        ContractorContact();
        ContractorContact(string first_name,
                          string last_name,
                          string phone,
                          string email,
                          int location,
                          int assignment_duration,
                          string company);
        virtual ~ContractorContact();

        string get_company() const;
        void set_company(string company);
        int get_assignment_duration() const;
        void set_assignment_duration(int assignment_duration);

        virtual void ShowContact() const;
};

class ContactList {
    private:
        Contact * head;
    public:
        ContactList();
        ~ContactList();

        void Init();
        void ShowAllContacts() const;
        void SearchByName(const Name & name) const;
        void SearchByDepartment(const string department) const;
        void RemoveContact(const Name & name);
    private:
        Contact * FindContact(const Name & name) const;
        void InsertSort(Contact * p_contact);
};

class AddressBook {
    private:
        string company_name;
        ContactList contact_list;
    public:
        static const string DEFAULT_COMPANY_NAME;

        AddressBook();
        AddressBook(string company_name);
        ~AddressBook();

        void Init();
        void Run();
    private:
        void Menu() const;
        int GetUserOption() const;
        void ShowAllContacts() const;
        void SearchByName() const;
        void SearchByDepartment() const;
        void RemoveByName();
        bool Quit() const;
};

int main() {
    AddressBook * p_address_book = new AddressBook("COMPANIA");
    p_address_book->Init();
    p_address_book->Run();
    delete p_address_book;

    return 0;
}

const string Name::DEFAULT_FIRST_NAME = "";
const string Name::DEFAULT_LAST_NAME = "";
Name::Name() : first_name(Name::DEFAULT_FIRST_NAME), last_name(Name::DEFAULT_LAST_NAME) {}
Name::Name(string first_name, string last_name) : first_name(first_name), last_name(last_name) {}
Name::~Name() {}
string Name::get_first_name() const {return first_name;}
void Name::set_first_name(string first_name) {this->first_name = first_name;}
string Name::get_last_name() const {return last_name;}
void Name::set_last_name(string last_name) {this->last_name = last_name;}
bool Name::operator==(const Name & right) const {
    return first_name == right.first_name && last_name == right.last_name;
}
bool Name::operator<(const Name & right) const {
    return last_name < right.last_name || (last_name == right.last_name && first_name < right.first_name); 
}

ostream & operator<<(ostream & os, const Name & name) {
    os << name.first_name << ' ' << name.last_name << endl;
    return os;
}


const string Contact::DEFAULT_PHONE = "X-XXX-XXX-XXXX";
const string Contact::DEFAULT_EMAIL = "XXXXX@YYYY.ZZZ";
const int Contact::DEFAULT_LOCATION = 0;
Contact::Contact() : name(),
                     phone(Contact::DEFAULT_PHONE),
                     email(Contact::DEFAULT_EMAIL),
                     location(Contact::DEFAULT_LOCATION),
                     next(nullptr) {}
Contact::Contact(string first_name,
                 string last_name,
                 string phone,
                 string email,
                 int location) : name(first_name, last_name),
                                 phone(phone),
                                 email(email),
                                 location(location),
                                 next(nullptr) {}
Contact::~Contact() {
    cout << name << " has gone home." << endl;
}
const Name & Contact::get_name() const {return name;}
void Contact::set_name(const Name & name) {this->name = name;}
string Contact::get_phone() const {return phone;}
void Contact::set_phone(string phone) {this->phone = phone;}
string Contact::get_email() const {return email;}
void Contact::set_email(string email) {this->email = email;}
int Contact::get_location() const {return location;}
void Contact::set_location(int location) {this->location = location;}
Contact * Contact::get_next() const {return next;}
void Contact::set_next(Contact * p_contact) {this->next = p_contact;}


const string EmployeeContact::DEFAULT_TITLE = "XXX";
const string EmployeeContact::DEFAULT_DEPARTMENT = "XXX";
EmployeeContact::EmployeeContact() : Contact(),
                                     title(EmployeeContact::DEFAULT_TITLE),
                                     department(EmployeeContact::DEFAULT_DEPARTMENT) {}
EmployeeContact::EmployeeContact(string first_name,
                                 string last_name,
                                 string phone,
                                 string email,
                                 int location,
                                 string title,
                                 string department) : Contact(first_name,
                                                              last_name,
                                                              phone,
                                                              email,
                                                              location),
                                                      title(title),
                                                      department(department) {}
EmployeeContact::~EmployeeContact() {}
string EmployeeContact::get_title() const {return title;}
void EmployeeContact::set_title(string title) {this->title = title;}
string EmployeeContact::get_department() const {return department;}
void EmployeeContact::set_department(string department) {this->department = department;}
void EmployeeContact::ShowContact() const {
    cout << name << '\t' << title << '\t' << department << "\tRoom" << location << '\t' << phone << '\t' << email << endl;
}


const string ContractorContact::DEFAULT_COMPANY = "XYZ";
const int ContractorContact::DEFAULT_ASSIGNMENT_DURATION = 0;
ContractorContact::ContractorContact() : Contact(),
                                         assignment_duration(ContractorContact::DEFAULT_ASSIGNMENT_DURATION),
                                         company(ContractorContact::DEFAULT_COMPANY) {}
ContractorContact::ContractorContact(string first_name,
                                     string last_name,
                                     string phone,
                                     string email,
                                     int location,
                                     int assignment_duration,
                                     string company) : Contact(first_name,
                                                               last_name,
                                                               phone,
                                                               email,
                                                               location),
                                                        assignment_duration(assignment_duration),
                                                        company(company) {}
ContractorContact::~ContractorContact() {}
string ContractorContact::get_company() const {return company;}
void ContractorContact::set_company(string company) {this->company = company;}
int ContractorContact::get_assignment_duration() const {return assignment_duration;}
void ContractorContact::set_assignment_duration(int assignment_duration) {this->assignment_duration = assignment_duration;}
void ContractorContact::ShowContact() const {
    cout << name << '\t' << assignment_duration << " months (contractor)\t" << company << "\tRoom" << location << '\t' << phone << '\t' << email << endl;
}


ContactList::ContactList() : head(nullptr) {}
ContactList::~ContactList() {
    Contact * p_walker = head;
    Contact * p_delete = p_walker;
    while (p_walker != nullptr) {
        p_delete = p_walker;
        p_walker = p_walker->get_next();
        delete p_delete;
    }
}
Contact * ContactList::FindContact(const Name & name) const {
    Contact * p_current = head;
    while (p_current != nullptr) {
        if (p_current->get_name() == name) {
            return p_current;
        }  
        if (name < p_current->get_name()) {
            return nullptr;
        }
        p_current = p_current->get_next();
    }
    return nullptr;
} 
void ContactList::RemoveContact(const Name & name) {
    // code can be improved the same way as InsertSort
    Contact * p_walker = head;
    Contact * p_walker2 = p_walker;
    if (head == nullptr) {
        return;
    }
    if (head->get_name() == name) {
        p_walker = head->get_next();
        delete head;
        head = p_walker;
        return;
    }
    while (p_walker2->get_next() != nullptr) {
        p_walker2 = p_walker2->get_next();
        if (p_walker2->get_name() == name) {
            p_walker->set_next(p_walker2->get_next());
            delete p_walker2;
            return;
        }
        p_walker = p_walker2;
    }
}
void ContactList::InsertSort(Contact * p_contact) {   
    // The idea is to locate the previous node pointer
    // (the node that comes immediately right before the newly inserted node).
    // The algorithm must take care of the following:
    // + the list is empty (always needed in any linked list processing algorithm)
    // + the new node will be the first node in the non-empty list
    // + the new node is inserted in the middle of the list
    // + the new node is inserted at the end of the list
    Contact * p_previous = nullptr;
    Contact * p_walker = head;

    while (p_walker != nullptr && p_walker->get_name() < p_contact->get_name()) {
        p_previous = p_walker;
        p_walker = p_walker->get_next();
    }
    if (p_previous == nullptr) { // new node is the first node whether or not the list is empty
        p_contact->set_next(head);
        head = p_contact;
    }
    else { // new_node is in the middle or the last node
        p_contact->set_next(p_previous->get_next());
        p_previous->set_next(p_contact);
    }
}
void ContactList::Init() {
    InsertSort(new EmployeeContact("David", "Summer", "1-408-790-1682", "davids@tpcommuniations", 23, "Software Engineer",  "Engineering"));
    InsertSort(new EmployeeContact("David", "Morgan", "1-408-790-2381", "jenniferh@tpcommuniations", 17, "HR Representative",  "Human Resources"));
    InsertSort(new ContractorContact("Cindy", "Morgan", "1-408-790-3953", "cindym@tpcommuniations", 43, 12, "TK Consultings"));
    InsertSort(new EmployeeContact("Patrick", "Jane", "1-000-222-1682", "patrick@tpcommuniations", 20, "Mentalist",  "Engineering"));
    InsertSort(new EmployeeContact("Carl", "Lightman", "1-444-000-1682", "carl@tpcommuniations", 21, "Psychologist",  "Engineering"));
    InsertSort(new ContractorContact("Derren", "Brown", "3-408-790-0000", "derren@tpcommuniations", 32, 12 , "TK Consultings"));
    InsertSort(new ContractorContact("Sherlock", "Holmes", "9-888-790-3953", "sherlock@tpcommuniations", 33, 12 ,  "TK Consultings"));
    InsertSort(new ContractorContact("Eliot", "Anderson", "1-999-790-3953", "eliot@tpcommuniations", 40, 12 , "TK Consultings"));
    InsertSort(new ContractorContact("Greg", "House", "5-008-790-8888", "greg@tpcommuniations", 44, 12, "TK Consultings"));
    InsertSort(new ContractorContact("Walter", "White", "1-008-790-9999", "walter@tpcommuniations", 45, 12, "TK Consultings"));
    InsertSort(new EmployeeContact("L", "Lawliet", "1-008-790-7777", "l@tpcommuniations", 13, "Detective",  "Engineering"));
    InsertSort(new ContractorContact("D", "Luffy", "4-008-790-6666", "d@tpcommuniations", 12, 12, "TK Consultings"));
    InsertSort(new ContractorContact("Marcus", "Aurelius", "1-308-790-5555", "marcus@tpcommuniations", 73, 12, "TK Consultings"));
    InsertSort(new EmployeeContact("Julius", "Caesar", "1-208-790-4444", "julius@tpcommuniations", 78, "Senator",  "R&D"));
    InsertSort(new EmployeeContact("Evariste", "Galois", "1-408-790-3333", "evariste@tpcommuniations", 78, "Mathematician",  "R&D"));
    InsertSort(new EmployeeContact("Andrew", "Huberman", "8-408-790-2222", "andrew@tpcommuniations", 1, "Neurologist",  "R&D"));
    InsertSort(new ContractorContact("Lex", "Fridman", "8-408-790-1111", "lex@tpcommuniations", 2, 12, "TK Consultings"));
}
void ContactList::ShowAllContacts() const {
    Contact * p_contact = head;
    while (p_contact != nullptr) {
        p_contact->ShowContact();
        p_contact = p_contact->get_next();
    } 
}
void ContactList::SearchByName(const Name & name) const {
    Contact * p_contact = FindContact(name);
    if (p_contact != nullptr) {
        p_contact->ShowContact();
    }
    else {
        cout << "ERROR: No contact with name " << name << " is found!!!" << endl;
    }
}
void ContactList::SearchByDepartment(string department) const {
    EmployeeContact * p_employee_contact = nullptr;
    Contact * p_contact = head;
    while (p_contact != nullptr) {
        p_employee_contact = dynamic_cast<EmployeeContact *>(p_contact);
        if (p_employee_contact != nullptr) {
            if (department == p_employee_contact->get_department()) {
                p_employee_contact->ShowContact();
            }
        }
        p_contact = p_contact->get_next();
    } 
}


const string AddressBook::DEFAULT_COMPANY_NAME = "XYZ";
AddressBook::AddressBook() : company_name(AddressBook::DEFAULT_COMPANY_NAME) {}
AddressBook::AddressBook(string company_name) : company_name(company_name) {}
AddressBook::~AddressBook() {}
void AddressBook::Init() {
    contact_list.Init();
}
void AddressBook::Run() {
    int choice = 0;
    int quit = false;
    do {
        Menu();
        choice = GetUserOption();
        switch (choice) {
            case 1:
                ShowAllContacts();
                break;
            case 2:
                SearchByName();
                break;
            case 3:
                SearchByDepartment();
                break;
            case 4:
                RemoveByName();
                break;
            case 5:
                quit = Quit();
                break;
            default:
                break;
        }
    }
    while (!quit);
}
void AddressBook::Menu() const {
    cout << "\t\t\tTP Communications Address Book Menu" << endl;
    cout << "\t\t\t\t\t1. View all contacts" << endl;   
    cout << "\t\t\t\t\t2. Search by name" << endl;     
    cout << "\t\t\t\t\t3. Search by department" << endl;
    cout << "\t\t\t\t\t4. Remove by name" << endl;
    cout << "\t\t\t\t\t5. Quit" << endl;
}
int AddressBook::GetUserOption() const {
    int option = 0;
    cout << "Select an option (1-4): ";
    cin >> option;
    return option;    
}
void AddressBook::ShowAllContacts() const {
    contact_list.ShowAllContacts();
}
void AddressBook::SearchByName() const {
    string first_name;
    string last_name;
    cout << "Please input first name: " << endl;
    cin >> first_name;
    cout << "Please input last name: " << endl;
    cin >> last_name;

    Name name = Name(first_name, last_name);
    contact_list.SearchByName(name);
}
void AddressBook::SearchByDepartment() const {
    string department;
    cout << "Please enter department name: " << endl;
    cin.ignore();
    getline(cin, department);

    contact_list.SearchByDepartment(department);
}
void AddressBook::RemoveByName() {
    string first_name;
    string last_name;
    cout << "Please input first name: " << endl;
    cin >> first_name;
    cout << "Please input last name: " << endl;
    cin >> last_name;

    Name name = Name(first_name, last_name);
    contact_list.RemoveContact(name);
}
bool AddressBook::Quit() const {
    cout << endl << "Goodbye~~~~" << endl << endl << endl;
    return true;
}
