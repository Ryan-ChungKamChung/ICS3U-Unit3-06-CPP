// Copyright (c) 2020 Ryan Chung Kam Chung All rights reserved
//
// Created by Ryan Chung Kam Chung
// Created in December 2020
// RNG number guessing game without crash


#include <iostream>
#include <random>
#include <string>


int main() {
    // this function generates a random number and checks if it is equal to
        // the user inputted number

    std::string magic_number_string;
    int random_number;
    int magic_number;

    std::cout << "Guess the magic number (0-9)!" << std::endl;

    // Input
    std::cout << "Please enter your guess: ";
    std::cin >> magic_number_string;

    // Process
    try {
        magic_number = std::stoi(magic_number_string);

        std::random_device rseed;
        std::mt19937 rgen(rseed());
        std::uniform_int_distribution<int> idist(0, 9);
        random_number = idist(rgen);

        if (magic_number == random_number) {
            // Output
            std::cout << "Nice! Your answer is right!" << std::endl;
        } else {
            // Output
            std::cout << "Oops! Your answer is wrong!" << std::endl;
            std::cout << "The correct answer was: "
            << random_number << std::endl;
        }
    } catch (std::invalid_argument) {
        // Output
        std::cout << "This isn't an integer" << std::endl;
    }
}
