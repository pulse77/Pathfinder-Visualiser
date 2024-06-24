#pragma once
#include "utils.h"

struct Node
{

};

class Grid
{
public:
	Grid() = default;

	Grid(Vec2i size, float nodeSize) {
		createGrid(size, nodeSize);
	}

	~Grid() { delete m_nodes; }

	void createGrid(sf::Vector2i size, float nodeSize) {
		m_size = size;
		m_nodeSize = nodeSize;
		delete m_nodes; // makes sure to free memory if an instance of nodes already exist
		m_nodes = new Node[size.x * size.y];
	}

	Node& getNode(int x, int y) { return m_nodes[y * m_size.x + x]; }
	Node& getNode(Vec2i pos) { return getNode(pos.x, pos.y); }
	Vec2i getSize() const { return m_size; }
	float getNodeSize() const { return m_nodeSize; }

private:
	Node* m_nodes = nullptr;
	Vec2i m_size = {};
	float m_nodeSize{};
};