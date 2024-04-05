# takes like a minute or two with the provided settings

from scipy.optimize import curve_fit
from random import randint
from subprocess import check_output
from os import system
import matplotlib.pyplot as plt
from sys import argv

LEFT = 100
RIGHT = 600
SAMPLING_DIST = 20

def cubic(x, a, b, c, d):
    y = a * x** 3 + b * x**2 + c*x + d
    return y

ydata = []
xdata = []
if len(argv) < 2:
    print("please provide .cpp file that generates random graph")
    exit(1)

system(f"g++ call_count.cpp {argv[1]}")
for i in range(LEFT, RIGHT, SAMPLING_DIST):
    s = 0
    for _ in range(20):
        s += int(check_output(["./a.out", str(i)]))
    ydata.append(s // 10)
    xdata.append(i)

a, b, c, d =  curve_fit(cubic, xdata, ydata)[0]
plt.plot(range(LEFT, RIGHT), [cubic(x, a,b, c, d) for x in range(LEFT, RIGHT)])
plt.scatter(xdata, ydata)
plt.show()