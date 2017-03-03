set pspath=C:\"Program Files"\PuTTY\pscp.exe
set dipath=C:\Users\Tobbeh\Documents\DAT065\Distributed_Sensors
set piip=169.254.11.199
::169.254.11.199 = 17 på lina
:: fredriks dipath: C:\Chalmers\Distributed_Sensors\
:: fredriks pspath: C:\ProgramData\chocolatey\bin\pscp.exe

%pspath% -scp -pw distsensor %dipath%\main.cpp pi@%piip%:/home/pi/Distributed_Sensors/main.cpp

::%pspath% -scp -pw distsensor %dipath%\helpfunc.h pi@%piip%:/home/pi/Distributed_Sensors/helpfunc.h

::%pspath% -scp -pw distsensor %dipath%\helpfunc.cpp pi@%piip%:/home/pi/Distributed_Sensors/helpfunc.cpp

::%pspath% -scp -pw distsensor %dipath%\logger.h pi@%piip%:/home/pi/Distributed_Sensors/logger.h

::%pspath% -scp -pw distsensor %dipath%\logger.cpp pi@%piip%:/home/pi/Distributed_Sensors/logger.cpp

%pspath% -scp -pw distsensor %dipath%\datatable.cpp pi@%piip%:/home/pi/Distributed_Sensors/datatable.cpp

::%pspath% -scp -pw distsensor %dipath%\server.cpp pi@%piip%:/home/pi/Distributed_Sensors/server.cpp

::%pspath% -scp -pw distsensor %dipath%\server.h pi@%piip%:/home/pi/Distributed_Sensors/server.h

::%pspath% -scp -pw distsensor %dipath%\Makefile pi@%piip%:/home/pi/Distributed_Sensors/Makefile


::plink -v %piip% -l pi -pw distsensor -batch -m commands.txt
pause
transfer.bat