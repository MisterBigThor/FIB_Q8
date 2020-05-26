from task import *
import numpy as np
import math
import pathlib

def hyper(tasks):
    l = list(r.period for r in tasks)
    H = np.lcm.reduce(l)
    return H
def l(tasks, U):
    ret = 0
    i = 1
    for t in tasks:
        ui = t.c / t.period
        ret += (t.period-t.deadline) * ui
        print("i = {} --> ({}-{}) * {}".format(i, t.period, t.deadline , ui))
        i += 1      
    ret = ret / (1 - U)
    return ret

def RealDeadlines(tasks, lim):
    ret = set()
    for t in tasks:
        act = t.deadline
        inter = []
        while act < lim:
            inter.append(act)
            act += t.period
        print(str(t.num) + " :" + str(inter))
        ret.update(inter)
    return ret

def calcG(tasks, D):
    ret = True
    for d in D:
        i = 0
        for t in tasks:
            fl = math.floor((d + t.period -t.deadline)/t.period)
            i += fl*t.c
        print("G({})= {} <= {}".format(d, i, d))
        if i > d : ret and False
        
    return ret
    
def earliestDeadline(tasks):
    print("Using the following task set:");
    deadlinesEqualPeriod = True
    for item in tasks:
        deadlinesEqualPeriod = deadlinesEqualPeriod and item.period == item.deadline 
        print(item)
    if deadlinesEqualPeriod :
        print("\n     * The deadlines are equal to the periods.\n")
    else:
        print("\n     * The deadlines aren't equal to the periods.\n")
    print("Checking the utilization: ");
    U = utilization(tasks)
    print("    * The utilization factor is {}.".format(U))
    if U > 1 :
        print("The utilization factor is over 1, no way to plan")
        print("    =====> The task cannot be scheduled")
        return;
    elif deadlinesEqualPeriod:
        print("\n   =====> Since Di == Ti the utilization factor is a sufficient condition")
        print("     =====> The tasks can be scheduled")
        return;
    print("Cheking the H and L*:")
    H = hyper(tasks)
    L = l(tasks, U)
    print("    * The results are H = {}, L = {}".format(H, L))
    auxMin = min(H, L)
    print("    * using {}, the real deadline are:".format(auxMin))
    D = RealDeadlines(tasks, auxMin)
    D = sorted(D)
    print("    * D = " + str(D))
    print("Check if all the tasks can achieve the deadlines")
    G = calcG(tasks, D)
    if not G: print("    =====> At least one deadline may be lost")
    else : print("    =====> The task can be schedulede in a EDF")
    
def main():                
    print("This is the script to evaluate tasks for a earliest deadline first scheduler")
    print("To exit, generate a keyboard interrupt Ctrl+C")
    print("For display the help for format, type *file")
    print("Current path {}".format(pathlib.Path().absolute()))
    while True:
        try:         
            f = input("Enter the tasks file: ")
            if f == "*file": helpFileFormat()
            else: 
                t = readTasksFromFile(f)
                earliestDeadline(t)
        except KeyboardInterrupt:
            print("Keyboard interrupt -> exit");
            quit()
        except FileNotFoundError:
            print("*****No such file: {}, try again*****".format(f))


if __name__ == "__main__":
    main()
