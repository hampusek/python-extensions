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

Here are some results from running the benchmark on my machine**:

| fibonacci sequence number | executions | python [s] | c-extension [s] | go-extension [s] |
| --- | --- | ---   | ---  | ---  |
| 32  | 10  | 7.24  | 0.07 | 0.11 |
| 33  | 10  | 11.78 | 0.11 | 0.18 |
| 35  | 10  | 30.89 | 0.29 | 0.47 |



**my machine:

Architecture:                    x86_64
CPU op-mode(s):                  32-bit, 64-bit
Byte Order:                      Little Endian
Address sizes:                   39 bits physical, 48 bits virtual
CPU(s):                          8
On-line CPU(s) list:             0-7
Thread(s) per core:              2
Core(s) per socket:              4
Socket(s):                       1
NUMA node(s):                    1
Vendor ID:                       GenuineIntel
CPU family:                      6
Model:                           142
Model name:                      Intel(R) Core(TM) i5-8350U CPU @ 1.70GHz
Stepping:                        10
CPU MHz:                         800.029
CPU max MHz:                     3600,0000
CPU min MHz:                     400,0000
BogoMIPS:                        3799.90
Virtualization:                  VT-x
L1d cache:                       128 KiB
L1i cache:                       128 KiB
L2 cache:                        1 MiB
L3 cache:                        6 MiB
NUMA node0 CPU(s):               0-7




