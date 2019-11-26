# CMSBWT
## Introduction
CMSBWT is a C++ library implementation for using Multi String BWTs based on the python library
[msbwt](https://github.com/holtjma/msbwt)
and is currently under development.
It currently implements a subset of functionality and does not utilize memory mapping when loading BWTs.
This leads to failed opens on large data sets.

## Installation and Testing

Clone this repository to begin the installation. 

### Without Tests

    cd cmsbwt
    mkdir build && cd build
    cmake ..
    make && make install
    
### With Tests

    cd cmsbwt
    mkdir build && cd build
    TEST_ARGS=/path/to/comp_msbwt.npy cmake ..
    make && make test
    # All tests pass
    make install
    
The installation will place the library and header files under /usr/local.
If this location is not already visible to linkers, you can add it to the appropriate paths.

An example demonstrating loading and querying a bwt is included in the ```example``` directory.


## Building the short-read BWT
Prior to using CMSBWT, a BWT of the short-read sequencing data needs to be constructed.
Currently, the implementation expects it to be in the Run-Length Encoded (RLE) format of the [*msbwt*](https://github.com/holtjma/msbwt) python package.
We recommend building the BWT using [*ropebwt2*](https://github.com/lh3/ropebwt2) by following the instructions on [Converting to the fmlrc RLE-BWT format](https://github.com/holtjma/fmlrc/wiki/Converting-to-the-fmlrc-RLE-BWT-format).
Alternatively, the *msbwt* package can directly build these BWTs ([Constructing the BWT wiki](https://github.com/holtjma/msbwt/wiki/Constructing-the-MSBWT)), but it may be slower and less memory efficient.

## Compiling with CMSBWT

Assuming the paths are set correctly, a binary using CMSBWT can be built with the command:

    clang++ -o <outname> -lcmsbwt <filename>.cpp
    
Otherwise, the locations can be specified directly:

    clang++ -o <outname> -I/usr/local/include -L/usr/local/lib -lcmsbwt <filename>.cpp
    

## Reference
Holt, James, and Leonard McMillan. "Merging of multi-string BWTs with applications." *Bioinformatics* (2014): btu584.

Holt, James, and Leonard McMillan. "Constructing Burrows-Wheeler transforms of large string collections via merging." *Proceedings of the 5th ACM Conference on Bioinformatics, Computational Biology, and Health Informatics.* ACM, 2014.

[Wang, Jeremy R. and Holt, James and McMillan, Leonard and Jones, Corbin D. FMLRC: Hybrid long read error correction using an FM-index. BMC Bioinformatics, 2018. 19 (1) 50.](https://bmcbioinformatics.biomedcentral.com/articles/10.1186/s12859-018-2051-3)
