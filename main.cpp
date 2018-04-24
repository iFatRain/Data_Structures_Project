//
//  main.cpp
//  main
//
//  Created by Michael Emperador on 4/9/18.
//  Copyright © 2018 Michael Emperador. All rights reserved.
//

#include "main.h"

/* commented these out because multiple declarations
 * void heart(void) {
    cout << "Heart Beat" << endl;
}

void lungs(void) {
    cout << "Lung Contraction" << endl;
}

void blank() {
    cout << "In Blank" << endl;
    return;
}*/

/**
 *right now I am only working on integrating your tree functionality
 *I am attempting to use the print functionality after adding the Tasks through the RTOS interface (this calls the insert function)
 *
 *TASK::Ready variable was set to 1 for debugging purposes it is intended to be set to 0 when actually using.
 */



int main(int argc, const char * argv[]) {
    //Initializes TIMER
    timeInit();

    // Adds all functions to hash table to make them available
    hashtable hash;
    hash.poparray("heart", &heart);
    hash.poparray("brain", &brain);
    hash.poparray("lungs", &lungs);
    hash.poparray("liver", &liver);
    hash.poparray("kidneys", &kidneys);
    hash.poparray("spleen", &spleen);
    hash.poparray("pancreas", &pancreas);
    hash.poparray("stomach",&stomach);




/*
*changed constructor to take in a time delay  in micro seconds this delay happens before the timeres get called
*this avoids constant pointless looping.
* The UI should also allow an input of the delay
*
*/
    RTOS mainRTOS(0);


    //Variable Dec's for UI

    char inputVar;
    string userInput;
    int priorityVal;
    bool enableFunc = true;


//This is where im adding the new UI, All the functions needed to be added to the hashtable above because
// theres no way to prompt passing in the address of functions from user input that I know of

    cout << "Welcome!" << endl;

    while(enableFunc) {
        cout << "\nWould you like to enable a function? [y/n]: ";
        cin >> inputVar;
        if (inputVar == 'y' || inputVar == 'Y') {
            cout << "Input the function name: ";
            cin >> userInput;
            if(hash.getfunction(userInput) == NULL){
                cout << "Null Function!!!";
                break;
            }
            cout << "Input the desired priority: ";
            cin >> priorityVal;




            mainRTOS.createTask(hash.getfunction(userInput), priorityVal);



        }
        else if (inputVar == 'n' || inputVar == 'N'){
            enableFunc = false;
            cout << "Starting RTOS..." << endl << endl;
        }
        else {
            cout << "Please input y/Y or n/N.";
        }

    }

    
   // for (int i = 24; i > 0; i--){
    //   mainRTOS.createTask(&heart, (i * 5) % 99);
    //}


    mainRTOS.insertTimerFunction(&timeFunction);
    while(1) {
        mainRTOS.startOS();
    }
    return 0;
}






