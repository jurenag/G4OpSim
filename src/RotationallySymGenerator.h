#ifndef ROTATIONALLY_SYM_GENERATOR_H
#define ROTATIONALLY_SYM_GENERATOR_H

#include <G4VUserPrimaryGeneratorAction.hh>
#include <G4Event.hh>

#include <TH1D.h>
#include <TFile.h>

#include "RotationallySymSources.h"

class RotationallySymGenerator: public G4VUserPrimaryGeneratorAction
{
  //Objects of this class implement rotationally symmetric optical photon sources which 
  //are uniquely characterized by two separate distributions. A 1-d POLAR angular 
  //distribution and an energy distribution.

  public:
    RotationallySymGenerator();
    virtual ~RotationallySymGenerator();

    void BuildGenerator(RSS);
    inline TH1D* GetSpectrum() {return spectrum;}
    inline TH1D* GetAngularDist() {return angular_dist;}

    void GeneratePrimaries(G4Event*) override;

  private:
    TFile* sFile;
    TFile* aFile;
    G4ThreeVector vertex_pos;
    TH1D* spectrum;
    TH1D* angular_dist;
    G4bool generatorIsReady;
};

#endif