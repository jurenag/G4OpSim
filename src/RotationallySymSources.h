#ifndef ROTATIONALLY_SYM_SOURCES_H
#define ROTATIONALLY_SYM_SOURCES_H

#include <string>

#include <G4ThreeVector.hh>
#include <G4SystemOfUnits.hh>

struct RSS{
  G4ThreeVector vertex_pos;
  std::string spectrum_filepath;
  std::string spectrum_name;
  std::string angular_dist_filepath;
  std::string angular_dist_name;
};

namespace AvailableRSS{
  static RSS LED325W2 = {G4ThreeVector(0., 10.*cm, 0.),
                                "./data/LED325W2-IvsLambda-TH1D.root",  //spectrum_filepath
                                "LED325W2_spectrum",                    //spectrum_name
                                "./data/LED325W2-IvsAngle-TH1D.root",   //angular_dist_filepath
                                "LED325W2_angular_pattern"              //angular_dist_name
                                };

  static RSS LED375L = {G4ThreeVector(0., 10.*cm, 0.),
                                "./data/LED375L-IvsLambda-TH1D.root",
                                "LED375L_spectrum",
                                "./data/LED375L-IvsAngle-TH1D.root",
                                "LED375L_angular_pattern"};

  static RSS LED430L = {G4ThreeVector(0., 10.*cm, 0.),
                                "./data/LED430L-IvsLambda-TH1D.root",
                                "LED430L_spectrum",
                                "./data/LED430L-IvsAngle-TH1D.root",
                                "LED430L_angular_pattern"};

  static RSS LED450LW = {G4ThreeVector(0., 10.*cm, 0.),
                                "./data/LED450LW-IvsLambda-TH1D.root",
                                "LED450LW_spectrum",
                                "./data/LED450LW-IvsAngle-TH1D.root",
                                "LED450LW_angular_pattern"}; 
}

#endif
