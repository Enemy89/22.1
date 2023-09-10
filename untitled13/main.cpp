#include <iostream>
#include <map>
#include <string>

enum command {
    add, surname, tel
};

int main() {
    std::map<std::string, std::string> telDir;
    telDir["44-44-44"] = "Petrov";
    telDir["11-11-11"] = "Sidorov";
    telDir["88-99-33"] = "Koroleva";
    telDir["69-70-30"] = "Ivanov";
    telDir["66-66-66"] = "Ivanov";
    telDir["44-52-43"] = "Ivanov";

   std::cout<<"Enter command: \n"
              "0 - add the subscriber's phone number and surname to the directory\n"
              "1 - find out the subscriber's last name by phone number\n"
              "2 - find out the subscriber's phone number by last name"<<std::endl;
   int command;
   std::cin>>command;

    std::string num, user;
    if (command==command::add) {
        std::cin >> num >> user;
        std::pair<std::string, std::string> telPair(num, user);
        telDir.insert(telPair);
        /*for (std::map<std::string, std::string>::iterator it = telDir.begin(); it != telDir.end(); ++it) {
            std::cout << it->first << " " << it->second << std::endl;
        }*/
    } else {
        if (command==command::surname) {
            std::cin>>num;
            std::map<std::string, std::string>::iterator it = telDir.find(num);
            std::cout << it->second;
        } else {
            if (command==command::tel) {
                 std::cin>>user;
                for (std::map<std::string, std::string>::iterator it = telDir.begin(); it != telDir.end(); ++it) {
                    if (it->second==user) {
                        std::cout << it->first<<" ";
                    }
                }
            } else
                std::cout << "Err!";
        }
    }
}
