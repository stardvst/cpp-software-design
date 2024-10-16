#include "persistenceInterface.h"
#include <iostream>

class Database : public PersistenceInterface
{
public:
  Database() = default;
  Database(const Database &) = delete;
  Database &operator=(const Database &) = delete;
  Database(Database &&) = delete;
  Database &operator=(Database &) = delete;

private:
  bool do_read() const override
  {
    std::cout << "do_read\n";
    return true;
  }

  bool do_write() override
  {
    std::cout << "do_write\n";
    return true;
  }
};
