#define PY_SSIZE_T_CLEAN
#include <Python.h>

PyObject* hello(PyObject*, PyObject*);
PyObject* sum(PyObject*, PyObject*);
PyObject* go_fib(PyObject*, PyObject*);

int PyArgParseTuple_ll(PyObject* args, long* a, long* b) {
    return PyArg_ParseTuple(args, "ll", a, b);
}

int PyArgParseTuple_s(PyObject* args, const char** ptr, Py_ssize_t* size) {
    return PyArg_ParseTuple(args, "s", ptr, size);
}

int PyArgParseTuple_I(PyObject* args, unsigned int* num) {
    return PyArg_ParseTuple(args, "I", num);
}


static struct PyMethodDef methods[] = {
    {"hello", (PyCFunction)hello, METH_VARARGS},
    {"sum", (PyCFunction)sum, METH_VARARGS},
    {"go_fib", (PyCFunction)go_fib, METH_VARARGS},
    {NULL, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "go_fib",
    NULL,
    -1,
    methods
};

PyMODINIT_FUNC PyInit_go_fib(void) {
    return PyModule_Create(&module);
};
