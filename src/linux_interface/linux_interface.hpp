#ifndef LINUX_INTERFACE_HPP
#define LINUX_INTERFACE_HPP

#include <memory>
#include <thread>
#include <vector>
#include "os_interface.hpp"

/** \brief A concrete class of OSInterface which runs on Linux Machine
 */
class LinuxInterface final: public OsInterface {
 public:
  LinuxInterface();
  ~LinuxInterface() {}

  virtual void SetTask(boost::function<void()> func,
                       uint16_t priority) override;

 private:
  /**
   * \brief Class that stores concrete function which will run on a thread  
   */
  class Task {
   public:
    Task();
    ~Task() { task_thread_.join(); };
    void SetTaskFunction(boost::function<void()> func);
    void RunTaskThread();

   private:
    boost::function<void()> task_func_;
    std::thread task_thread_;
    bool task_active_;
  };

  std::vector<std::shared_ptr<Task>> tasks_;
};

#endif  // LINUX_INTERFACE_HPP