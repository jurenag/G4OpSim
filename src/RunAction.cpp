// -----------------------------------------------------------------------------
//  G4Basic | RunAction.cpp
//
//  User run action class.
// -----------------------------------------------------------------------------

#include "RunAction.h"
#include "RotationallySymGenerator.h"
#include "RotationallySymSources.h"

#include <G4Run.hh>
#include <G4RunManager.hh>


void RunAction::BeginOfRunAction(const G4Run* run)
{
  G4cout << "------------------------------------------------------------\n"
         << "Run ID " << run->GetRunID() << G4endl;
         //Build your RotationallySymGenerator 
         dynamic_cast<RotationallySymGenerator*>(
           const_cast<G4VUserPrimaryGeneratorAction*>(
             G4RunManager::GetRunManager()->GetUserPrimaryGeneratorAction()
             ))->BuildGenerator(AvailableRSS::LED375L);
}

void RunAction::EndOfRunAction(const G4Run*)
{
  G4cout << "End of run."
         << "------------------------------------------------------------"
         << G4endl;
}
