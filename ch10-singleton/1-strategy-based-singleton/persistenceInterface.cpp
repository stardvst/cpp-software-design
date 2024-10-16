#include "database.h"

PersistenceInterface *instance = nullptr;

PersistenceInterface *get_persistence_interface()
{
  static bool init = []()
  {
    if (!instance)
    {
      static Database db;
      instance = &db;
    }
    return true;
  }();
  return instance;
}

void get_persistence_interface(PersistenceInterface *persistence)
{
  instance = persistence;
}
