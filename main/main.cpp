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

int main(int argc, const char * argv[]) {
    timeInit();
    node* first_head = NULL;
    RTOS mainRTOS(first_head, &heart, 200);
    mainRTOS.createTask(NULL, -1);
    mainRTOS.createTask(&lungs, 100);
    
//    for (int i = 24; i > 0; i--){
//       mainRTOS.createTask(&heart,i % 10);
//    }
    mainRTOS.insertTimerFunction(&timeFunction);
    while(1) {
        mainRTOS.startOS();
    }
    return 0;
}






