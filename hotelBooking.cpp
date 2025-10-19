#include <iostream>
using namespace std;

class Room
{
public:
    int roomNumber;
    string roomType;
    float pricePerNight;
    bool isBooked;

    Room()
    {
        isBooked = false;
    }

    void setRoomDetails()
    {
        cout << "Enter Room Number: ";
        cin >> roomNumber;
        cout << "Enter Room Type: ";
        cin >> roomType;
        cout << "Enter Price per Night: ";
        cin >> pricePerNight;
        isBooked = false;
        cout << "Room added successfully!\n\n";
    }

    void displayRoomDetails()
    {
        cout << "Room Number: " << roomNumber << endl;
        cout << "Room Type: " << roomType << endl;
        cout << "Price: " << pricePerNight << endl;
        cout << "Status: " << (isBooked ? "Booked" : "Available") << endl;
    }
};

class Customer
{
public:
    string name;
    long long int phoneNumber;
    int stayDays;

    void inputCustomerDetails()
    {
        cout << "---- Customer Details ----\n";
        cout << "Enter your Name: ";
        cin >> name;
        cout << "Enter your Phone Number: ";
        cin >> phoneNumber;
        cout << "Enter the days you Stay: ";
        cin >> stayDays;
    }

    void displayCustomerDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Days Stayed: " << stayDays << endl;
    }
};

class Hotel : public Room
{
public:
    Room roomList[10];
    int totalRooms;
    float totalEarning;

    Hotel()
    {
        totalRooms = 0;
        totalEarning = 0;
    }

    void addRoom()
    {
        if (totalRooms < 10)
        {
            cout << "---- Add New Room ----\n";
            roomList[totalRooms].setRoomDetails();
            totalRooms++;
        }
        else
        {
            cout << "Rooms Limit Reached\n";
        }
    }

    void showAllRooms()
    {
        cout << "Room Details\n";
        for (int i = 0; i < totalRooms; i++)
        {
            roomList[i].displayRoomDetails();
        }
    }

    void bookRoom()
    {
        int rNo;
        cout << "Enter Room Number to Book: ";
        cin >> rNo;

        for (int i = 0; i < totalRooms; i++)
        {
            if (roomList[i].roomNumber == rNo)
            {
                if (roomList[i].isBooked)
                {
                    cout << "Room is Booked!\n";
                    return;
                }
                else
                {
                    Customer c;
                    c.inputCustomerDetails();
                    float totalCost = roomList[i].pricePerNight * c.stayDays;
                    cout << "Booked Successful!\n";
                    cout << "Total Cost: " << totalCost << endl;
                    totalEarning += totalCost;
                    roomList[i].isBooked = true;
                    return;
                }
            }
        }
        cout << "Room not found\n";
    }

    void showTotalEarnings()
    {
        cout << "\nTotal Earnings: " << totalEarning << endl;
    }
};

int main()
{
    Hotel h;
    int choice;

    do
    {
        cout << "\n===== Hotel Room Booking System =====\n";
        cout << "1. Add Room\n";
        cout << "2. Show All Rooms\n";
        cout << "3. Book a Room\n";
        cout << "4. Show Total Earnings\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            h.addRoom();
            break;
        case 2:
            h.showAllRooms();
            break;
        case 3:
            h.bookRoom();
            break;
        case 4:
            h.showTotalEarnings();
            break;
        case 5:
            cout << "Exiting... Thank you!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
