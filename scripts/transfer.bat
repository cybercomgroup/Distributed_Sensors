C:\ProgramData\chocolatey\bin\pscp.exe -scp -pw distsensor C:\Chalmers\Distributed_Sensors\main.cpp pi@192.168.0.11:/home/pi/Distributed_Sensors/main.cpp

C:\ProgramData\chocolatey\bin\pscp.exe -scp -pw distsensor C:\Chalmers\Distributed_Sensors\client.cpp pi@192.168.0.11:/home/pi/Distributed_Sensors/client.cpp

C:\ProgramData\chocolatey\bin\pscp.exe -scp -pw distsensor C:\Chalmers\Distributed_Sensors\client.h pi@192.168.0.11:/home/pi/Distributed_Sensors/client.h

C:\ProgramData\chocolatey\bin\pscp.exe -scp -pw distsensor C:\Chalmers\Distributed_Sensors\Makefile pi@192.168.0.11:/home/pi/Distributed_Sensors/Makefile


plink -v 192.168.0.11 -l pi -pw distsensor -batch -m commands.txt
pause
transfer.bat