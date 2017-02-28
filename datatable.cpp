#define MAX_DOWNTIME 10

using namespace std;

struct Device {
    string      ip;
    string      sensor_type;
    time_t      last_response;
    Device     *next;
};

class DeviceTable {

public:
    DeviceTable();
    void init();
    void add(string ip,string sensor);
    void getValidIP();
    void deleteDevice(string ip);
    void updateDeviceDowntime(string ip);
    void print();
};

DeviceTable::DeviceTable() {
    init();
}
Device *head;
int size;

void DeviceTable::init() {
    head = new Device;
    head->next = 0;
    head->ip = "";
    head->sensor_type = "";
    head->last_response = 0;
    size = 0;
}

void DeviceTable::add(string ip,string sensor) {
    Device *pointer = head;

    if(pointer != 0){
      while(pointer->next != 0)
      {
        pointer = pointer->next;
      }
    }
    pointer->next = new Device;
    pointer = pointer->next;
    pointer->ip = ip;
    head->sensor_type = sensor;
    head->last_response = getEpoch();
    pointer->next = 0;
    size++;
}

void DeviceTable::getValidIP(){
  Device *pointer = head;
  Device *prev;
  string iplist[size];
  int i = 0;
  if(pointer != 0){
    while(pointer->next != 0)
    {
      if((pointer->last_response - getEpoch()) > MAX_DOWNTIME) {
        //delete
        prev->next = pointer->next;
        delete pointer;
      }
      else {
        iplist[i] = pointer->ip;
      }
      i++;
      prev = pointer;
      pointer = pointer->next;
    }
  }
}

void DeviceTable::updateDeviceDowntime(string ip) {
  Device *pointer = head;
  if(pointer != 0){
    while(pointer->next != 0)
    {
      if(strcmp(pointer->ip,ip) == 0){
          pointer->last_response = getEpoch();
          return;
      }
      pointer = pointer->next;
    }
  }
}

void DeviceTable::deleteDevice(string ip) {
  Device *pointer = head;
  Device *prev;
  if(pointer != 0){
    while(pointer->next != 0)
    {
      if(strcmp(pointer->ip,ip) == 0){
          prev->next = pointer->next;
          delete pointer;
          size--;
          return;
      }
      prev = pointer;
      pointer = pointer->next;
    }
  }
}

void DeviceTable::print() {
    Device *pointer = head;
    while(pointer != 0)
    {
      cout << "IP: " << pointer->ip << endl;
      pointer = pointer->next;
    }

}
