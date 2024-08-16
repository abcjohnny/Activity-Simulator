#include <random>
#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <thread>

int getRandom(){
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distr(0,12);

    int random_number = distr(gen);

    return random_number;
}

int main(){

    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_c);

    //change the following 2 lines to suit your needs
    std::string fileName = "log.txt";
    std::string filePathCommand = "cd .. && cd The-test-subject/ ";

    std::ostringstream oss;
    oss << std::put_time(now_tm, "%d-%m-%Y");
    
    std::string formatted_date = oss.str();

    std::string command = filePathCommand + "&& echo \"\n "+ formatted_date + "\" >> " + fileName;
    system(command.c_str());

    int rnd = getRandom();

    std::cout << "Random number: " << rnd << '\n';
    for (int i=0; i<rnd; i++){

        std::string sub_command = filePathCommand + "&& echo \" Commit #" + std::to_string(i) + "\" >> " + fileName + 
        "&& git add . && git commit -m \"abc\" && git push";
        system(sub_command.c_str());
        std::cout << i << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(2));


    }

    return 0;
}