:: Ten skrypt dałem dodatkowo, by łatwiej mi się kompilowało program

@echo off 
echo "Starting compile..."
g++ -std=c++20 func.hpp
g++ -std=c++20 main.cpp
echo "Compile has completed"
a.exe
pause