#ifndef EVOL_H_
#define EVOL_H_

// Includes padrão
#include <iostream>

// Includes do projeto
#include "../include/define.h"
#include "../include/geometry.h"
#include "../include/parameters.h"
#include "../include/potential.h"

// Compatibilidade com CUDA
#ifdef CUDA__
#include <cuda_runtime.h>
#include <curand_kernel.h>
#else
// Simulação de dim3 para compilação em CPU
struct dim3 {
  uint x;
  uint y;
  uint z;
};
#endif

// Classe base
class Evolve {
 public:
  virtual int run() { return 0; }
  virtual float latice_Potential() { return 0; }
  void check_Points(int *pt, Parameters params);
  virtual void tester() {
    printf("here\n");
    fflush(stdout);
  }

 protected:
  unsigned int Nx, Ny, Nz;
  Geometry *geometry;
  int VallidPoints;
};

// Classe intermediária com lógica comum
class EvolveN : public Evolve {
 public:
  EvolveN(float *ni, int *pt, Parameters *params)
      : ni(ni), pt(pt), params(params),
        Nx(params->Nx), Ny(params->Ny), Nz(params->Nz) {}

  int run() override { return 0; }

  void Monte_Carlo_Step(float &ang_var, gsl_rng **r);
  void Monte_Carlo_Step_GPU(float &ang_var, gsl_rng *r);
  float energy_calculator();
  float energy_calculator_GPU();

 protected:
  dim3 tick;

#ifdef CUDA__
  curandState *d_rngStates = nullptr;
#endif

  int *d_pt = nullptr;
  float *d_T = nullptr;
  unsigned int *d_acc = nullptr;
  Parameters *d_params = nullptr;

  float *ni = nullptr;
  float *d_ni = nullptr;
  int *pt = nullptr;
  Parameters *params = nullptr;
};

// Classes especializadas
class thermalEvolveN : public EvolveN {
 public:
  thermalEvolveN(float *ni, int *pt, Parameters *params);
  int run() override;
  ~thermalEvolveN() = default;
};

class stepEvolveN : public EvolveN {
 public:
  stepEvolveN(float *ni, int *pt, Parameters *params);
  int run() override;
  ~stepEvolveN() = default;
};

class quenchEvolveN : public EvolveN {
 public:
  quenchEvolveN(float *ni, int *pt, Parameters *params);
  int run() override;
  ~quenchEvolveN() = default;
};

class electricEvolveN : public EvolveN {
 public:
  electricEvolveN(float *ni, int *pt, Parameters *params);
  int run() override;
  ~electricEvolveN() = default;
};

#endif  // EVOL_H_
