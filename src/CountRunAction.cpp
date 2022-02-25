// -----------------------------------------------------------------------------
//  G4Basic | CountRunAction.cpp
//
//  User run action class.
// -----------------------------------------------------------------------------

#include "CountRunAction.h"

#include <G4Run.hh>
#include <globals.hh>

CountRunAction::CountRunAction():
G4UserRunAction(), IDs(), counters()
{
}

CountRunAction::~CountRunAction()
{
}

void CountRunAction::BeginOfRunAction(const G4Run* run)
{
  G4cout << "------------------------------------------------------------\n"
         << "Run ID " << run->GetRunID() << G4endl;
}

void CountRunAction::EndOfRunAction(const G4Run*)
{
  DisplaySortedCounters();
  ResetCounters();
  G4cout << "End of run."
         << "------------------------------------------------------------"
         << G4endl;
}

void CountRunAction::IncrementACounter(G4int ID){
  G4int IDIterator = GetIDIterator(ID);
  if(IDIterator>-1){counters[IDIterator]++;}
  else{
    RegisterNewSensor(ID);
    IncrementACounter(ID);
  }
  return;
}

void CountRunAction::ResetCounters(){
  IDs.clear();
  counters.clear();
  return;
}

void CountRunAction::DisplayCounters(){
  G4cout << "*************************************" << G4endl;
  for(G4int i=0; i<IDs.size(); i++){
      G4cout << "Sensor with ID= " << IDs[i] << " registered " << counters[i] << " hits." << G4endl;
  }
  G4cout << "*************************************" << G4endl;
  return;
}

void CountRunAction::DisplaySortedCounters(){
  G4cout << "*************************************" << G4endl;
  std::vector<G4int> IDsCopy = IDs;
  std::vector<G4int> countersCopy = counters;
  G4int holder;
  for(G4int i=0; i<IDs.size(); i++){
    holder = minimum(IDsCopy);
    G4cout << "Sensor with ID= " << IDsCopy[holder] << " registered " << countersCopy[holder] << " hits." << G4endl;
    IDsCopy.erase(IDsCopy.begin()+holder);
    countersCopy.erase(countersCopy.begin()+holder);
  }
  G4cout << "*************************************" << G4endl;
  return;
}

void CountRunAction::RegisterNewSensor(G4int ID)
{
  if(!isTaken(ID)){
    IDs.push_back(ID);
    counters.push_back(0);
  }
  else{
    G4Exception("RunAction::RegisterNewSensor()", "0", 
    JustWarning, "Description: ID must be unique. A sensor has not been registered for counting.");
  }
}

G4bool CountRunAction::isTaken(G4int id_candidate)
{
  return GetIDIterator(id_candidate)>-1 ? true : false;
}

G4int CountRunAction::GetIDIterator(G4int id_candidate)
{
  G4int pos = -1;
  for(G4int i=0; i<IDs.size(); i++)
  {
    if(id_candidate==IDs[i]){
      pos=i;
      break;//IDs are unique.
    }
  }
  return pos;
  //Returns -1 if id_candidate does not match any known ID.
}

G4int CountRunAction::minimum(std::vector<G4int> aVector){
  G4int pos = 0;
  for(G4int i=1; i<aVector.size(); i++){
    if(aVector[i]<aVector[pos]){
      pos = i;
    }
  }
  return pos;
}