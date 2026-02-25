#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"

int main() {
    Position pos;
    Statistic stat;
    // Hammer hammer1;
    // Shovel shovel1;
    // Worker w("Saruka", pos, stat, &hammer1);
    // w.setTool(&shovel1);
    // w.setTool(&shovel1);
    // w.removeTool(&shovel1);
    // w.removeTool(&shovel1);
    // w.removeTool(&hammer1);
    // w.removeTool(&hammer1);
    // cout << w.getTool("Shovel") << endl;
    // cout << w.getTool("Hammer") << endl;
    
    Shovel shovel2;
    Hammer hammer2;

    Worker worker1("Reiko", pos, stat, &hammer2);
    Worker worker2("Satoshi", pos, stat, &hammer2);
    worker1.useTool(&hammer2);
    worker1.removeTool(&hammer2);
    worker2.useTool(&hammer2);
    worker2.useTool(&hammer2);
    worker2.useTool(&hammer2);
    worker2.useTool(&hammer2);
    worker2.useTool(&hammer2);
    worker2.removeTool(&hammer2);

    worker1.setTool(&shovel2);
    worker2.setTool(&shovel2);
    worker1.setTool(&shovel2);
    worker2.setTool(&shovel2);
    worker2.useTool(&shovel2);
    worker2.useTool(&shovel2);
    worker2.useTool(&shovel2);
    worker1.useTool(&shovel2);
    worker2.useTool(&shovel2);
    worker2.useTool(&shovel2);
    worker2.removeTool(&shovel2);
    worker2.getTool("Shovel");    
    worker1.removeTool(&shovel2);
    worker1.getTool("Shovel");    
    
    // Worker aled("NoTool", pos, stat, &test1);
    // Shovel haha;
    // aled.setTool(&haha);
    // aled.setTool(&test1);
    // w.setTool(&test);
    // w.useTool(&test);
    // w.useTool(&test);
    // w.useTool(&test);
    // w.useTool(&test);
    // w.useTool(&test);
    
    return (0);
}
