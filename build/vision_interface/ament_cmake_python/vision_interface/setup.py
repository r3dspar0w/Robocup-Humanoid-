from setuptools import find_packages
from setuptools import setup

setup(
    name='vision_interface',
    version='1.0.0',
    packages=find_packages(
        include=('vision_interface', 'vision_interface.*')),
)
