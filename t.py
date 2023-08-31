import timeit
import random
from c_fib import c_fib
from go_fib import go_fib


NUM = random.randint(30, 35)


def fib(n: int) -> int:
    if n == 0:
        return 0
    elif n == 1:
        return 1
    return fib(n-1) + fib(n-2)


if __name__ == '__main__':
    executions = 10

    print(f"Running benchmark for fibonacci sequence number : {NUM}, with {executions} executions")

    print(f"python: {timeit.timeit('fib(NUM)', number=executions, globals=locals())}")
    print(f"c-extension: {timeit.timeit('c_fib(NUM)', number=executions, globals=locals())}")
    print(f"go-extension: {timeit.timeit('go_fib(NUM)', number=executions, globals=locals())}")

    assert fib(NUM) == c_fib(NUM) == go_fib(NUM), f"Implementation mismatch... {fib(NUM)=}, {c_fib(NUM)=}, {go_fib(NUM)=}"


