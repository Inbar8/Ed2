
#ifndef ED2_MYEXCEPTION_H
#define ED2_MYEXCEPTION_H

class timeout_exception : public std::runtime_error {
 public:
  explicit timeout_exception(const char* msg) : std::runtime_error(msg){}
  explicit timeout_exception(std::string msg) : std::runtime_error(msg){}
};

class illegal_state_exception : public std::logic_error {
 public:
  explicit illegal_state_exception(std::string msg) : std::logic_error(msg) {}
};
#endif //ED2_MYEXCEPTION_H
