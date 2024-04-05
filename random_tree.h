#include <vector>

std::vector<int> random_tree_with_root(int N, int r, std::vector<std::vector<int>> &adj);
void display_tree(int N, std::vector<int> next, bool to_stdout=false);
int get_call(void);