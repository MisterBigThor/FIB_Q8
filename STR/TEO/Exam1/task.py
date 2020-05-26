    
class taskRT:
    """
    A definition of a task. The constructor needs a reference number,
    a computing time and a period/deadlien
    """
    def __init__(self, num, time, per, d=-1):
        self.num = num
        self.c = time
        self.period = per
        if d==-1 : d = per
        self.deadline = d
        self.priority = -1
    def __str__(self):
        return "task {} with computing time {}, period {}, deadline {} and priority {}".format(self.num, self.c, self.period, self.deadline, self.priority)
    
def readTasksFromFile(file):
    """
    Read and generate a list of tasks.
    """
    print("\nReading from file {} ...".format(file))
    ret = [];
    for l in open(file, 'r').readlines():    
        if l[0] == '#': continue        
        info = l.split(' ')
        if len(info) == 3: newTask = taskRT(int(info[0]), int(info[1]), int(info[2]))
        else : newTask = taskRT(int(info[0]), int(info[1]), int(info[2]), int(info[3]))
        ret.append(newTask)
        print("Found:", end=" ")
        print(newTask)
    print("\nDone reading from file {} ...\n".format(file))
    return ret;

def helpFileFormat():
    print("************************************************************")
    print("| One task in each line")
    print("| A line with a # at the begginig will be ignored (use to commnent)")
    print("| In each line, with a space between numbers the correct format is:")
    print("| taskID <space> Computing time <space> Period <space> deadline <endline>")
    print("| If the deadline is not found, then the deadline will be equal to the period")
    print("************************************************************")


def printTasks(tasks):
    for t in tasks:
        print(t)
        
def utilization(tasks):
    ret = 0.0
    for task in tasks:
        ret += (task.c/task.period)
    return ret

def start():
    f = input("Enter the tasks file: ")
    t = readTasksFromFile(f)
