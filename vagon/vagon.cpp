#include <iostream>

using namespace std;

class Vagon {
private:
    int vagonNumber;
    int seats;
    int passengers;

public:
    Vagon() : vagonNumber(0), seats(0), passengers(0) {}
    Vagon(int number, int seatCount, int passengerCount)
        : vagonNumber(number), seats(seatCount), passengers(passengerCount) {}
    void Show() const {
        cout << "Vagon number: " << vagonNumber
            << ", Seats: " << seats
            << ", Passengers: " << passengers << endl;
    }
    void AddPassenger() {
        if (passengers < seats) {
            passengers++;
            cout << "One passenger added. Total passengers: " << passengers << endl;
        }
        else {
            cout << "No available seats!" << endl;
        }
    }
    int getSeats() const { return seats; }
    int getPassengers() const { return passengers; }
    int getVagonNumber() const { return vagonNumber; }
};

class Train {
private:
    string model;
    int numWagons;
    Vagon* wagons;

public:
    Train() : model(""), numWagons(0), wagons(nullptr) {}
    Train(string mod, int num) : model(mod), numWagons(num) {
        wagons = new Vagon[numWagons];
    }
    Train(const Train& other) : model(other.model), numWagons(other.numWagons) {
        wagons = new Vagon[numWagons];
        for (int i = 0; i < numWagons; ++i) {
            wagons[i] = other.wagons[i];
        }
    }
    ~Train() {
        delete[] wagons;
    }
    void AddVagon(const Vagon& newVagon) {
        Vagon* temp = new Vagon[numWagons + 1];
        for (int i = 0; i < numWagons; i++) {
            temp[i] = wagons[i];
        }
        temp[numWagons] = newVagon;
        delete[] wagons;
        wagons = temp;
        numWagons++;
    }
    void AddPassengerToVagon(int vagonNumber) {
        for (int i = 0; i < numWagons; i++) {
            if (wagons[i].getVagonNumber() == vagonNumber) {
                wagons[i].AddPassenger();
                return;
            }
        }
        cout << "Vagon number " << vagonNumber << " not found." << endl;
    }
    void Show() const {
        cout << "Train model: " << model
            << ", Number of wagons: " << numWagons << endl;

        for (int i = 0; i < numWagons; i++) {
            wagons[i].Show();
        }
    }
};

int main() {
    Train train("Express", 2);
    Vagon v1(1, 50, 30);
    Vagon v2(2, 60, 45);
    train.AddVagon(v1);
    train.AddVagon(v2);
    train.Show();
    train.AddPassengerToVagon(1);
    train.Show();

}
