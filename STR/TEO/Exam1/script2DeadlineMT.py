from task import *
import numpy as np
import math
import pathlib

def s(e):
    return e.priority

def highPriority(tasks, prev, t):
    ret = 0
    print("searching higher priority tasks...".format(prev))
    for task in tasks:
        if task.priority > t.priority:
            add = (math.ceil(prev/task.period) * task.c)
            print("Found task {} with high priority, adding {}".format(task.num, add))
            ret = ret + add
    return ret

def responseTime(tasks):
    tasks.sort(reverse=True, key=s)
    for item in tasks:
        print(item)
    ret = True;
    resultsDict = {}
    for task in tasks:
        n = 0
        i = task.num
        w = task.c
        wprev = -1
        print("")
        print("===========TASK_{}================".format(i))
        print("i = {} -> W{} = {} <= {}(Deadline{})".format(i,n,w,task.deadline,i))
        if w > task.deadline :
            print("ERROR: the W is greater than the deadline ")
            ret = ret and False;
        while wprev != w:
            wprev = w
            n = n +1
            w = task.c + highPriority(tasks, wprev, task)
            print("i = {} -> W{} = {} <= {}(Deadline{})".format(i,n,w,task.deadline,i))
            if w > task.deadline :
                print("ERROR: the W is greater than the deadline ")
                ret = ret and False;
        resultsDict ["task" + str(task.num)] = w
    print("")
    print("")
    print("===========RESULTS================".format(i))   
    for i in resultsDict:
        print(str(i) + "-->R =" + str(resultsDict[i]))
    if ret : print("For all, W <= Di")
    else : print("In some cases, the W > Di"); 
    return ret;
        
def calcPriority(tasks):
    for task in tasks:
        task.priority = (1 / task.deadline)*10
        print("task {} has priorty {}".format(task.num, task.priority))

def planDeadlineMonotonic(tasks):
    print("Assign higher priorities to shorter deadlines...")
    calcPriority(tasks)
    print("\n")
    print("Going to use the following task set:");
    deadlinesEqualPeriod = True
    for item in tasks:
        deadlinesEqualPeriod = deadlinesEqualPeriod and item.period == item.deadline 
        print(item)
    if deadlinesEqualPeriod :
        print("\n     * The deadlines are equal to the periods.\n")
    else:
        print("\n     * The deadlines aren't equal to the periods.\n")
        
    print("Calculating the utilization:")
    U = utilization(tasks)
    print("     * The utilization factor is {}".format(U))
    if(U > 1):
        print("\nThe utilitzation is over 1, no way to plan")
        print("=====> tasks cannot be scheduled")
        return;
    
    print("Calcuating U <= n(2^1/n -1), with n = {}".format(len(tasks)))
    x = 5 * (pow(2, 1/len(tasks)) - 1)
    print("     *{} <= {}".format(U, x))
    if(U > x):
        print("\n=====> Tasks cannot be scheduled")
        return;
    elif deadlinesEqualPeriod :
        print("\n=====> Since Di == Ti the U <= n(2^1/n-1) is a sufficient condition")
        print("=====> Tasks can be scheduled")
        return;
    print("Since Di != Ti, a Response time analysis is mandatory:");
    
    r = responseTime(tasks)
    if r:
        print("\n     *OK: response time")
        print("=====> tasks can be scheduled")
    else:
        print("\n     *ER: response time")
        print("=====> tasks cannot be scheduled")
        

def main():                
    print("This is the script to evaluate tasks for a deadline monotonic scheduler")
    print("To exit, generate a keyboard interrupt, (Ctrl+C)");
    print("For display the help for format, type *file")
    print("The current path {}".format(pathlib.Path().absolute()))  
    while True:
        try:
            f = input("Enter the tasks file: ")
            if f == "*file": helpFileFormat()
            else: 
                t = readTasksFromFile(f)
                planDeadlineMonotonic(t)
        except KeyboardInterrupt:
            print("Keyboard interrupt -> exit");
            quit()
        except FileNotFoundError:
            print("*****No such file: {}, try again*****".format(f))


if __name__ == "__main__": main()
