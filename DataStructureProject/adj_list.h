#pragma once

struct _adj_node;

typedef struct _side_node {
	int distance_value;
	int view_value;
	int green_value;
	struct _adj_node *des;
	struct _side_node *next;
}side_node;

typedef struct _adj_node{
	char *name;
	struct _adj_node *next;
	side_node *side_tail;//��ͷ���ĵ���ѭ������
}adj_node;

typedef struct adjList {
	adj_node *node_tail;//��ͷ���ĵ���ѭ������
	int node_num;//�����
	int side_num;//����
}adj_list;

typedef adj_list map;

map *CAMPUS = NULL;

void add_node(map * map, adj_node * node);

void add_side(adj_node * node, side_node * side);

void add_node_test(map * map);

void add_side_test(map * map);
