#include"pch.h"

map* read_map() {//先建立结点链表，再把所有边连上去
	FILE *fp = fopen("map.txt", "r");
	if (!fp)
		exit(-1);
	map *m = new_map();
	CAMPUS = m;
	char name[TEMP_SIZE];
	int cnt = 0, distance, view, green, node_num;
	fscanf(fp, "%d", &node_num);
	while (cnt++ < node_num) {
		fscanf(fp, "%s", name);
		adj_node *node = new_adj_node(name);
		add_node(m, node);
	}
	while (cnt--) {
		int side_num;
		fscanf(fp, "%d", &side_num);
		adj_node *node = m->node_tail->next;
		for (int i = 0; i < side_num; i++) {
			fscanf(fp, "%d%d%d%s", &distance, &view, &green, name);
			add_side(node, new_side_node(distance, view, green, from_name_to_node(name)));
		}
		node = node->next;
	}
	fclose(fp);
	return m;
}

void save_map(map *map) {
	FILE *fp = fopen("map.txt", "w");
	fprintf(fp, "%d ", map->node_num);
	adj_node *node = map->node_tail;
	if (!node)
		return;
	for (int i = 0; i < map->node_num; i++, node = node->next) {
		fprintf(fp, "%s ", node->name);
	}
	fprintf(fp, "\n");//写入所有地点名称
	for (int i = 0; i < map->node_num; i++, node = node->next) {
		side_node *side = node->side_tail;
		int cnt = 0;//统计每个结点的边数
		if (side) {
			for (cnt = 0, side = side->next; side != node->side_tail; cnt++, side = side->next);
			cnt++;
		}
		fprintf(fp, "%d", cnt);
		for (int i = 0; i < cnt; i++, side = side->next) {//写入每条边
			fprintf(fp, "%d %d %d %s", side->distance_value, side->view_value,
				side->green_value, side->des->name);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}