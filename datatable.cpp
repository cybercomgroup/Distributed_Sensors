#include "helpfunc.h"

#define MAX_DOWNTIME 100



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
    string* getValidIP();
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


    while(pointer->next != 0)
    {
      pointer = pointer->next;
    }
    pointer->next = new Device;
    pointer = pointer->next;
    pointer->ip = ip;
    head->sensor_type = sensor;
    head->last_response = getEpoch();
    pointer->next = 0;
    size++;
}

string* DeviceTable::getValidIP(){
  Device *pointer = head;

  string* iplist = new string[size];
  int i = 0;

    while(pointer->next != 0)
    {
      cout<<"Epoch: "<<getEpoch()<<endl;
      cout<<"Last: "<<pointer->next->last_response<<endl;
      cout<<"Max: "<<MAX_DOWNTIME<<endl;
      cout<<(getEpoch() - pointer->next->last_response)<<endl;
      if((getEpoch() - pointer->next->last_response) > MAX_DOWNTIME) {
        pointer->next = pointer->next->next;
        delete pointer->next;
        size--;
      }
      else {
        iplist[i] = pointer->ip;
        pointer = pointer->next;
      }
      i++;
    }
  return iplist;
}

void DeviceTable::updateDeviceDowntime(string ip) {
  Device *pointer = head->next;

    while(pointer != 0)
    {
      if(pointer->ip.compare(ip) == 0){
          pointer->last_response = getEpoch();
          cout<<"Updating: "<<pointer->ip<<endl;
          return;
      }
      pointer = pointer->next;
    }

}

void DeviceTable::deleteDevice(string ip) {
  Device *pointer = head->next;
  Device *prev = head;
  if(pointer != 0){
    while(pointer != 0)
    {
      if(pointer->ip.compare(ip) == 0){
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
    Device *pointer = head->next;
    while(pointer != 0)
    {
      cout << "IP: " << pointer->ip << endl;
      pointer = pointer->next;
    }

}
