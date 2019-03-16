#include <chrono>
#include <vector>

#include "robot.h"

using namespace std::chrono;
using namespace elma;
using namespace robot;

Robot::Robot() : StateMachine("robot") {

    // Define state machine initial states and transitions here
    set_initial(off);
    set_propagate(false);
    add_transition("on", off, on);
    //add_transition("wander", on, wander);            
    //add_transition("off", wander, off);
    add_transition("off", on, off);

    // Make sure we start in the right condition
    //reset();
}


void Robot::turnOn() {
   // _start_time = high_resolution_clock::now();
   string currE = "Robot turned on";
   addEvent(currE);
}

void Robot::turnOff() {
   // _elapsed = high_resolution_clock::duration::zero();
   // _laps.clear();
   string currE = "Robot turned off";
   addEvent(currE);
}

void Robot::addEvent(string str) {
    _currEvents.push_back(str);
}
/*
void Robot::wander() {
    //_elapsed += high_resolution_clock::now() - _start_time;
}*/
