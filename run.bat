mkdir build
cd build
mkdir debug
cd debug
set SRC_DIR=..\..\topological_sort
g++ %SRC_DIR%\tests\DataSetRegister.cpp %SRC_DIR%\tests\GraphReader.cpp %SRC_DIR%\tests\logger.cpp %SRC_DIR%\tests\tests_functions.cpp %SRC_DIR%\algorithms\algorithms.cpp %SRC_DIR%\algorithms\Demukrone_by_Balpeisov.cpp -o topological_sort.exe --std=c++23
topological_sort
cd ..\..\
pause