set pspath = C:\Program Files\PuTTY
set dipath = C:\Tobbe\Skola\Programming\DAT065\Distributed_Sensors
set piip = 169.254.11.199
::169.254.11.199 = 17 på lina
:: fredriks dipath: C:\Chalmers\Distributed_Sensors\
:: fredriks pspath: C:\ProgramData\chocolatey\bin\pscp.exe

C:\"Program Files"\PuTTY\pscp.exe -scp -pw distsensor C:\Tobbe\Skola\Programming\DAT065\Distributed_Sensors\main.cpp pi@169.254.11.199:/home/pi/Distributed_Sensors/main.cpp

C:\"Program Files"\PuTTY\pscp.exe -scp -pw distsensor C:\Tobbe\Skola\Programming\DAT065\Distributed_Sensors\client.cpp pi@169.254.11.199:/home/pi/Distributed_Sensors/client.cpp

C:\"Program Files"\PuTTY\pscp.exe -scp -pw distsensor C:\Tobbe\Skola\Programming\DAT065\Distributed_Sensors\client.h pi@169.254.11.199:/home/pi/Distributed_Sensors/client.h

C:\"Program Files"\PuTTY\pscp.exe -scp -pw distsensor C:\Tobbe\Skola\Programming\DAT065\Distributed_Sensors\server.cpp pi@169.254.11.199:/home/pi/Distributed_Sensors/server.cpp

C:\"Program Files"\PuTTY\pscp.exe -scp -pw distsensor C:\Tobbe\Skola\Programming\DAT065\Distributed_Sensors\server.h pi@169.254.11.199:/home/pi/Distributed_Sensors/server.h

C:\"Program Files"\PuTTY\pscp.exe -scp -pw distsensor C:\Tobbe\Skola\Programming\DAT065\Distributed_Sensors\Makefile pi@169.254.11.199:/home/pi/Distributed_Sensors/Makefile


plink -v 169.254.11.199 -l pi -pw distsensor -batch -m commands.txt
pause
transfer.bat