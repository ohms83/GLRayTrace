#pragma once

#include <string>
#include <vector>
#include <glm/glm.hpp>

/**
 * A utility class for output the screen buffer into PPM image file.
 */
class PPM
{
public:
    /// Write a PPM image to the specified @c filepath .
    static bool write(const std::string& filepath, const std::vector<glm::vec3>& pixels, size_t width, size_t height);
};