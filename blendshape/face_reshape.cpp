#include "face_reshape.h"

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>

#include <Eigen/Dense>

bool load_modelshape(const char *filename, ModelShape &shape) {
  std::ifstream ifs(filename);
  int v_n, f_n;
  if(!ifs) {
    printf("%s failed to open %s\n",__func__,filename);
	return false;
  }

  ifs >> v_n >> f_n;
  shape.v.resize(v_n);
  shape.f.resize(f_n);
  for (int i = 0; i<v_n; ++i) {
    Vertex &vert = shape.v[i];
	ifs >> vert.x >>vert.y >> vert.z;
  }
  for (int i=0; i<f_n; ++i) {
    TriIndex &t = shape.f[i];
	ifs >> t.a >> t.b >> t.c;
  }
  
  ifs.close();

  return true;
}

bool save_modelshape(const char *filename, ModelShape &shape) {
  FILE *ofs = fopen(filename, "w");
  if(!ofs) {
    printf("%s failed to open %s\n", __func__, filename);
	return false;
  }

  for (auto vert : shape.v) {
    fprintf(ofs, "v %f %f %f\n", vert.x, vert.y, vert.z);
  }

  for (auto t : shape.f) {
    fprintf(ofs, "f %d %d %d\n", t.a, t.b, t.c);
  }

  fclose(ofs);

  return true;
}

