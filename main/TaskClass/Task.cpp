
//using namespace std;
#include "Task.hpp"
#include "node.hpp"

Task::Task(FUNCTION func,const value_type& init_data)
: node(init_data) {
    state = func;
    Priority = init_data;
}

Task::~Task(){}

void Task::task() {
    state();
    Ready = 0;
    cout << Priority << endl;
    return;
}

int Task:: getPriority() {
    return Priority;
}

int Task:: getReady() {
    return Ready;
}

void Task:: setReady(int newReady) {
    Ready = newReady;
}
