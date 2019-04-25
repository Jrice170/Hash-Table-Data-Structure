/* main and it's supporting extras
 */

#include "MyUnorderedMap.h"


int main()
{
    MyUnorderedMap<std::string, int> virus_tree;
    get_virus_frequency(virus_tree);
    virus_tree.print();

    return 0;
}

