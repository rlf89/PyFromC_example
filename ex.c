// calling python functions from C code
// 

#include <Python.h>

int main()
{
    PyObject *thunarx;

    // Initialize the Python Interpreter
    Py_Initialize();

    PyRun_SimpleString("import gi; gi.require_version('Thunarx', '3.0')");

    thunarx = PyImport_ImportModule("gi.repository.Thunarx");
    if (!thunarx) {
        PyErr_Print();
        return -1;
    }

    PyRun_SimpleString("print('hello from python')");

    // Finish the Python Interpreter
    Py_Finalize();

    // REPEATING..

    Py_Initialize(); // It is broken

    PyRun_SimpleString("import gi; gi.require_version('Thunarx', '3.0')");

    //PyRun_InteractiveLoop(stdin, "<stdin>");

    thunarx = PyImport_ImportModule("gi.repository.Thunarx"); // Crashes here
    if (!thunarx) {
        PyErr_Print();
        return -1;
    }

    Py_Finalize();

    return 0;
}