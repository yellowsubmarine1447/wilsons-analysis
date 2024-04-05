# takes a few seconds (like 10)

from scipy.optimize import curve_fit
from random import randint
from subprocess import check_output
from os import system
import matplotlib.pyplot as plt
LEFT = 100
RIGHT = 500

def cubic(x, a, b, c, d):
    y = a * x** 3 + b * x ** 2 + c * x + d
    return y

ydata = []
xdata = []
system("g++ random_tree_algo.cpp worst_case_expected.cpp")
for i in range(LEFT, RIGHT, 10):
    s = 0
    for _ in range(20):
        s += int(check_output(["./a.out", str(i)]))
    ydata.append(s // 10)
    xdata.append(i)

a, b, c, d =  curve_fit(cubic, xdata, ydata)[0]
plt.plot(range(LEFT, RIGHT), [cubic(x, a,b, c, d) for x in range(LEFT, RIGHT)])
plt.scatter(xdata, ydata)
plt.show()