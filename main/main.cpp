//
//  main.cpp
//  main
//
//  Created by Michael Emperador on 4/9/18.
//  Copyright © 2018 Michael Emperador. All rights reserved.
//

#include "main.h"

void heart(void) {
    cout << "Heart Beat" << endl;
}

void lungs(void) {
    cout << "Lung Contraction" << endl;
}

void blank() {
    cout << "In Blank" << endl;
    return;
}

/**
 *right now I am only working on integrating your tree functionality
 *I am attempting to use the print functionality after adding the Tasks through the RTOS interface (this calls the insert function)
 *
 *TASK::Ready variable was set to 1 for debugging purposes it is intended to be set to 0 when actually using.
 */



int main(int argc, const char * argv[]) {
    //Initializes TIMER
    timeInit();
/*
*changed constructor to take in a time delay  in micro seconds this delay happens before the timeres get called
*this avoids constant pointless looping.
* The UI should also allow an input of the delay
*
*/
    RTOS mainRTOS(200000);
/*
 *THIS IS THE NEW INTERFACE THE UI WILL INTERACT WITH:
 *ex:
 *HASH: will return the Function pointer
 *STRING: userinput for name of function
 *
 *NOTE: If the hash function returns null, alert the user it doesn't exist and re-prompt them for
 *      a new string. 
 *
 *
 * ********mainRTOS.createTask(hash(userInput), priority);*********
 */
    
    
//These call HelperFUNCTIONs :: insert()
    mainRTOS.createTask(&heart, 200);
    mainRTOS.createTask(&lungs, 100);
    
    
    for (int i = 24; i > 0; i--){
       mainRTOS.createTask(&heart, (i * 5) % 99);
    }
    
    //INSERTION OF TIMER FOR RTOS TO INTERACT WITH
    mainRTOS.insertTimerFunction(&timeFunction);
    while(1) {
        mainRTOS.startOS();
    }
    return 0;
}






