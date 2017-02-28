
using namespace std;

struct Devices {
    string      ip;
    string      sensor_type;
    std::time_t last_response;
    Devices     *next;
};

Devices init() {
    Devices *head;

    head = new Devices;
    head->next = 0;
    head->ip = NULL;
    head->sensor_type = NULL;
    head->last_response = NULL;

    return head;
}

void add(Devices *head, Devices next) {
    Devices *pointer = head;

    if(pointer != 0){
      while(pointer->next != 0)
      {
        pointer = pointer->next;
      }
    }
    pointer->next = next;
}

void print(Devices *head) {
    Devices *pointer = head;
    if(pointer != 0){
      while(pointer->next != 0)
      {
        cout << "IP: " << pointer->ip << endl;
        pointer = pointer->next;
      }
    }
}
