# Python extensions

This is a simple demo for how extensions in other programing languages can be made for python.

For more information have a look at the [Python C api](https://docs.python.org/3.8/c-api/index.html).


Note that creating memory leaks is really easy when interfacing with c.

The programing languages you want to extend python with needs to be able to generate a shared object during compilation.

NOTE: go extensions might be difficult to get working on windows due to different c-compilers used for python and golang in windows.


## install
install as normal with:
```bash
pip install -r requirement.txt
```

Note that editable installs will not recompile the c code so any changes to the c source code will require you to reinstall the package.

## abi3 for better compatibility
The setup.py will create a abi3 compatible extension which should make distrubution between
operating systems and python version less painful.

## Benchmarking
I have included a very simple microbench script that can be used to compare
the implementations with a pure python implementation of the same function.

Run the benchmark with:
```bash
python t.py
```

