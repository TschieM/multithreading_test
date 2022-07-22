#include "linux_interface.hpp"
#include <mutex>

// mutex for protecting thread data
std::mutex mtx;

LinuxInterface::LinuxInterface() {}

OsInterfacePtr OsInterface::Create() {
  return OsInterfacePtr(new LinuxInterface());
}

void LinuxInterface::SetTask(boost::function<void()> func, uint16_t priority) {
  // for eliminating the compilation warning
  (uint16_t) priority;
  std::shared_ptr<Task> new_task(new Task());
  new_task->SetTaskFunction(func);
  tasks_.push_back(new_task);
}

LinuxInterface::Task::Task() {
  task_active_ = false;
  // when a task is instantiated, a new thread will be created for running the call back function
  task_thread_ = std::thread(&LinuxInterface::Task::RunTaskThread, this);
}

void LinuxInterface::Task::SetTaskFunction(boost::function<void()> func) {
  // map the desired function to call back function, which will be running on a thread
  task_func_ = func;
  task_active_ = true;
}

void LinuxInterface::Task::RunTaskThread() {
  while (task_active_) {
    std::unique_lock<std::mutex> lock(mtx);
    task_func_();
    // 10 hz
    std::this_thread::sleep_for(std::chrono::microseconds(100000));
    lock.unlock();
  }
}