#include <memory>
#include <vector>
#include "mallardDuck.h"
#include "wildTurkey.h"
#include "turkeyAdapter.h"

using DuckChoir = std::vector<std::unique_ptr<Duck>>;

void giveConcert(const DuckChoir &duckChoir)
{
  for (const auto &duck : duckChoir)
    duck->quack();
}

int main()
{
  DuckChoir duckChoir;

  duckChoir.push_back(std::make_unique<MallardDuck>());
  duckChoir.push_back(std::make_unique<MallardDuck>());
  duckChoir.push_back(std::make_unique<MallardDuck>());

  auto turkey = std::make_unique<WildTurkey>();
  auto turkeyInDisguise = std::make_unique<TurkeyAdapter>(std::move(turkey));
  duckChoir.push_back(std::move(turkeyInDisguise));

  giveConcert(duckChoir);
}
