/*
* This is a program that takes in the weight of a person and calculates the basal metabolic rate of a user gives thier weight in pounds
*
* Account for the calories burned through physical activity
*
*/


#include <iostream>
#include <cmath>

//This function calculates the Basal Metabolic Rate (BMR) given the user's weight in pounds.

double basalMetabolicRate(int weight);


//This function calculates the calories burned during physical exercise.


double caloriesForPhysExercise(int minutes, int intensity, int weight);


//This function handles the input from the user and provides options for calculating BMR and calories burned.

void input();


//This function validates the user's weight input.
int validUserWeight(int weight);

//This function validates the duration of exercise in minutes.
int validMinutes(int minutes);


//This function validates the intensity of the exercise.
int validIntensity(int intensity);


int main() {
    input(); // Starts the user interaction for the program
}

int validUserWeight(int weight) {
    while (weight <= 0) { // Ensure weight is a positive number
        std::cout << "Please input a valid weight in pounds: ";
        std::cin >> weight;
    }
    return weight;
}

int validMinutes(int minutes) {
    while (minutes <= 0) { // Ensure minutes is positive
        std::cout << "Please input a valid number of minutes: ";
        std::cin >> minutes;
    }
    return minutes;
}

int validIntensity(int intensity) {
    while (!(intensity == 17 || intensity == 10 || intensity == 8 || intensity == 1)) {
        std::cout << "Please input a valid intensity (17, 10, 8, or 1): ";
        std::cin >> intensity;
    }
    return intensity;
}

double basalMetabolicRate(int weight) {
    return (70 * pow((weight / 2.2), 0.756)); // Calculate BMR using weight converted from pounds to kg
}

double caloriesForPhysExercise(int minutes, int intensity, int weight) {
    return ((0.0385 * intensity) * (weight * minutes)); // Calculate calories burned during exercise
}

void input() {
    bool loop = true;
    int userInput, userWeight, minutes, intensity;

    while (loop) {
        std::cout << "\nWelcome to the calorie per serving calculator! " << std::endl
            << " 1. Calculate Basal Metabolic Rate (BMR)" << std::endl
            << " 2. Calculate Calories Burned from Physical Exercise" << std::endl
            << " 3. Calculate Total Calories (BMR + Exercise)" << std::endl
            << " 4. Exit" << std::endl
            << "Please choose an option: ";
        std::cin >> userInput;

        switch (userInput) {
        case 1: {
            // Calculate Basal Metabolic Rate (BMR)
            std::cout << "Please enter your weight in pounds: ";
            std::cin >> userWeight;
            userWeight = validUserWeight(userWeight);
            double basalMR = basalMetabolicRate(userWeight);
            std::cout << "The calories used by your body for the basal metabolic rate is: " << basalMR << " calories/day." << std::endl;
            break;
        }

        case 2: {
            // Calculate Calories Burned from Exercise
            std::cout << "Please enter your weight in pounds: ";
            std::cin >> userWeight;
            userWeight = validUserWeight(userWeight);

            std::cout << "Please enter the duration of your exercise in minutes: ";
            std::cin >> minutes;
            minutes = validMinutes(minutes);

            std::cout << "Please enter the intensity of the exercise (17, 10, 8, or 1): ";
            std::cin >> intensity;
            intensity = validIntensity(intensity);

            double caloriesBurned = caloriesForPhysExercise(minutes, intensity, userWeight);
            std::cout << "The calories burned during the exercise is: " << caloriesBurned << " calories." << std::endl;
            break;
        }

        case 3: {
            // Calculate Total Calories (BMR + Exercise)
            std::cout << "Please enter your weight in pounds: ";
            std::cin >> userWeight;
            userWeight = validUserWeight(userWeight);

            double basalMR = basalMetabolicRate(userWeight);

            std::cout << "Please enter the duration of your exercise in minutes: ";
            std::cin >> minutes;
            minutes = validMinutes(minutes);

            std::cout << "Please enter the intensity of the exercise (17, 10, 8, or 1): ";
            std::cin >> intensity;
            intensity = validIntensity(intensity);

            double caloriesBurned = caloriesForPhysExercise(minutes, intensity, userWeight);
            double totalCalories = basalMR + caloriesBurned;

            // Ask for calories per serving and calculate servings
            double caloriesPerServing;
            std::cout << "Please enter the calories per serving of the food: ";
            std::cin >> caloriesPerServing;

            if (caloriesPerServing > 0) {
                // Servings = (Total Calories) / (Calories per serving * 0.9) to account for digestion
                double servings = totalCalories / (caloriesPerServing * 0.9);
                std::cout << "You should consume " << servings << " servings to meet your total calorie needs. As you require: "<<totalCalories <<" calories per day" << std::endl;
            }
            else {
                std::cout << "Invalid calories per serving input. It must be greater than 0." << std::endl;
            }

            break;
        }


        case 4:
            // Exit the program
            loop = false;
            std::cout << "Exiting the program." << std::endl;
            break;

        default:
            std::cout << "Invalid option. Please select a valid option." << std::endl;
        }

    }
}
