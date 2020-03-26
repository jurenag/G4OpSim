// -----------------------------------------------------------------------------
//  G4OpSim | OpticalMaterialProperties.h
//
//  * Author:
//  * Creation date: 26 March 2020
// -----------------------------------------------------------------------------

#ifndef OPTICAL_MATERIAL_PROPERTIES_H
#define OPTICAL_MATERIAL_PROPERTIES_H

#include <G4Types.hh>
#include <G4SystemOfUnits.hh>

class G4MaterialPropertiesTable;


namespace OpticalMaterialProperties {

  const G4double min_energy =  2.0 * eV;
  const G4double max_energy = 12.0 * eV;

  G4MaterialPropertiesTable* Vacuum();

} // end namespace

#endif