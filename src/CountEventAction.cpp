// -----------------------------------------------------------------------------
//  G4Basic | CountEventAction.cpp
//
//  User event action class.
// -----------------------------------------------------------------------------

#include "CountEventAction.h"
#include "OpticalHit.h"
#include "OpticalSD.h"
#include "CountRunAction.h"

#include <G4RunManager.hh>
#include <G4SDManager.hh>
#include <G4HCofThisEvent.hh>


void CountEventAction::BeginOfEventAction(const G4Event*)
{
}

void CountEventAction::EndOfEventAction(const G4Event* anEvent)
{
    G4RunManager* pRunManager = G4RunManager::GetRunManager();    
    G4int hc_id = G4SDManager::GetSDMpointer()->GetCollectionID(OpticalSD::GetCollectionUniqueName());
    G4HCofThisEvent* hce = anEvent->GetHCofThisEvent();
    OpticalHitCollection* hc = dynamic_cast<OpticalHitCollection*>(hce->GetHC(hc_id));
    for(G4int i=0; i<hc->GetVector()->size(); i++){
        OpticalHit* aHit = dynamic_cast<OpticalHit*>((*(hc->GetVector()))[i]);
        G4int id = aHit->GetSensorID();
        dynamic_cast<CountRunAction*>(
            const_cast<G4UserRunAction*>(
                pRunManager->GetUserRunAction()
                ))->IncrementACounter(id);
    }
    return;
}