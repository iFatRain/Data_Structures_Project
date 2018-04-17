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
    return;
}

int main(int argc, const char * argv[]) {
    node* first_head = NULL;
    node* RTOS_list_head = NULL;
    
    RTOS_list_head_insert(first_head,RTOS_list_head, 5);
    RTOS_list_insert(NULL, RTOS_list_head, -1);
    RTOS_list_insert(NULL,RTOS_list_head, 1);
   

   
    Task_list_head_insert(first_head,&heart, 10);
    Task_list_insert(first_head, NULL, -1);
    Task_list_insert(first_head, &lungs, 10);
    for (int i = 24; i > 0; i--){
       Task_list_insert(first_head,&heart,i % 10);
    }
    
    RTOS mainRTOS(RTOS_list_head);
    
    for(int i = 25; i > 0; i--){
        mainRTOS.startTask();
    }
    return 0;
}






