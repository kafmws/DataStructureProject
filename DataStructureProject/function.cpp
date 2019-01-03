#include"pch.h"

adj_node *from_name_to_node(map *map, char *name) {
	if (map->node_tail) {
		adj_node *node = map->node_tail->next;
		for (; node != map->node_tail; node = node->next)
			if (strcmp(name, node->name) == 0)
				return node;
		if (strcmp(name, node->name) == 0)
			return node;
	}
	return NULL;
}

adj_node *from_name_to_node(char *name) {
	if (!CAMPUS) {
		return from_name_to_node(CAMPUS, name);
	}
	return NULL;
}

side_node *get_road(map *m, char *from, char *des) {
	adj_node *begin = from_name_to_node(m, from);
	adj_node *end = from_name_to_node(m, des);
	side_node *side = begin->side_tail;
	if (side) {//±ß´æÔÚ
		if (side->des == end)
			return side;
		else
			for (side = side->next; side != begin->side_tail; side = side->next)
				if (side->des == end)return side;
	}
	return NULL;
}