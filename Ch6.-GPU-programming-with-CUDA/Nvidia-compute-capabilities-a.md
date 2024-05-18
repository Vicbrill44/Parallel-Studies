# Nvidia compute capabilities and device architectures

Created: 2024-05-07 22:35:05 -0400

Modified: 2024-05-11 19:41:20 -0400

---

-   Read this to gain a better understanding of the capabilities of your NVIDIA GPU

-   In NVIDIA's CUDA architecture, Compute Capability is a version number that indicates the features and capabilities supported by a particular GPU architecture. It is represented as a two-part number: X.Y, where X is the major version and Y is the minor version.

-   Key Aspects of Compute Capability:

    -   GPU Architecture Generation:

        -   The major version (X) indicates the GPU architecture generation (e.g., Kepler, Maxwell, Pascal, Volta, Turing, Ampere).

        -   The minor version (Y) provides information about specific features within that generation.

    -   Features and Functionality:

        -   Compute Capability defines which features are supported by the GPU hardware, such as:

        -   Maximum number of threads per block.

        -   Maximum grid dimensions.

        -   Warp size (number of threads per warp).

        -   Support for specific instructions (e.g., double-precision, tensor cores).

        -   Hardware acceleration features.

-   I have on my laptop a 3050ti which has a 7.5 compute capability

    -   This means that

        -   Warp size: 32 threads

        -   Maximum number of threads per block: 1024

        -   Maximum x-dimension of a block: 1024

        -   Maximum y-dimension of a block: 1024

        -   Maximum z-dimension of a block: 64

        -   Maximum shared memory per block: 64 KB

        -   Maximum registers per block: 65,536

        -   Maximum grid dimensions: (2^31 - 1, 65535, 65535)

        -   Cooperative groups

        -   Independent thread scheduling

        -   AMONG OTHER FEATURES

