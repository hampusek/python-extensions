import platform
import sys
from setuptools import setup
from setuptools import Extension


if sys.version_info >= (3,) and platform.python_implementation() == 'CPython':
    try:
        import wheel.bdist_wheel
    except ImportError:
        cmdclass = {}
    else:
        class bdist_wheel(wheel.bdist_wheel.bdist_wheel):
            def finalize_options(self):
                self.py_limited_api = 'cp3{}'.format(sys.version_info[1])
                super().finalize_options()

        cmdclass = {'bdist_wheel': bdist_wheel}


setup(
    name='go_fib',
    setup_requires=['setuptools-golang'],
    ext_modules=[
        Extension(
            'go_fib',
            ['go_fib.go'],
            py_limited_api=True,
            define_macros=[('Py_LIMITED_API', None)],
        ),
    ],
    build_golang={'root': 'github.com/hampusek/python-go-extension'},
    cmdclass=cmdclass,
)
