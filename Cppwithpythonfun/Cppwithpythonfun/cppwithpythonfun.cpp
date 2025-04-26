#include <iostream>
#include <stdlib.h>
#include "cppwithpythonfun.h"

int main(void)
{
	// 1. Python Path
	_putenv("PYTHONHOME=C:\\Python38"); // local 변수로 PYTHONHOME을 설정해준다.
	_putenv("PYTHONPATH=C:\\Python38\\include"); // local 변수로 PYTHONPATH를 설정해준다.

	// 2. Process Values
	PyObject *pName, *pModule, *pFunc, *pArg, *pResult;
	PyObject *pValue1, *pValue2, *pValue3;
	PyObject *ob1 = NULL, *ob2 = NULL, *ob3 = NULL;

	// 3. Python Initialize
	Py_Initialize();

	// 4. Function Set
	pName = PyUnicode_FromString("Cppwithpythonfun"); // Cppwithpythonfun.py를 PyObject로 생성
	pModule = PyImport_Import(pName); // 생성한 PyObject pName을 import
	pFunc = PyObject_GetAttrString(pModule, "start_process"); // 실행할 함수인 start_process을 PyObject에 전달 

	// 5. Arguments Values Set
	pValue1 = PyLong_FromLong(10);
	pValue2 = PyLong_FromLong(20);
	pValue3 = PyLong_FromLong(30);

	// 6. Arguments PyTupleSet
	pArg = PyTuple_New(3);
	PyTuple_SetItem(pArg, 0, pValue1);
	PyTuple_SetItem(pArg, 1, pValue2);
	PyTuple_SetItem(pArg, 2, pValue3);


    // 7. Arguments check, Print the tuple
	PyObject* pStr = PyObject_Str(pArg);
	if (pStr) {
		printf("Tuple: %s\n", PyUnicode_AsUTF8(pStr));
		Py_DECREF(pStr);
	}
	else {
		PyErr_Print();
	}

	// 9. Calling Function of Python
	pResult = PyObject_CallObject(pFunc, pArg); // pFunc에 매개변수를 전달해서 실행한다. 현재 매개변수가 NULL인 경우이다.
	//pResult = PyObject_CallObject(pFunc, NULL); // pFunc에 매개변수를 전달해서 실행한다. 현재 매개변수가 NULL인 경우이다.

	// 10. Return ResultsS
	if (pResult != NULL)	{
		PyArg_ParseTuple(pResult, "O|O|O:pResult", &ob1, &ob2, &ob3);
		printf("C++ Result return ob1: %f \n", PyFloat_AsDouble(ob1));
		printf("C++ Result return ob2: %f \n", PyFloat_AsDouble(ob2));
		printf("C++ Result return ob3: %f \n", PyFloat_AsDouble(ob3));
		Py_DECREF(pResult);
	}
	else	{
		PyErr_Print();
	}

	// 11. Process Finalize
	Py_Finalize();
	return 0;
}