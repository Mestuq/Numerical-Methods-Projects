#Maciej Pestka
#Damian Szopiński 185394

# Przykladowe uzycie tego skryptu
# wykres.py funkcja1.txt funkcja2.txt funkcja3.txt
# W tym przypadku narysowane beda 3 wykresy

import matplotlib.pyplot as plt
import numpy as np
import os,sys

os.system("pip install Matplotlib")

# USUNIECIE PIERWSZEGO ARGUMENTU (SCIEZKA SKRYPTU) [NIE BEDZIE NAM JUZ POTRZEBNY]
sys.argv.remove(sys.argv[0])

# ODCZYT Z PLIKU
x1Max=0 # NAJWIEKSZA DLUGOSC WYKRESU (PRZEDZIALOW OSI X)
iteration=0 # ITERACJA PONIZSZEJ PETLI
y1=[[]] # TABLICA WYKRESOW FUNKCJI
# WCZYTYWANIE WYKRESOW Z PLIKU
for function in sys.argv:
    y1.append([])
    location = str(function)
    file = open(location, 'r')
    count = 0
    for line in file:
        y1[iteration].append(float(line.strip()))
        count += 1
    if count > x1Max:
        x1Max=count
    file.close()
    iteration += 1
y1.pop()

# TWORZENIE OSI X
x1=[]
for x in range(x1Max):
    x1.append(x+1)

# WSTAWIANIE WYKRESOW
for y in y1:
    plt.plot(x1, y)

# TWORZENIE LEGENDY WYKRESU
legend1=[]
for legend in sys.argv:
    legend1.append(os.path.splitext(legend)[0])
plt.legend(legend1)

# OZNACZENIA OSI
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.title("Wykres funkcji")
plt.show()