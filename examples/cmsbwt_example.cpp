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

//Custom header
#include <cmsbwt.h>

int main(int argc, char* argv[]) {

  string_util::initializeStringUtil();

  char* bwtFN = argv[1];
  BaseBWT * rle = new RLE_BWT(bwtFN, 9);


  unsigned char kmer[20];
  // Convert Search Character to Int Encoding
  kmer[0] = string_util::STRING_TO_INT['$'];


  bwtRange r = rle->findIndicesOfStr(kmer, 1L);
  uint64_t c = rle->countKmer(kmer, 1L);
  printf("%d, %d\n", r.l, r.h);
  printf("%d", c);

  return 0;
}
