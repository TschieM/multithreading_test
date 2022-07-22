#ifndef OS_INTERFACE_HPP
#define OS_INTERFACE_HPP

#include <boost/function.hpp>
#include <memory>

class OsInterface;
typedef std::shared_ptr<OsInterface> OsInterfacePtr;

class OsInterface {
 public:
  /* \brief Factory Function
   *
   */
  static OsInterfacePtr Create();

  /* \brief Map the function to os dependent thread functions
   *
   */
  virtual void SetTask(boost::function<void()> task_func,
                       uint16_t priority) = 0;

};  // Class OsInterface

#endif  // OS_INTERFACE_HPP