#include"pch.h"

void add_node(map *map, adj_node *node) {//将node连到map中
	if (map->node_tail == NULL) {
		node->next = node;
	}
	else {
		node->next = map->node_tail->next;
		map->node_tail->next = node;	
	}
	map->node_tail = node;
}

void add_side(adj_node *node, side_node *side) {
	if (node->side_tail == NULL) {
		side->next = side;
	}
	else {
		side->next = node->side_tail->next;
		node->side_tail->next = side;
	}
	node->side_tail = side;
}

void add_node_test(map *map) {
	char tem[TEMP_SIZE];
	printf("请输入地点名称：");
	scanf("%[^\n]", tem);
	add_node(map, new_adj_node(tem));
}

void add_side_test(map *map) {
	char begin[TEMP_SIZE], end[TEMP_SIZE];
	printf("请输入起始地名称:");
	scanf("%s", begin);
	printf("请输入目的地名称:");
	scanf("%s", end);
	printf("请输入这条路的长度、景色级别、树荫量：");
	int distance, view, green;
	scanf("%d %d %d", &distance, &view, &green);
	adj_node *from = from_name_to_node(map,begin);
	adj_node *des = from_name_to_node(map, end);
	add_side(from, new_side_node(distance, view, green, des));
	add_side(des, new_side_node(distance, view, green, from));//双向道路
}