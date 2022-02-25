// -----------------------------------------------------------------------------
//  G4Basic | CountEventAction.h
//
//  User event action class.
// -----------------------------------------------------------------------------

#ifndef COUNT_EVENT_ACTION_H
#define COUNT_EVENT_ACTION_H

#include <G4UserEventAction.hh>

class G4Event;


class CountEventAction: public G4UserEventAction
{
public:
  CountEventAction();
  virtual ~CountEventAction();
  virtual void BeginOfEventAction(const G4Event*);
  virtual void EndOfEventAction(const G4Event*);
};

inline CountEventAction::CountEventAction() {}
inline CountEventAction::~CountEventAction() {}

#endif
