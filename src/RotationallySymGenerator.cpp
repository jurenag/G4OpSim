#include "RotationallySymGenerator.h"  

#include <G4SystemOfUnits.hh>
#include <G4PhysicalConstants.hh>
#include <globals.hh>
#include <G4PrimaryParticle.hh>
#include <G4PrimaryVertex.hh>
#include <G4RandomDirection.hh>
#include <G4OpticalPhoton.hh>

RotationallySymGenerator::RotationallySymGenerator():
sFile(nullptr), aFile(nullptr), vertex_pos(0., 0., 0.), spectrum(nullptr), angular_dist(nullptr), generatorIsReady(false)
{
}

RotationallySymGenerator::~RotationallySymGenerator()
{
  if(generatorIsReady){
    sFile->Close();
    aFile->Close();
  }
}

void RotationallySymGenerator::BuildGenerator(RSS source){
  if(generatorIsReady){
    G4Exception("RotationallySymGenerator::BuildGenerator", "0", JustWarning,
    "Description: Overwriting an already built generator.");
    sFile->Close();
    aFile->Close();
    sFile = TFile::Open(source.spectrum_filepath.c_str());
    spectrum = dynamic_cast<TH1D*>(sFile->Get(source.spectrum_name.c_str()));
    aFile = TFile::Open(source.angular_dist_filepath.c_str());
    angular_dist = dynamic_cast<TH1D*>(aFile->Get(source.angular_dist_name.c_str()));
    vertex_pos = source.vertex_pos;
  }
  else{
    sFile = TFile::Open(source.spectrum_filepath.c_str());
    spectrum = dynamic_cast<TH1D*>(sFile->Get(source.spectrum_name.c_str()));
    aFile = TFile::Open(source.angular_dist_filepath.c_str());
    angular_dist = dynamic_cast<TH1D*>(aFile->Get(source.angular_dist_name.c_str()));
    vertex_pos = source.vertex_pos;
    generatorIsReady=true;
  }
}

void RotationallySymGenerator::GeneratePrimaries(G4Event* event)
{  
  //Azimuthal angle is uniformly sampled from [0,twopi]
  G4double phi = twopi*G4UniformRand();
  
  //Polar angle is sampled from the manufacturer's info
  G4double theta = (angular_dist->GetRandom())*(pi/180.0);
  
  //Kinetic energy is sampled from the manufacturer's info
  G4double wavelength = spectrum->GetRandom()*nm;
  G4double kinetic_energy =  h_Planck*c_light/wavelength;

  G4double cosp = std::cos(phi);
  G4double sinp = std::sin(phi);

  G4double cost = std::cos(theta);
  G4double sint = std::sin(theta);

  G4double px = sint*cosp;
  G4double py = -cost;
  G4double pz = sint*sinp;

  G4ThreeVector momentum(px, py, pz);

  G4double sx = cost*cosp;
  G4double sy = sint;
  G4double sz = cost*sinp;

  //polarization is just a perpendicular vector to momentum
  G4ThreeVector polarization(sx, sy, sz);

  //perp, polarization and momentum are a cartesian basis
  G4ThreeVector perp = momentum.cross(polarization);

  //The actual polarization is a normalized random combination of perp and polarization
  phi  = twopi*G4UniformRand();
  sinp = std::sin(phi);
  cosp = std::cos(phi);

  polarization = cosp * polarization + sinp * perp;
  polarization = polarization.unit();
  
  //Create a new photon
  G4PrimaryParticle * particle = new G4PrimaryParticle(G4OpticalPhoton::Definition());
  particle->SetMomentumDirection(momentum);
  particle->SetPolarization(polarization);
  particle->SetKineticEnergy(kinetic_energy);

  G4PrimaryVertex* vertex = new G4PrimaryVertex(vertex_pos, 0.);
  vertex->SetPrimary(particle);

  event->AddPrimaryVertex(vertex);
}