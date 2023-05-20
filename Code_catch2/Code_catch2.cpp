#include <iostream>
#include <string>
#include <locale>

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

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
        }
        else {
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
        }
        else {
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


TEST_CASE("setSpeed method testing") {
    dist object;
    SECTION("Positive tests") {
        REQUIRE(object.setSpeed(1) == 0);
        REQUIRE(object.setSpeed(300) == 0);
        REQUIRE(object.setSpeed(100) == 0);
    }
    SECTION("Negative tests") {
        REQUIRE(object.setSpeed(0) == -1);
        REQUIRE(object.setSpeed(-1) == -1);
        REQUIRE(object.setSpeed(301) == -1);
    }
}

TEST_CASE("setTime method testing") {
    dist object;
    SECTION("Positive tests") {
        REQUIRE(object.setTime(1) == 0);
        REQUIRE(object.setTime(360) == 0);
        REQUIRE(object.setTime(200) == 0);
    }
    SECTION("Negative tests") {
        REQUIRE(object.setTime(0) == -1);
        REQUIRE(object.setTime(-1) == -1);
        REQUIRE(object.setTime(361) == -1);
    }
}