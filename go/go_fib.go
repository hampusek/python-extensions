package main

// #include <Python.h>
// int PyArgParseTuple_ll(PyObject* args, long* a, long* b);
// int PyArgParseTuple_s(PyObject* args, const char** ptr, Py_ssize_t* size);
// int PyArgParseTuple_I(PyObject* args, unsigned int* num);
import "C"
import "unsafe"

//export hello
func hello(self *C.PyObject, args *C.PyObject) *C.PyObject {
    var s *C.char
    var size C.Py_ssize_t
    if C.PyArgParseTuple_s(args, &s, &size) == 0 {
        return nil
    }

    ret := "hello hello " + C.GoString(s)
    cstr := C.CString(ret)
    ret_u := C.PyUnicode_FromString(cstr)
    C.free(unsafe.Pointer(cstr))
    return ret_u
}

//export sum
func sum(self *C.PyObject, args *C.PyObject) *C.PyObject {
    var a C.long
    var b C.long
    if C.PyArgParseTuple_ll(args, &a, &b) == 0 {
        return nil
    }

    ret := a + b
    return C.PyLong_FromLong(ret)
}

func _fib(num uint) uint64 {
    if num == 0 {
        return 0
    } else if num == 1 {
        return 1
    }
    return _fib(num-1) + _fib(num-2)
}

//export go_fib
func go_fib(self *C.PyObject, args *C.PyObject) *C.PyObject {
    var num C.uint

    if C.PyArgParseTuple_I(args, &num) == 0 {
        return nil
    }

    ret := C.ulonglong(_fib(uint(num)))
    return C.PyLong_FromUnsignedLongLong(ret)
}

func main() {}
