from setuptools import find_packages, setup

package_name = 'sound_play'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'rclpy', 'std_msgs'],
    zip_safe=True,
    maintainer='liqi',
    maintainer_email='liqi@boosterobotics.com',
    description='Speech output node',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'sound_play_node = sound_play.sound_play_node:main'
        ],
    },
    python_requires='>=3.6'
)