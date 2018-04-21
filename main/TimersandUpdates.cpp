////
////  TimersandUpdates.cpp
////  main
////
////  Created by Michael Emperador on 4/20/18.
////  Copyright © 2018 Michael Emperador. All rights reserved.
////
//
//#include "TimersandUpdates.hpp"
//
//void timeInit() {
//    time0 = clock();
//    return;
//}
//
//double getElapsedTime() {
//    time1 = clock();
//    double seconds =  (time1 - time0)/CLOCKS_PER_SEC;
//    time0 = time1;
//    return seconds;
//}
//
//void timeFunction(node* head_ptr) {
//    if(first){
//        timeInit();
//        first = false;
//        return;
//    }
//    double timePassed = getElapsedTime();
//    for(node *cursor = head_ptr; cursor->link() != NULL; cursor = cursor->link()) {
//        if(timePassed/10000 < .001 &&  cursor->getPriority() > 4) {
//            cursor->setReady(1);
//        }
//    }
//    return;
//}

