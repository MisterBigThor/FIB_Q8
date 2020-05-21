import numpy as np
from task import taskRT

#Definition a set of tasks & methods
class cyclicScheduler:
    """
    Functions to perform a analisis for a scheduling. 
    Contains a group of tasks.
    """
    def __init__(self, f):
        self.t = []
        self.H = 0
        self.secondary = []
        for l in open(f, 'r').readlines():    
            if l[0] == '#': continue        
            info = l.split(' ')
            newTask = taskRT(int(info[0]), int(info[1]), int(info[2]))
            self.t.append(newTask)
            print("Found:", end=" ")
            print(newTask)

    def __str__(self):
        for l in self.t:
            print(l)
        return "This is the contained in the structure"

    def utilization(self):
        ret = 0.0
        for task in self.t:
            ret += (task.c/task.period)
        return ret

    def hyper(self):
        l = list(r.period for r in self.t)
        self.H = np.lcm.reduce(l)
        return self.H

    def sec(self):
        maxCi = max(list(r.c for r in self.t))
        minTi = min(list(r.period for r in self.t))
        if(maxCi > minTi):
            print("ERROR: the maxCi is greater than minTi: {0} > {1}".format(maxCi, minTi))
            return -1
        candidatos = list(range(maxCi, minTi+1))
        c2 = []
        for n in candidatos:
            if(self.H%n == 0.0) :
                c2.append(n)
        print ("     * candidates: {}".format(c2))
        c3 = []
        for n in c2:
            print("     * trying with Ts={}".format(n))
            c = 0
            for task in self.t:
                f = 2*n - np.gcd(n, task.period)
                if((f <= task.period)):
                    c = c+1
                    print("     | ok: 2 * {0} - gcd({0},{1}) = {2} (<= {1})".format(n, task.period, f))
                else:
                    print("     | no: 2 * {0} - gcd({0},{1}) = {2} (<= {1})".format(n, task.period, f))
            if(len(self.t) == c):
                c3.append(n) 
        self.secondary = c3
        return c3     

    def appendTask(self, num, comp, per):
        newTask = taskRT(int(num), int(comp), int(per))
        self.t.append(newTask)
    

def calcCyclicScheduler(c):
    print("Calculating the utilization:")
    u = c.utilization()
    print("     * The utilization factor is {}".format(u))
    if(u > 1):
        print("The utilitzation is over 1, no way to plan")
        print("=====> The tasks can't planable in a cyclic scheduler.")
        return;    

    print("Calculating the hyperperiod:")
    c.H = c.hyper()
    print("     * H=lcm{}".format(list(r.period for r in c.t)))
    print("     * The hiperperiod is {}".format(c.H))

    print("Calculating the secondary frame:")
    c.secondary = c.sec()
    if(c.secondary == -1) :
        print("=====> The tasks can't be planed in a cyclic scheduler.");
        return;
    print("     * The secondary frame is {}".format(c.secondary))
    print("=====> All the sufficient conditions are completed.")

c = cyclicScheduler('tasks2.txt')
calcCyclicScheduler(c)
