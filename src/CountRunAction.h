// -----------------------------------------------------------------------------
//  G4Basic | CountRunAction.h
//
//  User run action class.
// -----------------------------------------------------------------------------

#ifndef COUNT_RUN_ACTION_H
#define COUNT_RUN_ACTION_H

#include <vector>

#include <G4UserRunAction.hh>

class G4Run;


class CountRunAction: public G4UserRunAction
{
public:
  CountRunAction();
  virtual ~CountRunAction();
  virtual void BeginOfRunAction(const G4Run*);
  virtual void EndOfRunAction(const G4Run*);

  void IncrementACounter(G4int);
  void ResetCounters();
  void DisplayCounters();
  void DisplaySortedCounters();

private: 
  void RegisterNewSensor(G4int);
  G4bool isTaken(G4int);
  G4int GetIDIterator(G4int);
  G4int minimum(std::vector<G4int>);

  std::vector<G4int> IDs;
  std::vector<G4int> counters;
};

#endif
