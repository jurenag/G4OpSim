// -----------------------------------------------------------------------------
//  G4Basic | OpticalSD.cpp
//
//  Sensitive detector for optical sensors (e.g. SiPMs).
//   * Author: <justo.martin-albo@ific.uv.es>
//   * Creation date: 5 Nov 2020
// -----------------------------------------------------------------------------

#include "OpticalSD.h"

#include <G4SDManager.hh>
#include <G4VTouchable.hh>



OpticalSD::OpticalSD(const G4String& sdname):
  G4VSensitiveDetector(sdname)
{
  collectionName.insert(GetCollectionUniqueName());
}


OpticalSD::~OpticalSD()
{
}


void OpticalSD::Initialize(G4HCofThisEvent* hce)
{
  hc_ = new OpticalHitCollection(SensitiveDetectorName, GetCollectionUniqueName());
  G4int hc_id = G4SDManager::GetSDMpointer()->GetCollectionID(GetCollectionUniqueName());
  hce->AddHitsCollection(hc_id, hc_);
}


G4bool OpticalSD::ProcessHits(G4Step* aStep, G4TouchableHistory*)
{
  OpticalHit * aHit = new OpticalHit();
  const G4VTouchable * pt = aStep->GetPostStepPoint()->GetTouchable();
  aHit->SetSensorID(pt->GetReplicaNumber(pt->GetHistory()->GetDepth()-1));
  //Want to know the ID of each photosensor with regard to its placement over the world volume.
  hc_->insert(aHit);
  return true;
}

void OpticalSD::EndOfEvent(G4HCofThisEvent*)
{
  return;
}