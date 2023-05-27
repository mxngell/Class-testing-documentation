#include <iostream>
#include <string>
#include <locale>
#include <array>

using namespace std;

class dist {
private: 
    float speed;
    int time;
public:
    int setSpeed(float currentSpeed) {
        int errorCode{ 0 };
        if (currentSpeed < 1 || currentSpeed > 300) {
            errorCode = -1;
        } else {
            speed = currentSpeed;
        }       
        return errorCode;
    }
    float getSpeed() {
        return speed;
    }

    int setTime(int currentTime) {
        int errorCode{ 0 };
        if (currentTime < 1 || currentTime > 360) {
            errorCode = -1;
        } else {
            time = currentTime;
        }
        return errorCode;
    }
    float getTime() {
        return time;
    }

    int calculateDist() {
        int distance = (speed * 60) * time;
        return distance;
    }

    string getAllValues() {
        string result = to_string(speed) + " " + to_string(time);
        return result;
    }
};

int main() {
    dist object;

    cerr << object.setSpeed(231.25) << endl;
    cerr << object.getSpeed() << endl << endl;

    cerr << object.setTime(32) << endl;
    cerr << object.getTime() << endl << endl; 

    cerr << object.calculateDist() << endl << endl;

    cerr << object.getAllValues();
}


