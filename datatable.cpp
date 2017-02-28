
using namespace std;

struct Device {
    string      ip;
    string      sensor_type;
    std::time_t last_response;
    Device     *next;
};

class DeviceTable {

public:
    DeviceTable();
    void init();
    void add(string s);
    void print();
};

DeviceTable::DeviceTable() {
    init();
}
Device *head;

void DeviceTable::init() {
    head = new Device;
    head->next = 0;
    head->ip = "";
    head->sensor_type = "";
    head->last_response = 0;
}

void DeviceTable::add(string s) {
    Device *pointer = head;

    if(pointer != 0){
      while(pointer->next != 0)
      {
        pointer = pointer->next;
      }
    }
    pointer->next = new Device;
    pointer = pointer->next;
    pointer->ip = s;
    head->sensor_type = "";
    head->last_response = 0;
    pointer->next = 0;
}

void DeviceTable::print() {
    Device *pointer = head;
    if(pointer != 0){
      while(pointer != 0)
      {
        cout << "IP: " << pointer->ip << endl;
        pointer = pointer->next;
      }
    }
}
