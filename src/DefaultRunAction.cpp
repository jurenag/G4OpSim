// -----------------------------------------------------------------------------
//  G4Basic | DefaultRunAction.cpp
//
//  User run action class.
// -----------------------------------------------------------------------------

#include "DefaultRunAction.h"

#include <G4Run.hh>


void DefaultRunAction::BeginOfRunAction(const G4Run* run)
{
  G4cout << "------------------------------------------------------------\n"
         << "Run ID " << run->GetRunID() << G4endl;
}

void DefaultRunAction::EndOfRunAction(const G4Run*)
{
  G4cout << "End of run."
         << "------------------------------------------------------------"
         << G4endl;
}