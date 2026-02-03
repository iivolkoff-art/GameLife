#ifndef CONSOLERENDER_H
#define CONSOLERENDER_H

#include "IRenderer.h"

class ConsoleRender : public IRenderer {
public:
    void render(const std::vector<std::vector<bool>>& grid) override;
};
#endif // CONSOLERENDER_H
