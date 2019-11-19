#include "face_reshape.h"

int main(int argc, char** argv) {

  ModelShape face;
  load_modelshape("../data/target/face.txt",face);
  save_modelshape("target.obj",face);

  return 0;
}
