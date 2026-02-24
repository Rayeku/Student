#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"

int main() {
    Position pos;
    Statistic stat;
    Hammer hammer;
    Shovel shovel;
    Worker w("Worker 1", pos, stat, &hammer);
    w.setTool(&shovel);
    w.setTool(&shovel);
    w.removeTool(&shovel);
    w.removeTool(&shovel);
    w.removeTool(&hammer);
    w.removeTool(&hammer);
    
    Worker z;
    Hammer test;
    Shovel test1;
    w.setTool(&test);
    z.setTool(&test);
    w.setTool(&test1);

    w.useTool(&test);
    w.useTool(&test1);
    w.useTool(&test1);
    w.useTool(&test1);
    w.useTool(&test1);
    w.useTool(&test1);

    // w.useTool(&test);
    // w.useTool(&test);
    // w.useTool(&test);
    // w.useTool(&test);
    // w.useTool(&test);
    
    return (0);
}
