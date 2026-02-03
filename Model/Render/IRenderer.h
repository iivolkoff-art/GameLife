#ifndef IRENDERER_H
#define IRENDERER_H

#include <vector>

class IRenderer {
public:
    virtual void render(const std::vector<std::vector<bool>>& grid) = 0;

    virtual ~IRenderer() = default;
};

#endif // IRENDERER_H
