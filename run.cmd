cmake -B ./bin/ -G "MinGW Makefiles"
cmake --build ./bin/
cd bin 
ConvertingTable.exe
cd ..