import numpy as np
import pickle 
import sys
import inspect

import Orange
#from Orange.data import Table

print(inspect.getfile(Orange))

def start_process():
    print("Hello, world!")
    print(sys.path)
    print(sys.version)
    a = np.array([1, 2, 3])
    print(a)



start_process();
