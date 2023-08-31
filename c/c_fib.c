#define PY_SSIZE_T_CLEAN
#include <Python.h>

static unsigned long long _fib(int n) {
    if (n == 0) {
        return 0;
    } else if (n ==1) {
        return 1;
    }
    return _fib(n - 2) + _fib(n - 1);
}

static PyObject* c_fib(PyObject* self, PyObject* args) {
    unsigned num;
    if (!PyArg_ParseTuple(args, "I", &num)) {
        return NULL;
    }

    unsigned long long n;
    n = _fib(num);

    PyObject* python_val = Py_BuildValue("K", n);

    return python_val;
}

static struct PyMethodDef methods[] = {
    {"c_fib", (PyCFunction)c_fib, METH_VARARGS},
    {NULL, NULL}
};


static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "c_fib",
    NULL,
    -1,
    methods
};

PyMODINIT_FUNC PyInit_c_fib(void) {
    return PyModule_Create(&module);
}
