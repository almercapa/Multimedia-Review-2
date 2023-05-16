#include <array>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctype.h>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

// Calculator methods
int add(int num1, int num2);
int sub(int num1, int num2);
double divi(int num1, int num2);
int mult(int num1, int num2);
int expo(int num1, int num2);
double mod(int num1, int num2);
void SelectionSort(vector<double>&);
void BubbleSort(vector<double>&);
// Donator center methods
void ShellSort(vector<string>&, vector<string>&, vector<int>&, vector<double>&, vector<string>&);
void SelectionSort(vector<double>&, vector<string>&, vector<string>&, vector<int>&, vector<string>&);
void BubbleSort(vector<int>&, vector<string>&, vector<string>&, vector<double>&, vector<string>&);
// Text game method
void ShellSort(vector<string>&);

int main() {
  // Allows for random input
  srand((unsigned) time(0));
  //MAIN MENU
  int choice;
  cout << "1. Calculator";
  cout << "\n2. Donation Center";
  cout << "\n3. Adventure Game\n";
  cin >> choice;
  // LOOP
  while (choice != 4) {

    // PART 1: CALCULATOR
    if (choice == 1) {
      int op = 0, num1 = 0, num2 = 0, order;
      double result;
      string dummy, response, sort;
      vector <double> ans;
      // variables for calculator part
      cout << "\nWould you like to make a calculation (Y/N)? ";
      cin >> response;
      while (response == "Y" || response == "y") {
        cout << "\nWhich operation would you like to use?\n1.)Add\n2.)Subtract\n3.)Multiply\n4.)Divide\n5.)Exponent\n6.)Modulus\n";
        getline(cin, dummy);
        cin >> op;

        // get both numbers
        cout << "\nChoose number one: ";
        cin >> num1;
        cout << "\nChoose number two: ";
        cin >> num2;

        // CALLING ALL OPERATION FUNCTIONS
        if (op == 1) { // addition
          result = add(num1, num2);
          cout << "\nResult: " << add(num1, num2) << endl;
        } else if (op == 2) { // subtraction
          result = sub(num1, num2);
          cout << "\nResult: " << sub(num1, num2) << endl;
        } else if (op == 3) { // multiplication
          result = mult(num1, num2);
          cout << "\nResult: " << mult(num1, num2) << endl;
        } else if (op == 4) { // division
          cout.setf(ios::fixed);
          cout.setf(ios::showpoint);
          result = divi(num1, num2);
          cout << "\nResult: " << setprecision(2) << divi(num1, num2) << endl;
        } else if (op == 5) { // exponent
          result = expo(num1, num2);
          cout << "\nResult: " << expo(num1, num2) << endl;
        } else if (op == 6) { // Modulus
          result = mod(num1, num2);
          cout << "\nResult: " << mod(num1, num2) << endl;
        }
        ans.push_back(result);

        cout << "\nWould you like to sort the results so far (Y/N)? ";
        cin >> sort;

        //SORTING
        if (sort == "Y" || sort == "y") {
          cout << "\n1. Ascending";
          cout << "\n2. Descending";
          cout << "\nHow would you like to sort these variables? ";
          cin >> order;
          // Sorts ascending or descending depending on order input
          if (order == 1) {
            SelectionSort(ans);
          }
          else if (order == 2) {
            BubbleSort(ans);
          }

          // For loop printing each value in ans
          for (int index = 0; index < ans.size(); index++) {
            cout << ans[index] << endl;
          }
        }
        // Asks to replay calculator section
        cout << "\nWould you like to make another calculation (Y/N)? ";
        cin >> response;
      }
    }

    //DONATION CENTER
    else if(choice == 2){
      double price;
      int id, sorting;
      string name,color,type,alpha,dummy;
      string donate = "Y";
      //variables
      
      cout << "\n------------------------------Welcome to Sheck Wes Incorporated!------------------------------";
      // Declaring vectors
      vector <int> ids;
      vector <string> names;
      vector <double> prices;
      vector <string> colors;
      vector <string> types;

      // While loop allowing center to continue running
      while (donate == "Y" || donate == "y") {
        // User input for all item info
        cout << "\n\nWhat is the name of the item your donating? ";
        getline(cin,dummy);
        getline(cin,name); 
        // Adds info to correlated vector
        names.push_back(name);
        cout << "\n\nWhat is the price of " << name << "? ";
        cin >> price; 
        prices.push_back(price);
        cout << "\n\nWhat is the color of " << name << "? ";
        getline(cin,dummy);
        getline(cin,color);
        colors.push_back(color);
        cout << "\n\nWhat type of item is " << name << "? ";
        getline(cin, dummy);
        getline(cin, type);
        types.push_back(type);
        // Creates ID based on random number
        id = (rand() % 999) + 1;
        ids.push_back(id);

        // Asks to sort results
        cout << "\nWould you like to sort the results so far (Y/N)? ";
        cin >> alpha;
        
        if (alpha == "Y" || alpha == "y") {
          // List of sorting options
          cout << "\n\n1. Colors";
          cout << "\n2. Names";
          cout << "\n3. IDs";
          cout << "\n4. Prices";
          cout << "\n5. Types";
          cout << "\nHow would you like to sort the results? ";
          cin >> sorting;
          if (sorting == 1) {
            // Parallel vectors included in sorting (keeps all vectors in line during each sort)
            ShellSort(colors, names, ids, prices, types);
            cout << endl;
            // Prints all values in vector
            for (int index = 0; index < names.size(); index++) {
              cout << names[index] << " --> " << colors[index] << endl;
            }
          }
          // Each sorting method is based on the variable type (shell sort for strings)
          if (sorting == 2) {
            ShellSort(names, colors, ids, prices, types);
            cout << endl;
            for (int index = 0; index < names.size(); index++) {
              cout << names[index] << endl;
            }
          }
          // Bubble sort for integers
          if (sorting == 3) {
            BubbleSort(ids, names, colors, prices, types);
            for (int index = 0; index < names.size(); index++) {
              cout << names[index] << " --> #" << ids[index] << endl;
            }
          }
          // Selection sort for prices
          if (sorting == 4) {
            SelectionSort(prices, names, colors, ids, types);
            for (int index = 0; index < names.size(); index++) {
              cout << names[index] << " --> $" << prices[index] << endl;
            }
          }
          if (sorting == 5) {
            ShellSort(types, names, ids, prices, colors);
            for (int index = 0; index < names.size(); index++) {
              cout << names[index] << " --> " << types[index] << endl;
            }
          }
        }
        // Asks if user would like to make another donation
        cout << "\nWould you like to make another donation? (Y/N) ";
        cin >> donate;
      }
    }

    //GAME!!!  
    else if(choice ==3){
      // Beginner variable / Vector
      bool play = true;
      vector <string> drops = {"V-Bucks", "Apology Video", "Strand of Hair", "Travis Scott Burger", "Yeezy Foam Runners", "Travis Scott Reese's Puffs", "Travis Scott Jordans", "Astroworld Vinyl", "Trap House", "Travis Scott McDonald's Merch"}; 

      // While loop continuing until user no longer wishes to play
      while (play == true) {
      cout << "\nWe back...\n\n\n";
      cout << "\nHello Sheck Wes. You are much needed in battle. Go forth!";
      cout << "\nYou slowly walk in to battle with Mo Bamba blasting in your Apple Earbuds from 2011. The ground is stained red...";
      cout << "\nYou walk for a bit more and see the cause for all this havoc. Travy Daddy...";
      cout << "\nyou notice Travy Daddy is in a man diaper but thats besides the point! This battle will be legendary!";
      cout << "\nObjective: Vanquish Travy Daddy!";
      srand((unsigned) time(0));
        // Variables
      int hp = 100, opp = 200, backup, repost, refund, crease, frat, attack, microphone, chance;

      // Continues while either player / enemy is above 0 health
      while (opp > 0 && hp > 0) {
      //ATTACKING
      cout << "\n\n\nPlayer: " << hp;
      cout << "\nTravy Daddy: " << opp;
      cout << "\nHere are your attacks Mr. Wes!";
      cout << "\n1.) BACKUP?"; // send in quandale dingle
      cout << "\n2.) REPOST"; // apologize to travy
      cout << "\n3.) REFUND"; // refund his fortnite skin
      cout << "\n4.) CREASE"; // crease the jordans in front of him
      cout << "\n5.) FRAT PARTY\n"; // uninvite him from the frat party

      cin >> attack;

      //what the attacks do
      if(attack == 1){
        // Creates random attack value based on the given parameters
        // In this case, any value from 50-75
        backup = (rand() % 75) + 50;
        opp = opp - backup;
        cout << "\nYou call up your homeboy from Florida, Quandale Dingle. Quandale Dingle attacks Travis for " << backup << " damage! AUGHHHHHHHHHHHH";
        // Enemy attack given a chance
        chance = (rand() % 10) + 1;
        // Misses if the chance is 6-10
        if (chance > 5) {
          cout << "\nTravy chucks his microphone at you! However, it missed!";
        } else {
          // Connects otherwise for a random amount of damage
          microphone = (rand() % 50) + 1;
          hp = hp - microphone;
          cout << "\nTravy chucks his microphone at you for " << microphone << " damage!";
        }
      }
      else if(attack == 2){
        repost = (rand() % 100) + 1;
        opp = opp - repost;
        cout << "\nYou... apologize to Travy??? Travy is confused -- he's never heard anything other than autotune. Dealt " << repost << " damage!";
        chance = (rand() % 10) + 1;
        if (chance > 5) {
          cout << "\nTravy chucks his microphone at you! However, it missed!";
        } else {
          microphone = (rand() % 50) + 1;
          hp = hp - microphone;
          cout << "\nTravy chucks his microphone at you for " << microphone << " damage!";
        }
      }
      else if(attack == 3){
        refund = (rand() % 30) + 10;
        opp = opp - refund;
        cout << "\nYou refund Travy Daddy's Fortnite skin! What a shame though -- he's too busy buying the Chun-Li skin with Mr. Botero! Dealt " << refund << " damage!";
        chance = (rand() % 10) + 1;
        if (chance > 5) {
          cout << "\nTravy chucks his microphone at you! However, it missed!";
        } else {
          microphone = (rand() % 50) + 1;
          hp = hp - microphone;
          cout << "\nTravy chucks his microphone at you for " << microphone << " damage!";
        }
      }
      else if(attack == 4){
        crease = (rand() % 35) + 1;
        opp = opp - crease;
        cout << "\nYou crease the Jordans in front of Travy Patty! You thought it would work -- but the shoes were from Costco! Dealt " << crease << " damage!";
        chance = (rand() % 10) + 1;
        if (chance > 5) {
          cout << "\nTravy chucks his microphone at you! However, it missed!";
        } else {
          microphone = (rand() % 50) + 1;
          hp = hp - microphone;
          cout << "\nTravy chucks his microphone at you for " << microphone << " damage!";
        }
      }
      else if(attack == 5){
        // Random frat chance for player
        frat = (rand() % 20) + 10;
        // One shots opponent if the frat value is very specifically 19, deals a miniscule amount of damage otherwise
        if (frat == 19) {
          frat = 200;
          cout << "\nTravy's homeboy told him 'last night was a movie. crazy. lit. movie!' SUPER EFFECTIVE -- Dealt " << frat << " damage!";
          opp = opp - frat;
          chance = (rand() % 10) + 1;
          if (chance > 5) {
            cout << "\nTravy chucks his microphone at you! However, it missed!";
          } else {
            microphone = (rand() % 50) + 1;
            hp = hp - microphone;
            cout << "\nTravy chucks his microphone at you for " << microphone << " damage!";
          }
        } else {
          opp = opp - frat;
          cout << "\nYou uninvite Travy Daddy from the annual frat party! It's a shame though -- the party usually takes place in his massive trap house! Dealt " << frat << " damage!";
          chance = (rand() % 10) + 1;
          if (chance > 5) {
            cout << "\nTravy chucks his microphone at you! However, it missed!";
          } else {
            microphone = (rand() % 50) + 1;
            hp = hp - microphone;
            cout << "\nTravy chucks his microphone at you for " << microphone << " damage!";
          }
        }
      }
      }
      // Restart variable
      string restart;
      // Plays if opponent is defeated
      if (opp <= 0) {
        cout << "\n\n\nSheck Wes charges his final attack: HATE CRIME! He calls out 'MO BAMBA >>> SICKO MID' and Travy Daddy evaporates because he can't handle peak! YOU WIN!";
        cout << "\nYou win the following items:\n";
        // Sorts drops won by player
        ShellSort(drops);
        cout << endl;
        for (int index = 0; index < drops.size(); index++) {
        cout << drops[index] << endl;
        }
        // Prompts user for restart
        cout << "\n\nWould you like to play again (Y/N)? ";
        cin >> restart;
      } else {
        // Plays if player is defeated
        cout << "\n\n\nGame Over! Travy got tired of listening to MID BAMBA";
        // Prompts for restart
        cout << "\n\nWould you like to play again (Y/N)? ";
        cin >> restart;
      }
        // Boolean is changed depending on user input
        if (restart == "Y") {
          play = true;
        } else {
          play = false;
        }
      }
    }

    // Restarted menu
    cout << "1. Calculator";
    cout << "\n2. Donation Center";
    cout << "\n3. Adventure Game\n";
    cin >> choice;
  }
}

int add(int num1, int num2) {
  double total = num1 + num2;
  return total;
  
}

int sub(int num1, int num2) {
  double total = num1 - num2;
  return total;

}

double divi(int num1, int num2) {
  double total = (num1 * 1.0) / num2;
  return total;
}

int mult(int num1, int num2) {
  double total = num1 * num2;
  return total;

}

int expo(int num1, int num2) {
  double total = pow(num1, num2);
  return total;

}

double mod(int num1, int num2) {
  double total = num1 % num2;
  return total;
}

void SelectionSort(vector <double> &num)
  {
    double i, j, first, temp;
    double numLength = num.size();
    for (i= numLength - 1; i > 0; i--)
       {
          first = 0; // initialize to subscript of first element
          for (j=1; j<=i; j++) // locate smallest between positions 1 and i.
            {
              if (num[j] > num[first])
                first = j;
            }
           temp = num[first]; // Swap smallest found with element in position i.
           num[first] = num[i];
           num[i] = temp;
       }
  }

void BubbleSort(vector <double>& num)
  {
    double i, j, flag = 1; // set flag to 1 to start first pass
    double temp; // holding variable
    double numLength = num.size(); 
    for(i = 1; (i <= numLength) && flag; i++)
       {
          flag = 0;
          for (j=0; j < (numLength -1); j++)
            {
              if (num[j+1] > num[j])// ascending order simply changes to <
                { 
                  temp = num[j];// swap elements
                  num[j] = num[j+1];
                  num[j+1] = temp;
                  flag = 1; // indicates that a swap occurred.
                }
            }
       }
  } 

void ShellSort(vector <string> &colors, vector <string> &names, vector <int> &ids, vector <double> &prices, vector <string> &types)//method
  {
    int i, flag = 1, numLength = colors.size();
    string temp, temp2, temp5; //change to string because working with string vector
    int temp3;
    int temp4;
    int d = numLength;
    while( flag || (d > 1)) // boolean flag (true when not equal to 0)
       {
          flag = 0; // reset flag to 0 to check for future swaps
          d = (d+1) / 2;
          for (i = 0; i < (numLength - d); i++)   
            {
              if (colors[i + d] < colors[i])//have to change it to less than to properly sort 
                {
                  temp = colors[i + d]; // swap positions i+d and i
                  colors[i + d] = colors[i];
                  colors[i] = temp;

                  temp2 = names[i + d]; 
                  names[i + d] = names[i];
                  names[i] = temp2;

                  temp3 = ids[i + d]; 
                  ids[i + d] = ids[i];
                  ids[i] = temp3;

                  temp4 = prices[i + d]; 
                  prices[i + d] = prices[i];
                  prices[i] = temp4;

                  temp5 = types[i + d]; 
                  types[i + d] = types[i];
                  types[i] = temp5;
                  flag = 1; // tells swap has occurred
                }
             }
       }
  }

void SelectionSort(vector <double> &prices, vector <string> &names, vector <string> &colors, vector <int> &ids, vector <string> &types)
  {
    double i, j, first, temp;
    string temp2;
    string temp3;
    string temp5;
    int temp4;
    double numLength = prices.size();
    for (i= numLength - 1; i > 0; i--)
       {
          first = 0; // initialize to subscript of first element
          for (j=1; j<=i; j++) // locate smallest between positions 1 and i.
            {
              if (prices[j] > prices[first])
                first = j;
            }
           temp = prices[first]; // Swap smallest found with element in position i.
           prices[first] = prices[i];
           prices[i] = temp;

           temp2 = names[first]; // Swap smallest found with element in position i.
           names[first] = names[i];
           names[i] = temp2;

           temp3 = colors[first]; // Swap smallest found with element in position i.
           colors[first] = colors[i];
           colors[i] = temp3;

           temp4 = ids[first]; // Swap smallest found with element in position i.
           ids[first] = ids[i];
           ids[i] = temp4;

           temp5 = types[first]; // Swap smallest found with element in position i.
           types[first] = types[i];
           types[i] = temp5;
       }
  }

void BubbleSort(vector <int>& num, vector <string> &num2, vector <string> &num3, vector <double> &num4, vector <string> &num5) {
    double i, j, flag = 1; // set flag to 1 to start first pass
    int temp; // holding variable
    double temp4;
    string temp3, temp2, temp5;
    double numLength = num.size(); 
    for(i = 1; (i <= numLength) && flag; i++)
       {
          flag = 0;
          for (j=0; j < (numLength -1); j++)
            {
              if (num[j+1] > num[j])// ascending order simply changes to <
                { 
                  temp = num[j];// swap elements
                  num[j] = num[j+1];
                  num[j+1] = temp;

                  temp2 = num2[j];// swap elements
                  num2[j] = num2[j+1];
                  num2[j+1] = temp2;

                  temp3 = num3[j];// swap elements
                  num3[j] = num3[j+1];
                  num3[j+1] = temp3;

                  temp4 = num4[j];// swap elements
                  num4[j] = num4[j+1];
                  num4[j+1] = temp4;

                  temp5 = num5[j];// swap elements
                  num5[j] = num5[j+1];
                  num5[j+1] = temp5;
                  flag = 1; // indicates that a swap occurred.
                }
            }
       }
  } 

void ShellSort(vector <string> &colors)//method
  {
    int i, flag = 1, numLength = colors.size();
    string temp, temp2; //change to string because working with string vector
    int temp3;
    int temp4;
    int d = numLength;
    while( flag || (d > 1)) // boolean flag (true when not equal to 0)
       {
          flag = 0; // reset flag to 0 to check for future swaps
          d = (d+1) / 2;
          for (i = 0; i < (numLength - d); i++)   
            {
              if (colors[i + d] < colors[i])//have to change it to less than to properly sort 
                {
                  temp = colors[i + d]; // swap positions i+d and i
                  colors[i + d] = colors[i];
                  colors[i] = temp;
                  flag = 1; // tells swap has occurred
                }
             }
       }
  }
