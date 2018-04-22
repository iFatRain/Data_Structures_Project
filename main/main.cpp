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
 */



int main(int argc, const char * argv[]) {
    timeInit();
    node* first_head = NULL;
    RTOS mainRTOS(first_head, &heart, 200);
   // mainRTOS.createTask(NULL, -1);
    mainRTOS.createTask(&lungs, 100);
    
    for (int i = 24; i > 0; i--){
       mainRTOS.createTask(&heart,i % 99);
    }
    mainRTOS.insertTimerFunction(&timeFunction);
//    while(1) {
//        mainRTOS.startOS();
//    }
    printTree(first_head);
    return 0;
}






