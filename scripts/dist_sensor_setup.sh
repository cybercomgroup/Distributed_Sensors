#!/bin/sh

ifdown wlan0

# build the interfaces file that will point to the file that holds our configuration
rm /etc/network/interfaces
touch /etc/network/interfaces
echo 'auto lo' >> /etc/network/interfaces
echo 'iface lo inet loopback' >> /etc/network/interfaces
echo 'iface eth0 inet dhcp' >> /etc/network/interfaces
echo 'allow-hotplug wlan0' >> /etc/network/interfaces
echo 'iface wlan0 inet manual' >> /etc/network/interfaces
echo 'wpa-roam /etc/wpa_supplicant/wpa_supplicant.conf' >> /etc/network/interfaces
echo 'iface default inet dhcp' >> /etc/network/interfaces

# build the supplicant file that holds our configuration
rm /etc/wpa_supplicant/wpa_supplicant.conf
touch /etc/wpa_supplicant/wpa_supplicant.conf
echo 'ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev' >> /etc/wpa_supplicant/wpa_supplicant.conf
echo 'update_config=1' >> /etc/wpa_supplicant/wpa_supplicant.conf
wpa_passphrase "PhoneBucket" "123456789M" >> /etc/wpa_supplicant/wpa_supplicant.conf

ifup wlan0

cd
git clone https://github.com/cybercomgroup/Distributed_Sensors.git
cd Distributed_Sensors
git checkout master
git pull
#use make here
echo 'make'

ifdown wlan0

#iw interface set type ibss
#ip link set interface up
#iw interface ibss join DSadhoc 2.447

#rm /etc/wpa_supplicant/wpa_supplicant.conf
#touch /etc/wpa_supplicant/wpa_supplicant.conf

#echo 'ctrl_interface=DIR=/run/wpa_supplicant GROUP=wheel' >> /etc/wpa_supplicant/wpa_supplicant.conf
# use 'ap_scan=2' on all devices connected to the network
# this is unnecessary if you only want the network to be created when no other networks are available
#echo 'ap_scan=2' >> /etc/wpa_supplicant/wpa_supplicant.conf

#echo 'network={ssid="DSadhoc" mode=1 frequency=2432 proto=RSN key_mgmt=WPA-PSK pairwise=CCMP group=CCMP psk="secret passphrase"}' >> /etc/wpa_supplicant/wpa_supplicant.conf

ifupwlan0
