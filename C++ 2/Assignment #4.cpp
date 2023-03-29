//============================================================================
// File Name   : main.cpp
// Author      : Jinrui Du
// Copyright   : Copyright 2023 Jinrui Du
// Description : This program tracks customer accounts and their messages usages. 
// Disclaimer  : This is assignment 4.
// Revision History:
// Date              Version     Change ID         Author             Comment
// 21-Mar-2023         1.0          001           Jinrui Du        Initial creation
//============================================================================

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <cstdlib>

using namespace std;

class AccountNotFoundException : public exception {
    private:
        string msg;
        string phone_number;
    public:
        AccountNotFoundException();
        AccountNotFoundException(const AccountNotFoundException & e);
        string get_phone_number() const;
        void set_phone_number(string phone_number);
        virtual const char * what() const noexcept;
};

class Media {
    private:
        double size_in_mb;
    public:
        static const double DEFAULT_SIZE_IN_MB;
        static const double DEFAULT_CHARGE_PER_MB;
        static const double DEFAULT_MINIMUM_CHARGE;
        static const double SIZE_THRESHOLD;
        Media();
        Media(double size_in_mb);
        ~Media();
        double get_size_in_mb() const;
        void set_size_in_mb(double size_in_mb);
        double GetCharge() const;
};

template<typename T>
class Message {
    private:
        string to;
        T m_data;
    public:
        static const string DEFAULT_TO;
        Message();
        Message(string to, T m_data);
        ~Message();
        T get_data() const;
        void set_data(T m_data);
        string get_to() const;
        void set_to(string to);
};

class SmartCarrier {
    private:
        string name;
        bool init;
        map<string, vector<Message<Media> *>> account_map;
    public:
        static const string DEFAULT_NAME;
        static const bool DEFAULT_INIT;
        SmartCarrier();
        SmartCarrier(string name, bool init);
        ~SmartCarrier();
        void Init();
        void StartService();
    private:
        void Menu() const;
        int GetChoice() const;
        void ListAccounts() const;
        void InsertMessage();
        void PurgeLargeMessages();
        void DisconnectAccount();
};

int main() {
    SmartCarrier * p_carrier = new SmartCarrier();
    p_carrier->Init();
    p_carrier->StartService();
    delete p_carrier;

    return 0;
}

AccountNotFoundException::AccountNotFoundException() : exception() {}
AccountNotFoundException::AccountNotFoundException(const AccountNotFoundException & e) : phone_number(e.get_phone_number()),
                                                                                         msg("Account " + e.get_phone_number() + " not found!") {}
string AccountNotFoundException::get_phone_number() const {return phone_number;}
void AccountNotFoundException::set_phone_number(string phone_number) {this->phone_number = phone_number;}
const char * AccountNotFoundException::what() const noexcept {
    return msg.c_str();
}

const double Media::DEFAULT_SIZE_IN_MB = 0.0;
const double Media::DEFAULT_CHARGE_PER_MB = 0.05;
const double Media::DEFAULT_MINIMUM_CHARGE = 1.00;
const double Media::SIZE_THRESHOLD = 100;
Media::Media() : size_in_mb(Media::DEFAULT_SIZE_IN_MB) {}
Media::Media(double size_in_mb) : size_in_mb(size_in_mb) {}
Media::~Media() {}
double Media::get_size_in_mb() const {return size_in_mb;}
void Media::set_size_in_mb(double size_in_mb) {this->size_in_mb = size_in_mb;}
double Media::GetCharge() const {
    double charge = Media::DEFAULT_CHARGE_PER_MB * size_in_mb;
    if (charge > Media::DEFAULT_MINIMUM_CHARGE) {
        return charge;
    }
    else {
        return Media::DEFAULT_MINIMUM_CHARGE;
    }
}

template<typename T>
const string Message<T>::DEFAULT_TO = "000-000-0000";
template<typename T>
Message<T>::Message() : to(Message<T>::DEFAULT_TO) {}
template<typename T>
Message<T>::Message(string to, T m_data) : to(to), m_data(m_data) {}
template<typename T>
Message<T>::~Message() {}
template<typename T>
T Message<T>::get_data() const {return m_data;}
template<typename T>
void Message<T>::set_data(T m_data) {this->m_data = m_data;}
template<typename T>
string Message<T>::get_to() const {return to;}
template<typename T>
void Message<T>::set_to(string to) {this->to = to;}

const string SmartCarrier::DEFAULT_NAME = "XYZ Wireless";
const bool SmartCarrier::DEFAULT_INIT = false;
SmartCarrier::SmartCarrier() : name(SmartCarrier::DEFAULT_NAME), init(SmartCarrier::DEFAULT_INIT) {}
SmartCarrier::SmartCarrier(string name, bool init) : name(SmartCarrier::DEFAULT_NAME), init(SmartCarrier::DEFAULT_INIT) {}
SmartCarrier::~SmartCarrier() {
    map<string, vector<Message<Media> *>>::iterator iter_map;
    vector<Message<Media> *>::iterator iter_list;
    for (iter_map = account_map.begin(); iter_map != account_map.end(); ++iter_map) {
        for (iter_list = iter_map->second.begin(); iter_list != iter_map->second.end(); ++iter_list) {
            delete *iter_list;
        }
        iter_map->second.clear();
    }
    account_map.clear();
}
void SmartCarrier::Init() {
    // 1
    account_map["669-444-4444"];
    // 2
    account_map["310-211-5540"];
    // 3
    account_map["831-777-7777"].push_back(new Message<Media>("408-222-2222", Media(120.0)));
    // 4
    account_map["456-888-2334"].push_back(new Message<Media>("101-558-2222", Media(10.05)));
    // 5
    account_map["408-111-1111"].push_back(new Message<Media>("415-678-9011", Media(23.08))); 
    account_map["408-111-1111"].push_back(new Message<Media>("408-555-8888", Media(875.35))); 
    account_map["408-111-1111"].push_back(new Message<Media>("669-000-1234", Media(357.59))); 
    // 6
    account_map["121-555-3322"].push_back(new Message<Media>("321-581-4040", Media(70.2))); 
    account_map["121-555-3322"].push_back(new Message<Media>("102-381-4040", Media(30.2))); 
    // 7
    account_map["758-433-5219"].push_back(new Message<Media>("420-633-8729", Media(17.51)));
    account_map["758-433-5219"].push_back(new Message<Media>("110-333-8729", Media(30.0)));
    account_map["758-433-5219"].push_back(new Message<Media>("370-229-1010", Media(127.49)));
    // 8
    account_map["338-229-1110"].push_back(new Message<Media>("492-513-2727", Media(50.33)));
    account_map["338-229-1110"].push_back(new Message<Media>("532-013-2828", Media(150.33)));
    account_map["338-229-1110"].push_back(new Message<Media>("732-118-5720", Media(50.33)));
    // 9
    account_map["537-440-7753"].push_back(new Message<Media>("482-991-5959", Media(230.33)));
    account_map["537-440-7753"].push_back(new Message<Media>("837-999-9999", Media(20.33)));
    account_map["537-440-7753"].push_back(new Message<Media>("756-777-7777", Media(20.33)));
    // 10
    account_map["218-440-5527"].push_back(new Message<Media>("898-8385-1324", Media(200.01)));
    account_map["218-440-5527"].push_back(new Message<Media>("192-2837-1234", Media(30.01)));
    account_map["218-440-5527"].push_back(new Message<Media>("891-8234-9989", Media(200.01)));
    account_map["218-440-5527"].push_back(new Message<Media>("398-1234-1928", Media(30.01)));
    account_map["218-440-5527"].push_back(new Message<Media>("189-2987-2384", Media(200.01)));

    init = true;
}
void SmartCarrier::StartService() {
    int choice = 0;
    bool quit = false;
    if (init) {
        do {
            try {
                Menu();
                choice = GetChoice();
                switch (choice) {
                    case 1:
                        ListAccounts();
                        break;
                    case 2:
                        InsertMessage();
                        break;
                    case 3:
                        PurgeLargeMessages();
                        break;
                    case 4:
                        DisconnectAccount();
                        break;
                    case 5:
                        quit = true;
                        break;
                    default:
                        break;
                }
            }
            catch (AccountNotFoundException & e) {
                cout << e.what() << endl;
            }
            catch (...) {
                cout << "This is from the catch all handler." << endl;
            }
        }
        while (!quit);
    }
    else {
        cout << "System not initialized. Exiting..." << endl;
        exit(1);
    }
}
void SmartCarrier::Menu() const {
    cout << setw(30) << "FOOTHILL WIRELESS" << endl;
    cout << setw(28) << "ACCOUNT ADMIN" << endl;
    cout << "1. List all accounts and their messages' usages" << endl;
    cout << "2. Add a message to an account" << endl;
    cout << "3. Purge large messages from an account" << endl;
    cout << "4. Disconnect an account" << endl;
    cout << "5. Quit" << endl;
}
int SmartCarrier::GetChoice() const {
    int choice = 0;
    cout << "Please enter your choice: ";
    cin >> choice;
    return choice;
}
void SmartCarrier::ListAccounts() const {
    map<string, vector<Message<Media> *>>::const_iterator kIterMap;
    vector<Message<Media> *>::const_iterator kIterList;
    double total_msg_size = 0.0;
    double charge = 0.0;
    cout << fixed << setprecision(2);
    cout << setw(15) << "Account";
    cout << setw(15) << "Total message";
    cout << setw(30) << "Total message's size (MB)";
    cout << setw(20) << "Charge (dollar)";
    cout << endl;
    for (kIterMap = account_map.begin(); kIterMap != account_map.end(); ++kIterMap) {
        total_msg_size = 0.0;
        charge = 0.0;
        for (kIterList = kIterMap->second.begin(); kIterList != kIterMap->second.end(); ++kIterList) {
            total_msg_size += (*kIterList)->get_data().get_size_in_mb();
            charge += (*kIterList)->get_data().GetCharge();  
        }
        cout << setw(15) << kIterMap->first;
        cout << setw(15) << kIterMap->second.size();
        cout << setw(30) << total_msg_size;
        cout << setw(20) << charge;
        cout << endl;
    }
}
void SmartCarrier::InsertMessage() {
    string phone_number;
    double size;
    string to;
    map<string, vector<Message<Media> *>>::iterator iter_map;

    cout << "Please enter a phone number: ";
    cin >> phone_number;
    iter_map = account_map.find(phone_number);
    if (iter_map != account_map.end()) {
        cout << "Please enter media size: ";
        cin >> size;
        cout << "Please enter another phone number: ";
        cin >> to;
        iter_map->second.push_back(new Message<Media>(to, Media(size)));
    }
    else {
        AccountNotFoundException e;
        e.set_phone_number(phone_number);
        throw e;
    }
}
void SmartCarrier::PurgeLargeMessages() {
    string phone_number;
    double size = 0.0;
    double total_size_purged = 0.0;
    map<string, vector<Message<Media> *>>::iterator iter_map;
    vector<Message<Media> *>::iterator iter_list;

    cout << "Please enter a phone number: ";
    cin >> phone_number;
    iter_map = account_map.find(phone_number);
    if (iter_map != account_map.end()) {
        iter_list = iter_map->second.begin();
        while (iter_list != iter_map->second.end()) {
            size = (*iter_list)->get_data().get_size_in_mb();
            if (size > Media::SIZE_THRESHOLD) {
                total_size_purged += size;
                delete *iter_list;
                iter_list = iter_map->second.erase(iter_list);
            }
            else {
                ++iter_list;
            }
        }
        cout << "Total size purged is " << total_size_purged << " MB." << endl;
    }  
    else {
        AccountNotFoundException e;
        e.set_phone_number(phone_number);
        throw e;
    }
}
void SmartCarrier::DisconnectAccount() {
    string phone_number;
    map<string, vector<Message<Media> *>>::iterator iter_map;
    vector<Message<Media> *>::iterator iter_list;

    cout << "Please enter a phone number: ";
    cin >> phone_number;
    iter_map = account_map.find(phone_number);
    if (iter_map != account_map.end()) {
        for (iter_list = iter_map->second.begin(); iter_list != iter_map->second.end(); ++iter_list) {
            delete *iter_list;
        }
        iter_map->second.clear();
        account_map.erase(iter_map);
    }
    else {
        AccountNotFoundException e;
        e.set_phone_number(phone_number);
        throw e;
    }
}
