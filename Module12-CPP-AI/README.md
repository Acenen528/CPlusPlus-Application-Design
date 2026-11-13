// An example where C++ is used in a product is Unreal Engine. Many 3D video games are developed using Unreal Engine because
    rendering these games are very performance-consuming. Unreal Engine is able to use C++ for the performance boost in areas like 
    having direct communication to the hardware (for example GPUs and CPUs) and having more control of memory allocation.

// If my application BCI (brain computer interface) signal processing and classification app was built bigger and actually deployed in
    real-time signal classification, then C++ would come in useful. Python is more readable, but compared to C++, it is much slower. 
    In a real-time situation where the user needs feedback within milliseconds, my app would improve by using C++ by saving processing time.

// Here is an example that uses CPP to make more efficient code in my midterm project

    // INEFFICIENT EXAMPLE
    // If the given file name does not have .csv extension, add it.
    if (filename.length() < 4 || filename.substr(filename.length() - 4) != ".csv") {
        filename += ".csv";
    }

    I used that code in my midterm to validate file names given by users. But it's more efficient to use the version below.

    //EFFICIENT EXAMPLE
    if (!filename.ends_with(".csv")) {
        filename += ".csv";
    }

    This version is more efficient because it avoids creating a new temporary substring which saves memory space.