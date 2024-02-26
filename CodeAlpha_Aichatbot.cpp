#include <iostream>
#include <string>
#include <algorithm>
#include <map>

std::string preprocessInput(const std::string& input) {
    std::string processedInput = input;
    std::transform(processedInput.begin(), processedInput.end(), processedInput.begin(), ::tolower);
    return processedInput;
}

std::string getResponse(const std::string& input) {
    std::map<std::string, std::string> responses = {
        {"hi", "Hello! How can I assist you today?"},
        {"how are you", "I'm just a program, so I don't have feelings, but thanks for asking!"},
        {"what is your name", "I am a chatbot."},

    };

    for (const auto& entry : responses) {
        if (input.find(entry.first) != std::string::npos) {
            return entry.second;
        }
    }

    return "I'm sorry, I don't understand. Can you please rephrase?";
}


int main() {
    std::cout << "Welcome to the Advanced AI Chatbot!\n";
    std::string input;
    
    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, input);
        
        std::string processedInput = preprocessInput(input);
        
        std::string response = getResponse(processedInput);
        
        std::cout << "Chatbot: " << response << std::endl;
        
        
        if (processedInput == "goodbye") {
            std::cout << "Chatbot: Goodbye! Have a great day." << std::endl;
            break;
        }
    }
    return 0;
}
