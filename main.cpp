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

    //defines the file and filepath where commits are made
    std::string fileName = "log.txt";
    std::string filePathCommand = "cd .. && cd The-test-subject/ ";
    
    //one day is 24 hours
    const auto one_day = std::chrono::hours(24);

    //loop through the last year
    for (int i=0; i<365; i++){

        //subtract i days from current date and turn that into a string
        auto current_date = now - one_day * i;
        std::time_t time_t_date = std::chrono::system_clock::to_time_t(current_date);
        std::tm* tm_date = std::localtime(&time_t_date);
        std::ostringstream date_stream;
        date_stream << std::put_time(tm_date, "%Y-%m-%d");
        std::string date_string = date_stream.str();

        //defines a command that appends the current date to the log file and runs it
        std::string command = filePathCommand + "&& echo \"\n "+ date_string + "\" >> " + fileName;
        system(command.c_str());

        int rnd = getRandom();
        //for debugging purposes
        std::cout << "Random number: " << rnd << '\n';

        for (int i=0; i<rnd; i++){
            
            std::string sub_command = filePathCommand + "&& echo \" Commit #" + std::to_string(i + 1) + "\" >> " + fileName + 
            "&& git add . && git commit --date=\"" + date_string + "\" -m \"abc\" && git push";
            system(sub_command.c_str());
            std::cout << i << '\n';
            std::this_thread::sleep_for(std::chrono::seconds(2));

        }   
    }

    return 0;
}