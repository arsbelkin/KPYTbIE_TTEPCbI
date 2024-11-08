mkdir build
cd build
mkdir debug
cd debug
set SRC_DIR=..\..\topological_sort
g++ %SRC_DIR%\tests\DataSetRegister.cpp %SRC_DIR%\tests\GraphReader.cpp %SRC_DIR%\tests\logger.cpp %SRC_DIR%\tests\tests_functions.cpp %SRC_DIR%\algorithms\algorithms.cpp %SRC_DIR%\algorithms\TaryanSort_by_Maslov.cpp -o topological_sort.exe --std=c++23
cd ..\..\
pause