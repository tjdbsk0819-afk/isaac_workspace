from setuptools import find_packages
from setuptools import setup

setup(
    name='gaemi_interfaces',
    version='0.1.0',
    packages=find_packages(
        include=('gaemi_interfaces', 'gaemi_interfaces.*')),
)
