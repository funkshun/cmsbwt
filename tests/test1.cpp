//C headers
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <assert.h>

//C++ headers
#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>
#include <iostream>

//Custom headers
#include "alignment_util.h"
#include "base_bwt.h"
#include "csa_bwt.h"
#include "file_iterators.h"
#include "rle_bwt.h"
#include "string_util.h"

int main(int argc, char* argv[]) {

  string_util::initializeStringUtil();

  char* bwtFN = argv[1];
  BaseBWT * rle = new RLE_BWT(bwtFN, 9);


  unsigned char kmer[20];
  kmer[0] = 0;


  bwtRange r = rle->findIndicesOfStr(kmer, 1L);
  uint64_t c = rle->countKmer(kmer, 1L);
  assert(r.l != r.h);
  assert(c > 0);
  //assert(0);
}
