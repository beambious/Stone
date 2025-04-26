import numpy as np
import pickle 
import sys
import inspect

print('---- 1. Orange import check ---- ')
import Orange
from Orange.data import Table

print(inspect.getfile(pickle))
print('\n')

with open('D:\\Model.pkcls', 'rb') as model:
	lr = pickle.load(model)

print('---- 2. DataBase Import check ---- ')
data1 = Table('D:\\Input.csv')
print('\n')

def start_process(value1,value2, value3):
    print('---- 3. Process communication check ---- ')
    print("Hello, world!")
    #print(sys.path)
    #print(sys.version)
    print('\n')

    print('---- 4. Data Transfer(C++ -> Python)  check ---- ')
    print(value1, value2, value3)
    print('\n')

    print('---- 5. Data input read check ---- ')
    print(data1)
    print('\n')

    print('---- 6. Python Result and Model operation check ---- ')
    result = lr([6, 60, 600, 6000, 60000, 600000])
    print(result)
    print('\n')

    print('---- 7. Result return(Python -> C++) check ---- ')
    return result, 2, 3
    



