#pragma once

adj_node * new_adj_node(char * tem);

side_node * new_side_node(int distance, int view, int green, adj_node* des);

map * new_map();
