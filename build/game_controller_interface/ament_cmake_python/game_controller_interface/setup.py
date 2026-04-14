from setuptools import find_packages
from setuptools import setup

setup(
    name='game_controller_interface',
    version='1.0.0',
    packages=find_packages(
        include=('game_controller_interface', 'game_controller_interface.*')),
)
