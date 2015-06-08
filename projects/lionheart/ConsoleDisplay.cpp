#include "ConsoleDisplay.hpp"
#include <iostream>

namespace
{
  void displayHeader(int length)
  {
    for(int i=0;i<=length;++i)
      std::cout << "-";
    std::cout << std::endl;
  }
}
void lionheart::ConsoleDisplay::show(lionheart::SituationReport const &report,
                                     Blazon const &,
                                     Blazon const &)
{
  if(report.things.empty())return;
  displayHeader(report.things[0].size());
  for(auto&& row:report.things)
  {
    std::cout << '|' ;
    for(auto&& thing:row)
    {
      switch(thing.type)
      {
        case SituationReport::ROCK: std::cout << 'X';break;
        case SituationReport::SPACE: std::cout << ' ';break;
        case SituationReport::ALLY:
                                     switch(thing.unit)
                                     {
                                       case CROWN:std::cout <<'*';break;
                                       case KNIGHT:std::cout <<'k';break;
                                       case ARCHER:std::cout <<'a';break;
                                       case INFANTRY:std::cout <<'i';break;
                                       default:std::cout << '.';
                                     }
                    break;
        case SituationReport::ENEMY:
                                     switch(thing.unit)
                                     {
                                       case CROWN:std::cout <<'@';break;
                                       case KNIGHT:std::cout <<'K';break;
                                       case ARCHER:std::cout <<'A';break;
                                       case INFANTRY:std::cout <<'I';break;
                                       default:std::cout << '.';
                                     }
                    break;

      }
    }
    std::cout << '|' << std::endl;
  }
  displayHeader(report.things[0].size());
}
