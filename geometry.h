#ifndef GEOMETRY_H_
#define GEOMETRY_H_

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
class Geometry {
 public:
  Geometry(Parameters* params);

  virtual ~Geometry() = default;

  virtual int* set_point_type_normals(int* pt, Parameters* params) = 0;
  virtual float latice_Potential(const nni ni[7]) = 0;

  float newman_neighbours(const nni fullni[]);
  float second_nerghbours(const nni fullni[]);
  float third_nerghbours(const nni fullni[]);
  void Boundary_Init(Parameters* params);

  float (*bulk_potential)(float ni[3], float nj[3], Parameters* params, float rij[3], int nk);

  int Nx, Ny, Nz;
  int nSurfaces;
  float* ns;
  Parameters* params;
  std::vector<class Anchoring*> surfaces;
};

// Geometria tipo Bulk
class Bulk_Geometry : public Geometry {
 public:
  Bulk_Geometry(int* pt, Parameters* params);
  float latice_Potential(const nni ni[7]) override;

 private:
  int* set_point_type_normals(int* pt, Parameters* params) override;
};

// Geometria tipo Slab
class Slab_Geometry : public Geometry {
 public:
  Slab_Geometry(int* pt, Parameters* params);
  float latice_Potential(const nni ni[7]) override;

 private:
  int* set_point_type_normals(int* pt, Parameters* params) override;
};

// Geometria tipo Esfera
class Sphere_Geometry : public Geometry {
 public:
  Sphere_Geometry(int* pt, Parameters* params);
  float latice_Potential(const nni ni[7]) override;

 private:
  int* set_point_type_normals(int* pt, Parameters* params) override;
};

// Geometria personalizada
class Custom_Geometry : public Geometry {
 public:
  Custom_Geometry(int* pt, Parameters* params);
  float latice_Potential(const nni ni[7]) override;

 private:
  int* set_point_type_normals(int* pt, Parameters* params) override;
};

#endif  // GEOMETRY_H_
