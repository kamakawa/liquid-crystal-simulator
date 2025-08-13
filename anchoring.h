#ifndef ANCHORING_H_
#define ANCHORING_H_

// Includes padrão
#include <iostream>
#include <vector>
#include <gsl/gsl_rng.h>

// Includes do projeto
#include "../include/define.h"
#include "../include/io.h"
#include "../include/monte_carlo.h"
#include "../include/parameter_order.h"
#include "../include/parameters.h"
#include "../include/potential.h"

// Classe base
class Anchoring {
 public:
  char name[50];
  int id;
  Parameters* params;

  virtual char* getName() { return name; }
  virtual float surface_potential(float ni[3], float s[3]) { return 0.0f; }
  void check_parameter(bool std_val, std::string parameter_name);
};

// Classes derivadas

class Strong_Anchoring : public Anchoring {
 public:
  Strong_Anchoring(Parameters* params, int id);
  float W, theta_s, phi_s;
  char name[50] = "Strong Anchoring";

  char* getName() override { return name; }
  float surface_potential(float ni[3], float s[3]) override;
};

class RP_Anchoring : public Anchoring {
 public:
  RP_Anchoring(Parameters* params, int id);
  float W, theta_s, phi_s;
  char name[50] = "Rapine Papoular Anchoring";

  char* getName() override { return name; }
  float surface_potential(float ni[3], float s[3]) override;
};

class FG_Anchoring : public Anchoring {
 public:
  FG_Anchoring(Parameters* params, int id);
  float W, theta_s, phi_s;
  char name[50] = "Founier-Galatola like Anchoring";

  char* getName() override { return name; }
  float surface_potential(float ni[3], float s[3]) override;
};

class Homeotropic_Anchoring : public Anchoring {
 public:
  Homeotropic_Anchoring(Parameters* params, int id);
  float W, theta_s, phi_s;
  char name[50] = "Homeotropic Anchoring";

  char* getName() override { return name; }
  float surface_potential(float ni[3], float s[3]) override;
};

class Strong_Anchoring_GHRL : public Anchoring {
 public:
  Strong_Anchoring_GHRL(Parameters* params, int id);
  float W, theta_s, phi_s;
  char name[50] = "Strong Anchoring GHRL";

  char* getName() override { return name; }
  float surface_potential(float ni[3], float s[3]) override;
};

class RP_Anchoring_GHRL : public Anchoring {
 public:
  RP_Anchoring_GHRL(Parameters* params, int id);
  float W, theta_s, phi_s;
  char name[50] = "Rapine Papoular Anchoring GHRL";

  char* getName() override { return name; }
  float surface_potential(float ni[3], float s[3]) override;
};

class FG_Anchoring_GHRL : public Anchoring {
 public:
  FG_Anchoring_GHRL(Parameters* params, int id);
  float W, theta_s, phi_s;
  char name[50] = "Founier-Galatola like Anchoring GHRL";

  char* getName() override { return name; }
  float surface_potential(float ni[3], float s[3]) override;
};

class Homeotropic_Anchoring_GHRL : public Anchoring {
 public:
  Homeotropic_Anchoring_GHRL(Parameters* params, int id);
  float W, theta_s, phi_s;
  char name[50] = "Homeotropic Anchoring GHRL";

  char* getName() override { return name; }
  float surface_potential(float ni[3], float s[3]) override;
};

#endif  // ANCHORING_H_
