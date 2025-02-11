#include <iostream>
#include <iomanip>
#include <cmath>

// Function to calculate the total number of pie slices needed based on the number of guests and average slices each guest will eat.
double numberOfSlices(int guest, double avgPieSlice) {
    return (guest * avgPieSlice);
}

// Function to calculate the number of whole pies needed, assuming 1 pie = 8 slices. 
// It rounds up to ensure you have enough pies even if the total number of slices is not divisible by 8.
int wholePies(double totalSlicesOfPie) {
    return (std::ceil(totalSlicesOfPie / 8));
}

// Function to calculate the total cost spent on pies based on the number of whole pies and the cost per pie.
double amountSpentOnPies(int wholePies, double costOfPie) {
    return (wholePies * costOfPie);
}

// Function to calculate the total sales tax based on the total amount spent on pies.
double salesTaxTotal(double amountSpentOnPies, double salesTax) {
    return(amountSpentOnPies * salesTax);
}

// Function to calculate the total delivery charges based on the total amount spent on pies.
double deliveryChargesTotal(double amountSpentOnPiesWithTax, double deliveryCharges) {
    return(amountSpentOnPiesWithTax * deliveryCharges);
}

// Function to calculate the total cost including the amount spent on pies, sales tax, and delivery charges.
double totalCost(double amountSpentOnPies, double salesTaxTotal, const double deliveryChargesTotal=1.2) {
    return((amountSpentOnPies + salesTaxTotal)*deliveryChargesTotal);
}

int main() {
    // Declare variables for the number of guests, whole pies, and other costs.
    int guests;
    double avgPieSlicePerPerson, costOfPumpkinPie;
    double salesTax = 0.07; // Sales tax percentage (7%)
    double deliveryFee = 0.20; // Delivery fee percentage (20%)
    double costWithSalesTax = 0.0;
    double amountSpentOnAllPies = 0.0;
    double totalNumberOfSlice = 0.0;
    double delieveryChargesTotal = 0.0;
    int numberOfWholePies = 0;

    // Take user input for the number of guests, average slices per person, and the cost of one pie.
    std::cin >> guests >> avgPieSlicePerPerson >> costOfPumpkinPie;

    // Calculate the total number of pie slices needed.
    totalNumberOfSlice += numberOfSlices(guests, avgPieSlicePerPerson);

    // Calculate the number of whole pies required.
    numberOfWholePies += wholePies(totalNumberOfSlice);

    // Calculate the amountSpentOnAllPies

    amountSpentOnAllPies += amountSpentOnPies(numberOfWholePies, costOfPumpkinPie); 

    // Calculate the sales tax on the total amount spent on pies.
    costWithSalesTax += salesTaxTotal(amountSpentOnAllPies, salesTax);

    // Calculate the delivery charges on the total amount + taxes
    

    // Output the results: the total number of slices and number of whole pies.
    std::cout << "Happy Halloween!" << std::fixed << std::setprecision(2) << std::endl
        << "Total slices needed: " << totalNumberOfSlice << std::endl
        << "Number of Pumpkin Pies: " << numberOfWholePies << std::endl
        << "Cost of whole pies";
}
