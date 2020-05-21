from task import *
import numpy as np
import pathlib

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
                planCyclicScheduler(t)
        except KeyboardInterrupt:
            print("Keyboard interrupt -> exit");
            quit()
        except FileNotFoundError:
            print("*****No such file: {}, try again*****".format(f))

def hyper(tasks):
        l = list(r.period for r in tasks)
        H = np.lcm.reduce(l)
        return H

def sec(tasks, H):
        maxCi = max(list(r.c for r in tasks))
        minTi = min(list(r.period for r in tasks))
        if(maxCi > minTi):
            print("ERROR: the maxCi is greater than minTi: {0} > {1}".format(maxCi, minTi))
            return -1
        candidatos = list(range(maxCi, minTi+1))
        c2 = []
        for n in candidatos:
            if(H%n == 0.0) :
                c2.append(n)
        print ("     * candidates: {}".format(c2))
        c3 = []
        for n in c2:
            print("     * trying with Ts={}".format(n))
            c = 0
            for task in tasks:
                f = 2*n - np.gcd(n, task.period)
                if((f <= task.period)):
                    c = c+1
                    print("     | OK: 2 * {0} - gcd({0},{1}) = {2} (<= {1})".format(n, task.period, f))
                else:
                    print("     | ER: 2 * {0} - gcd({0},{1}) = {2} (<= {1})".format(n, task.period, f))
            if(len(tasks) == c):
                c3.append(n) 
        return c3     

def planCyclicScheduler(tasks):
    print("Going to use the following task set:");
    for item in tasks:
        print(item)
    print("Calculating the utilization:")
    u = utilization(tasks)
    print("     * The utilization factor is {}".format(u))
    if(u > 1):
        print("The utilitzation is over 1, no way to plan")
        print("=====> The tasks can't planable in a cyclic scheduler.")
        return;    

    print("Calculating the hyperperiod:")
    H = hyper(tasks)
    print("     * H=lcm{}".format(list(r.period for r in tasks)))
    print("     * The hiperperiod is {}".format(H))

    print("Calculating the secondary frame:")
    SEC = sec(tasks, H)
    if(SEC == -1) :
        print("=====> The tasks can't be planed in a cyclic scheduler.");
        return;
    print("     * The secondary frame is {}".format(SEC))
    print("=====> All the sufficient conditions are completed.")

print("This is the script to evaluate tasks for a cyclic scheduler")
print("To exit, generate a keyboard interrupt Ctrl+C");

if __name__ == "__main__":
        main()
