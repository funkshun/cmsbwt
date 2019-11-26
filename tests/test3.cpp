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
#include "rle_mmap.h"
#include "string_util.h"

int main(int argc, char* argv[]) {

  string_util::initializeStringUtil();

  char* bwtFN = argv[1];
  BaseBWT * norm = new RLE_BWT(bwtFN, 9);

  BaseBWT * mm = new RLE_MMAP(bwtFN, 9);


  unsigned char kmer[20];
  kmer[0] = 0;


  bwtRange nr = norm->findIndicesOfStr(kmer, 1L);
  uint64_t nc = norm->countKmer(kmer, 1L);

  bwtRange mr = mm->findIndicesOfStr(kmer, 1L);
  uint64_t mc = mm->countKmer(kmer, 1L);

  assert(nr.l == mr.l);
  assert(nr.h == mr.h);
  assert(nc == mc);
  //assert(0);
}
