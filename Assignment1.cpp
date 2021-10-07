
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Tommy Thai
// Assignment 1

int main()
{


    

    // define the stock of each coin or bill
    int nickel_stock = 25,
        dime_stock = 25,
        quarter_stock = 25,
        ones_stock = 0,
        fives_stock = 0;

  
    // introduction of program

    cout << "Welcome to the vending machine change maker\n" << "program\n" << "Change maker initialized.\n";

    // display stock

    cout << "Stock contains:\n";
    cout << setw(3) << ""
        << nickel_stock << " nickels\n"
        << setw(3) << ""
        << dime_stock << " dimes\n"
        << setw(3) << ""
        << quarter_stock << " quarters\n"
        << setw(3) << ""
        << ones_stock << " ones\n"
        << fives_stock << " fives\n";

    //ask user for input of price
    bool _continue = true;
    while (_continue) {
        double price; // defines a variable to hold the input
        cout << "Enter the purchase price (xx.xx)  : "; // prompt the user to enter a the price 
        cin >> price; // store input

    // Checking if input is a number or not

        bool notNumber = true;
        while (notNumber)
        {
        
        if (!cin) 
            {
                
                cin.clear(); 
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                
                cout << "Input is not a number.\n";
                cout << "Enter the purchase price (xx.xx)  : ";
                cin >> price;
            }
        else
        {
            notNumber = false;
        }
        }
        // check if the price is a multiple of 5 cents
        // if not multiple of 5 the loop will re-prompt the user to enter a price

        bool flag = true;
        int multiple_check = ((int)(price * 100)) % 5;
        if (multiple_check != 0)
        {
            while (flag == true)
            {

                cout << "Illegal price:  Must be a non-negative multiple\nof 5 cents.\n";

                cout << "Enter the purchase price (xx.xx)  : ";
                cin >> price;
                multiple_check = ((int(price * 100)) % 5);
                if (multiple_check == 0)
                {
                    flag = false;
                }
            }
        }
        else
        {
            flag = false;
        }

        // display menu options

        cout << "Menu for deposits:\n";
        cout << setw(3) << ""
            << "'n' - deposit a nickel\n"
            << setw(3) << ""
            << "'d' - deposit a dime\n"
            << setw(3) << ""
            << "'q' - deposit a quarter\n"
            << setw(3) << ""
            << "'o' - deposit a one dollar bill\n"
            << setw(3) << ""
            << "'f' - deposit a five dollar bill\n"
            << setw(3) << ""
            << "'c' - cancel the purchase\n";

        // conversion to display dollars and cents
        string sprice = to_string(price);
        double dollars_cost = stod(sprice.substr(0, sprice.find(".")));

        double cents_cost = stod(sprice.substr(sprice.find(".") + 1, 2));

        
        if (dollars_cost > 0)
        {
            cout << "Payment due:  " << dollars_cost << " dollars and " << cents_cost << " cents\n";
        }
        else if (dollars_cost == 0 && cents_cost >= 0)
        {
            cout << "Payment due:  " << cents_cost << " cents\n";
        }
        
        // payment and adding to stock

        char selection;
        double origprice = price;
        while (price > 0)
        {
            cout << "Indicate your deposit:  ";
            cin >> selection;
            if (selection == 'n')
            {
                price -= .05;
                nickel_stock++;
            }
            else if (selection == 'd')
            {
                price -= 0.10;
                dime_stock++;
            }
            else if (selection == 'q')
            {
                price -= 0.25;
                quarter_stock++;
            }
            else if (selection == 'o')
            {
                price -= 1.00;
                ones_stock++;
            }
            else if (selection == 'f')
            {
                price -= 5.00;
                fives_stock++;
                if (price < 0)
                {
                    break;
                }
            }
            else if (selection == 'c')
            {
                price = origprice - price;;
                sprice = to_string(price);
                dollars_cost = stod(sprice.substr(0, sprice.find(".")));
                cents_cost = stod(sprice.substr(sprice.find(".") + 1, 2));
                break;
            }
            else
            {
                cout << "Illegal selection:  " << selection << endl;
            }
            if (price < 0)
            {
                
            }
            else
            {
                sprice = to_string(price);
                dollars_cost = stod(sprice.substr(0, sprice.find(".")));

                cents_cost = stod(sprice.substr(sprice.find(".") + 1, 2));

                if (dollars_cost > 0)
                {
                    cout << "Payment due:  " << dollars_cost << " dollars and " << cents_cost << " cents\n";
                }
                else if (dollars_cost == 0 && cents_cost > 0)
                {
                    cout << "Payment due:  " << cents_cost << " cents\n";
                }
            }




        }


        // This part calculates change

        // set value of coins and bills
 
        cout << "Please take the change below.\n";

        double nickel = .05,
            dime = 0.10,
            quarter = 0.25,
            onedollar = 1.00,
            fivedollar = 5.00;
        double change = price;
            


        if (price < 0)
        {
            change = price * -1; // make change positive
        }
        
        // define variables to store amount of change for return

        int nickelchange = 0,
            dimechange = 0,
            quarterchange = 0,
            onedollarchange = 0,
            fivedollarchange = 0;
        
      // Determine the amount of change to return  

            if (change < 0.04)  // multiples of 5 will never be less than 0.04
            {
                cout << "No change due.\n";
            }
            else
            {
                while (change > 0.05)
                {
                    if ((change >= 0.25) && (quarter_stock > 0))
                    {
                        quarter_stock--;
                        change = change - quarter;
                        quarterchange++;
                        
                    }
                    else if ((change >= 0.10) && (dime_stock > 0))
                    {
                        dime_stock--;
                        change = change - dime;
                        dimechange++;
                        
                    }
                    else if (((change < 0.10) && (nickel_stock > 0)) || ((dime_stock == 0) && (change > 0.10) && (nickel_stock > 0)))
                    {
                        nickel_stock--;
                        change = change - nickel;
                        nickelchange++;
                    }
                    else
                    {
                        break;
                    }




                }

     // Display the amount of change due to user

                if (quarterchange > 0)
                {
                    cout << quarterchange << " quarters\n";
                }
                if (dimechange > 0)
                {
                    cout << dimechange << " dimes\n";
                }
                if (nickelchange > 0)
                {
                    cout << nickelchange << " nickels\n";
                }

                // Same conversion to display amount

                sprice = to_string(change);
                dollars_cost = stod(sprice.substr(0, sprice.find(".")));

                cents_cost = stod(sprice.substr(sprice.find(".") + 1, 2));

                // if statement for the case when machine is out of stock
                //prompt the user to see store manager for refund

                if ((change - .05) > 0)
                {
                    cout << "Machine is out of change.\n" << "See store manager for remaining refund.\n";
                    if (dollars_cost > 0)
                    {
                        cout << "Amount due is:  " << dollars_cost << " dollars and " << cents_cost << " cents\n";
                    }
                    else if (dollars_cost == 0 && cents_cost >= 0)
                    {
                        cout << "Amount due is:  " << cents_cost << " cents\n";
                    }
                    
                }
                


            }

        // Display updated stock
            
        cout << "Stock contains:\n";
        cout << setw(3) << ""
        << nickel_stock << " nickels\n"
        << setw(3) << ""
        << dime_stock << " dimes\n"
        << setw(3) << ""
        << quarter_stock << " quarters\n"
        << setw(3) << ""
        << ones_stock << " ones\n"
        << setw(3) << ""
        << fives_stock << " fives\n";

        // Loop to either continue or exit the program

        string answer;

        bool flag2 = true;
        while (flag2)
        {
            cout << "Do you want to continue:  ";
            cin >> answer;
            if (answer == "no")
            {
                _continue = false;
                flag2 = false;
            }
            else if (answer == "yes")
            {
                _continue = true;
                flag2 = false;
            }
            else
            {
                 cout << "Illegal selection, enter 'yes' or 'no'." << endl;
            }
        }
    }
    

}