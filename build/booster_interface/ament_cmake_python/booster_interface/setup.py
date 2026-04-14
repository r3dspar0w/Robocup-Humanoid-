from setuptools import find_packages
from setuptools import setup

setup(
    name='booster_interface',
    version='0.0.0',
    packages=find_packages(
        include=('booster_interface', 'booster_interface.*')),
)
