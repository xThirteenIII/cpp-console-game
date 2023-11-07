#include "RendererAdapter.h"

class NcursesAdapter: public RendererAdapter{
    public:
        void initialize() override;
        void finalize() override;
        void render() override;
        void handleInput() override;
};
