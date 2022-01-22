#include "PPM.h"
#include <iostream>
#include <fstream>

using namespace std;

bool PPM::write(const string& filepath, const vector<glm::vec3>& pixels, size_t width, size_t height)
{
    const auto numPixel = pixels.size();
    if(numPixel < width * height)
    {
        std::cout << "Pixel data too small. Pixel count=" << numPixel << " Width=" << width << " Height=" << height << std::endl;
        return false;
    }

    ofstream outFile;
    outFile.open(filepath);
    if(!outFile.good())
    {
        std::cout << "Unable to create the output file. FILEPATH=" << filepath << std::endl;
    }

    outFile << "P3\n" << width << ' ' << height << "\n255\n";

    size_t index = 0;
    for(size_t i = 0; i < height; ++i)
    {
        for(size_t j = 0; j < width; ++j, ++index)
        {
            const auto& pixel = pixels[index];
            glm::vec3 rgb = glm::clamp(pixel, 0.0f, 255.0f);
            outFile << static_cast<int>(rgb.r) << ' ' << static_cast<int>(rgb.g) << ' ' << static_cast<int>(rgb.b) << '\n';
        }
    }

    return true;
}