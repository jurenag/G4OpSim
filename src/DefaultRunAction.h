
// -----------------------------------------------------------------------------
//  G4Basic | DefaultRunAction.h
//
//  User run action class.
// -----------------------------------------------------------------------------

#ifndef DEFAULT_RUN_ACTION_H
#define DEFAULT_RUN_ACTION_H

#include <G4UserRunAction.hh>

class G4Run;


class DefaultRunAction: public G4UserRunAction
{
public:
  DefaultRunAction();
  virtual ~DefaultRunAction();
  virtual void BeginOfRunAction(const G4Run*);
  virtual void EndOfRunAction(const G4Run*);
};

inline DefaultRunAction::DefaultRunAction() {}
inline DefaultRunAction::~DefaultRunAction() {}

#endif