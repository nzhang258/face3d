#ifndef __HEADER_FACE_RESHAPE_H__
#define __HEADER_FACE_RESHAPE_H__

#include <string>
#include <vector>

struct Vertex {
  float x,y,z;

  Vertex() : x(0), y(0), z(0) {}
  Vertex(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

struct TriIndex {
  int a, b, c;

  TriIndex() : a(-1), b(-1), c(-1) {}
  TriIndex(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};

struct ModelShape {
  std::vector<Vertex> v;
  std::vector<TriIndex> f;
  bool write(std::ofstream &ofs);
  bool load(std::ifstream &ifs);
};

bool load_modelshape(const char *filename, ModelShape &shape);
bool save_modelshape(const char *filename, ModelShape &shape);

#endif

