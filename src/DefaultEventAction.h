// -----------------------------------------------------------------------------
//  G4Basic | DefaultEventAction.h
//
//  User event action class.
// -----------------------------------------------------------------------------

#ifndef DEFAULT_EVENT_ACTION_H
#define DEFAULT_EVENT_ACTION_H

#include <G4UserEventAction.hh>

class G4Event;


class DefaultEventAction: public G4UserEventAction
{
public:
  DefaultEventAction();
  virtual ~DefaultEventAction();
  virtual void BeginOfEventAction(const G4Event*);
  virtual void EndOfEventAction(const G4Event*);
};

inline DefaultEventAction::DefaultEventAction() {}
inline DefaultEventAction::~DefaultEventAction() {}

#endif
