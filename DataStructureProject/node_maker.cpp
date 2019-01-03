#include"pch.h"
#include "node_maker.h"

adj_node *new_adj_node(char *tem) {
	adj_node* node = (adj_node *)malloc(sizeof(adj_node));
	node->next = NULL;
	node->side_tail = NULL;
	node->name = (char *)malloc(sizeof(char)*(strlen(tem) + 1));
	strcpy(node->name, tem);
	return node;
}

side_node *new_side_node(int distance, int view, int green, adj_node *des) {
	side_node *node = (side_node *)malloc(sizeof(side_node));
	node->distance_value = distance;
	node->view_value = view;
	node->green_value = green;
	node->des = des;
	node->next = NULL;
}

map *new_map() {
	map *m = (map *)malloc(sizeof(map));
	m->node_num = m->side_num = 0;
	m->node_tail = NULL;
	return m;
}