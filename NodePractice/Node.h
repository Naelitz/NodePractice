#pragma once
class Node
{
public:
	int intValue;
	int intOccurences = 1;
	Node* rightNode;
	Node* leftNode;
	Node* lastNode;
	void SetValue(int intValue);
	int GetValue();
	void SetRightNode(Node* theNode);
	void SetLeftNode(Node* theNode);
	void SetLastNode(Node* theNode);
	void IncrementOccurence();
	Node* GetLeftNode();
	Node* GetRightNode();
	Node* GetLastNode();
	Node();
	~Node();
};

