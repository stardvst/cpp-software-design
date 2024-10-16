#include "persistenceInterface.h"
#include <cstdlib>

int main()
{
  PersistenceInterface *persistence = get_persistence_interface();
  persistence->read();
  persistence->write();
}
