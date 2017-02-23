
@netsh wlan set profileparameter DSadhoc connectiontype=ibss connectionmode=manual
@netsh wlan connect DSadhoc

::Change "WiFi" to fit your wireless network adapter name, change ip to fit your needs
@netsh int ip set address "WiFi" static 192.168.0.1 255.255.255.0

@echo press anything to disconnect from AdHoc
@pause

@netsh int ip set address "WiFi" dhcp
@pause
@netsh wlan disconnect
