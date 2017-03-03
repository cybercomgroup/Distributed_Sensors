#include "helpfunc.h"

using namespace std;

struct Device {
    string      ip;
    string      sensor_type;
    time_t      last_response;
    Device     *next;
};

class DeviceTable {

public:
    DeviceTable(int dwnT);
    void init(int dwnT);
    void add(string ip,string sensor);
    void addOrUpdateDowntime(string ip,string sensor);
    string* getValidIP();
    int MAX_DOWNTIME;
    void deleteDevice(string ip);
    void updateDeviceDowntime(string ip);
    void print();
};

DeviceTable::DeviceTable(int dwnT) {
    init(dwnT);
}
Device *head;
int size;

void DeviceTable::init(int dwnT) {
    head = new Device;
    head->next = 0;
    head->ip = "";
    head->sensor_type = "";
    head->last_response = 0;
    size = 0;
    MAX_DOWNTIME = dwnT;
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
    pointer->sensor_type = sensor;
    pointer->last_response = getEpoch();
    pointer->next = 0;
    size++;
}

void DeviceTable::addOrUpdateDowntime(string ip,string sensor) {
    Device *pointer = head;


    while(pointer->next != 0)
    {
      if(pointer->ip.compare(ip) == 0)
      {
          pointer->last_response = getEpoch();
          return;
      }
      pointer = pointer->next;
    }
    pointer->next = new Device;
    pointer = pointer->next;
    pointer->ip = ip;
    pointer->sensor_type = sensor;
    pointer->last_response = getEpoch();
    pointer->next = 0;
    size++;
}

string* DeviceTable::getValidIP(){
  Device *pointer = head;
  Device *tempP = 0;

  string* iplist = new string[size+1];
  int i = 1;

    while(pointer->next != 0)
    {
      if((getEpoch() - pointer->next->last_response) > MAX_DOWNTIME) {
        tempP = pointer->next->next;
        delete pointer->next;
        pointer->next = tempP;
        size--;
      }
      else {
        iplist[i] = pointer->next->ip;
        i++;
        pointer = pointer->next;
      }
    }

  iplist[0] = to_string(i);
  return iplist;
}

void DeviceTable::updateDeviceDowntime(string ip) {
  Device *pointer = head->next;

    while(pointer != 0)
    {
      if(pointer->ip.compare(ip) == 0){
          pointer->last_response = getEpoch();
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
      cout << "IP: " << pointer->ip << "\t| Sensor: " << pointer->sensor_type << endl;
      pointer = pointer->next;
    }

}