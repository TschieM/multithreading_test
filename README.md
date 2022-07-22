# multithreading_test

# Descirption
 A mini test project to implement a os interface, which allows user to create thread tasks in an easier way.

# Demo
Two tasks should be created (func1 and func2), which should be running parallelly. 

# Design 
os_interface.hpp is an abstract class, which works as an general interface.  
linux_interface.hpp is a concrete class, which implements the os_interface and should be working on linux system.  
The LinuxInterface class has a vector which contains all the tasks created by the user.  
For each task, it has a callback function, which is given by the user and a thread which runs this callback function.

# How to Run
```
mkdir build
cd build
cmake ..
make

./bin/test
```
