//
// Created by masha on 11/12/20.
//

#ifndef CPP_PRACTICE_DEBUGGING_H
#define CPP_PRACTICE_DEBUGGING_H
#include <iostream>

/*
 * Hotel Prices
 * In this challenge, the task is to debug the existing code to successfully execute all provided test files.
 * The given code defines two classes HotelRoom and HotelApartment denoting respectively a standard hotel room and a hotel apartment.
 * An instance of any of these classes has two parameters: bedrooms and bathrooms denoting respectively
 * the number of bedrooms and the number of bathrooms in the room.
 * The prices of a standard hotel room and hotel apartment are given as:
 * Hotel Room: 50 * bedrooms + 100 bathrooms.
 * Hotel Apartment: The price of a standard room with the same number bedrooms and bathrooms plus 100.
 * For example, if a standard room costs 200, then an apartment with the same number of bedrooms and bathrooms costs 300.
 * In hotel's codebase, there is a piece of code reading the list of rooms booked for today
 * and calculates the total profit for the hotel. However, sometimes calculated profits are lower than they should be.
 * Debug the existing HotelRoom and HotelApartment classes' implementations
 * so that the existing code computing the total profit returns a correct profit.
 *
 * Input Format
 * The input is read by the provided locked code template.
 * In the first line, there is a single integer n denoting the number of rooms booked for today.
 * After that n lines follow. Each of these lines begins with a room_type which is either standard or apartment,
 * and is followed by the number of bedrooms and the number of bathrooms in this room.
 *
 * Output Format
 * The output is produced by the provided and locked code template.
 * It calculates the total profit by iterating through the vector of all rooms read from the input.
 */
#include <vector>
class HotelRoom {
public:
    HotelRoom(int bedrooms, int bathrooms)
            : bedrooms_(bedrooms), bathrooms_(bathrooms) {}
    virtual ~HotelRoom() {}

   virtual int get_price() {
        return 50*bedrooms_ + 100*bathrooms_;
    }
private:
    int bedrooms_;
    int bathrooms_;
};

class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms) : HotelRoom(bedrooms, bathrooms){}

    int get_price() override
    {
        return HotelRoom::get_price() + 100;
    }
private:
    int bedrooms_;
    int bathrooms_;
};

void call_hotel_price()
{
    int n;
    std::cin >> n;
    std::vector<HotelRoom*> rooms;
    for (int i = 0; i < n; ++i) {
        std::string room_type;
        int bedrooms;
        int bathrooms;
        std::cin >> room_type >> bedrooms >> bathrooms;
        if (room_type == "standard") {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        } else {
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
        }
    }

    int total_profit = 0;
    for (auto room : rooms) {
        total_profit += room->get_price();
    }
    std::cout << total_profit << std::endl;

    for (auto room : rooms) {
        delete room;
    }
    rooms.clear();
}


/*
 * Overloading Ostream Operator
 * The task is to overload the << operator for Person class in such a way
 * that for p being an instance of class Person the result of:
 * std::cout << p << " " << <some_string_value> << std::endl;
 * produces the following output:
 * first_name=<first_name>,last_name=<last_name> <some_string_value>
 * Input Format
 *  The input is read by the provided locked code template. In the only line of the input there are 3 space-separated strings:
 *  first_name, last_name, event. The values of first_name and last_name will be used to create an object p of type Person.
 *  The value of event will be used by the provided code to produce the output.
 * Output Format
 *  The output should be produced by the provided locked code template.
 *  This code will use the implementation of Person public methods and the overloaded << operator to produce the output.
 *  Specifically, the output will be produced by the following code:
 *  cout << p << " " << event << endl;
 */
class Person {
public:
    Person(const std::string& first_name, const std::string& last_name) : first_name_(first_name), last_name_(last_name) {}
    const std::string& get_first_name() const {
        return first_name_;
    }
    const std::string& get_last_name() const {
        return last_name_;
    }
private:
    std::string first_name_;
    std::string last_name_;
};

std::ostream &operator<<(std::ostream &out, const Person &p) {
    out << "first_name=" << p.get_first_name() << ",last_name=" << p.get_last_name();
    return out;
}

void call_person() {
    std::string first_name, last_name, event;
    std::cin >> first_name >> last_name >> event;
    auto p = Person(first_name, last_name);
    std::cout << p << " " << event << std::endl;
}

/*
 * Messages Order
 * In this problem, the task is to implement a software layer over the top of a network protocol sending messages in arbitrary order,
 * in such a way that the sent messages are printed by the recipient in the order they were sent.
 * Your task is to implement classes Message and MessageFactory according to the below specification:
 * Class Message is required to store a text value of type std::string and provide a public getter const string& get_text()
 * which is expected to return this text value.
 * Besides that, it should implement the < operator that will be used in fix_order() method of the recipient to fix the order of received messages.
 * Feel free to implement any other methods and class/instance variables.
 * In particular, you can implement any additional constructors, but make sure that you provide an empty constructor, i.e. the one without arguments.
 * Class MessageFactory is required to have an empty constructor,
 * and implement a method Message create_message(const string& text) that is expected to return a Message object storing the value of text argument.
 * Feel free to implement any other methods and class/instance variables of this class.
 *
 * Input Format
 * The input is read by the provided locked code template. It contains several lines of text messages in the order that they will be sent over the network.
 *
 * Output Format
 * The output should be produced by the provided locked code template and it is produced as described in details in the statement.
 * The expected order of printed messages is the same as the one in the input.
 */
class Message {
private:
    std::string text_;
    int id_;
public:
    Message() {}
    Message(const std::string text, const int id) {
        text_ = text;
        id_ = id;
    };
    const std::string& get_text() {
        return text_;
    }
    bool operator<(const Message& rhs)
    {
        return this->id_ < rhs.id_;
    }
};

class MessageFactory {
private:
    static int id;
public:
    MessageFactory() {}
    Message create_message(const std::string& text) {
        return Message(text, id++);
    }
};


class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            std::cout << msg.get_text() << std::endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    std::vector<Message> messages_;
};

class Network {
public:
    static void send_messages(std::vector<Message> messages, Recipient& recipient) {
        // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};

int MessageFactory::id = 0;

void call_msg_order() {
    MessageFactory message_factory;
    Recipient recipient;
    std::vector<Message> messages;
    std::string text;
    std::cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
    // are ignored
    while (getline(std::cin, text)) {
        if(text == "")
            break;
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}

#endif //CPP_PRACTICE_DEBUGGING_H
