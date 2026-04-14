from setuptools import find_packages
from setuptools import setup

setup(
    name='booster_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('booster_msgs', 'booster_msgs.*')),
)
