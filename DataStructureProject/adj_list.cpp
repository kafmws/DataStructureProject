#include"pch.h"

void add_node(map *map, adj_node *node) {//��node����map��
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
	printf("������ص����ƣ�");
	scanf("%[^\n]", tem);
	add_node(map, new_adj_node(tem));
}

void add_side_test(map *map) {
	char begin[TEMP_SIZE], end[TEMP_SIZE];
	printf("��������ʼ������:");
	scanf("%s", begin);
	printf("������Ŀ�ĵ�����:");
	scanf("%s", end);
	printf("����������·�ĳ��ȡ���ɫ������������");
	int distance, view, green;
	scanf("%d %d %d", &distance, &view, &green);
	adj_node *from = from_name_to_node(map,begin);
	adj_node *des = from_name_to_node(map, end);
	add_side(from, new_side_node(distance, view, green, des));
	add_side(des, new_side_node(distance, view, green, from));//˫���·
}