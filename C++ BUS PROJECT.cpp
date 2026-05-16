#include <iostream>
using namespace std;

// ---------------- CONSTANTS ----------------

const int TOTAL_ROUTES = 4;
const int TOTAL_SEATS = 10;

// ---------------- ROUTES ----------------

string routes[TOTAL_ROUTES] =
{
    "Lahore-Islamabad",
    "Lahore-Karachi",
    "Faisalabad-Multan",
    "Rawalpindi-Murree"
};

// ---------------- ARRAYS ----------------

// Passenger Names
string passengerNames[TOTAL_ROUTES][TOTAL_SEATS];

// Seat Booking Status
bool seatBooked[TOTAL_ROUTES][TOTAL_SEATS] = {false};

// Current Selected Route
int currentRoute = -1;

// ---------------- FUNCTIONS ----------------

// Main Menu Function
void showMenu()
{
    cout << "\n=====================================\n";
    cout << "       BUS RESERVATION SYSTEM\n";
    cout << "=====================================\n";

    cout << "1. Show Bus Routes\n";
    cout << "2. Select Route\n";
    cout << "3. Show Seats\n";
    cout << "4. Book Seat\n";
    cout << "5. Cancel Booking\n";
    cout << "6. Exit\n";

    cout << "=====================================\n";
}

// Show Routes Function
void showRoutes()
{
    cout << "\n========== AVAILABLE ROUTES ==========\n";

    for(int i = 0; i < TOTAL_ROUTES; i++)
    {
        cout << i + 1 << ". "
             << routes[i] << endl;
    }
}

// Select Route Function
void selectRoute()
{
    int choice;

    showRoutes();

    cout << "\nEnter Route Number: ";
    cin >> choice;

    if(choice >= 1 && choice <= TOTAL_ROUTES)
    {
        currentRoute = choice - 1;

        cout << "\nRoute Selected Successfully!\n";
        cout << "Selected Route: "
             << routes[currentRoute] << endl;
    }
    else
    {
        cout << "\nInvalid Route Number!\n";
    }
}

// Show Seats Function
void showSeats()
{
    if(currentRoute == -1)
    {
        cout << "\nPlease Select a Route First!\n";
        return;
    }

    cout << "\n=====================================\n";
    cout << "Route: " << routes[currentRoute] << endl;
    cout << "=====================================\n";

    for(int i = 0; i < TOTAL_SEATS; i++)
    {
        if(seatBooked[currentRoute][i] == false)
        {
            cout << "Seat "
                 << i + 1
                 << " : Available\n";
        }
        else
        {
            cout << "Seat "
                 << i + 1
                 << " : Booked by "
                 << passengerNames[currentRoute][i]
                 << endl;
        }
    }
}

// Book Seat Function
void bookSeat()
{
    if(currentRoute == -1)
    {
        cout << "\nPlease Select a Route First!\n";
        return;
    }

    int seatNo;
    string name;

    showSeats();

    cout << "\nEnter Seat Number (1-10): ";
    cin >> seatNo;

    // Validation
    if(seatNo < 1 || seatNo > TOTAL_SEATS)
    {
        cout << "Invalid Seat Number!\n";
        return;
    }

    // Check if already booked
    if(seatBooked[currentRoute][seatNo - 1] == true)
    {
        cout << "Seat Already Booked!\n";
        return;
    }

    cout << "Enter Passenger Name: ";
    cin >> name;

    // Save Data
    passengerNames[currentRoute][seatNo - 1] = name;

    seatBooked[currentRoute][seatNo - 1] = true;

    cout << "\nSeat Booked Successfully!\n";

    cout << "Passenger Name : "
         << passengerNames[currentRoute][seatNo - 1]
         << endl;

    cout << "Route : "
         << routes[currentRoute]
         << endl;

    cout << "Seat Number : "
         << seatNo
         << endl;
}

// Cancel Booking Function
void cancelBooking()
{
    if(currentRoute == -1)
    {
        cout << "\nPlease Select a Route First!\n";
        return;
    }

    int seatNo;

    showSeats();

    cout << "\nEnter Seat Number to Cancel: ";
    cin >> seatNo;

    // Validation
    if(seatNo < 1 || seatNo > TOTAL_SEATS)
    {
        cout << "Invalid Seat Number!\n";
        return;
    }

    // Check if seat is empty
    if(seatBooked[currentRoute][seatNo - 1] == false)
    {
        cout << "Seat Already Empty!\n";
        return;
    }

    // Cancel Booking
    seatBooked[currentRoute][seatNo - 1] = false;

    passengerNames[currentRoute][seatNo - 1] = "";

    cout << "\nBooking Cancelled Successfully!\n";
}

// ---------------- MAIN FUNCTION ----------------

int main()
{
    int choice;

    do
    {
        showMenu();

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                showRoutes();
                break;

            case 2:
                selectRoute();
                break;

            case 3:
                showSeats();
                break;

            case 4:
                bookSeat();
                break;

            case 5:
                cancelBooking();
                break;

            case 6:
                cout << "\nThank You For Using The System!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}
