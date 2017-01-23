// NodePractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;

std::mt19937 mt;
std::uniform_int_distribution<int> dist(0, INT32_MAX);

int main()
{
	int intRandomNumber = dist(mt);
	int intLastPrintedNode;
	
	Node theFirstNode;
	theFirstNode.SetValue(intRandomNumber);
	Node* pntCurrentNode;
	void AddRandomNumber(Node* theCurrentNode, int intRandomNumber);
	void ReadNode(Node* theCurrentNode, int intLastPrintedNode);

	for (int intCounter = 0; intCounter < 10000; intCounter++)
	{
		pntCurrentNode = &theFirstNode;
		intRandomNumber = dist(mt);
		AddRandomNumber(pntCurrentNode, intRandomNumber);

	}
	pntCurrentNode = &theFirstNode;
	while (pntCurrentNode->GetLeftNode() != NULL)
	{
		pntCurrentNode = pntCurrentNode->GetLeftNode();
	}
	cout << "The number " << pntCurrentNode->GetValue() << " appeared " << pntCurrentNode->GetOccurences() << " times." << endl;
	intLastPrintedNode = pntCurrentNode->GetValue();
	ReadNode(pntCurrentNode, intLastPrintedNode);
    return 0;
}

void AddRandomNumber(Node* theCurrentNode, int intRandomNumber)
{
	if (intRandomNumber == theCurrentNode->GetValue())
	{
		theCurrentNode->IncrementOccurence();
		return;
	}
	else if (intRandomNumber > theCurrentNode->GetValue())
	{
		if (theCurrentNode->GetRightNode() == NULL)
		{
			theCurrentNode->SetRightNode(new Node);
			theCurrentNode->GetRightNode()->SetLastNode(theCurrentNode);
			theCurrentNode = theCurrentNode->GetRightNode();
			theCurrentNode->SetValue(intRandomNumber);
			return;
		}
		else
		{
			theCurrentNode = theCurrentNode->GetRightNode();
			AddRandomNumber(theCurrentNode, intRandomNumber);
		}
	}
	else
	{
		if (theCurrentNode->GetLeftNode() == NULL)
		{
			theCurrentNode->SetLeftNode(new Node);
			theCurrentNode->GetLeftNode()->SetLastNode(theCurrentNode);
			theCurrentNode = theCurrentNode->GetLeftNode();
			theCurrentNode->SetValue(intRandomNumber);
			return;
		}
		else
		{
			theCurrentNode = theCurrentNode->GetLeftNode();
			AddRandomNumber(theCurrentNode, intRandomNumber);
		}
	}
}

void ReadNode(Node* theCurrentNode, int intLastValue)
{
	if (theCurrentNode->GetValue() == intLastValue)
	{
		//todo: check right node, if null move up else move right
		if (theCurrentNode->GetRightNode() == NULL)
		{
			theCurrentNode = theCurrentNode->GetLastNode();
		}
		else
		{
			theCurrentNode = theCurrentNode->GetRightNode();
		}
		ReadNode(theCurrentNode, intLastValue);
	}
	else if (theCurrentNode->GetValue() < intLastValue)
	{
		//todo: move up the tree
		theCurrentNode = theCurrentNode->GetLastNode();
		ReadNode(theCurrentNode, intLastValue);
	}
	else if (theCurrentNode->GetValue() > intLastValue)
	{
		//todo: check the left node, if null print node else move left
		{
			if (theCurrentNode->GetLeftNode() == NULL || theCurrentNode->GetLeftNode()->GetValue() >= intLastValue)
			{
				cout << "The number " << theCurrentNode->GetValue() << " appeared " << theCurrentNode->GetOccurences() << " times." << endl;
				intLastValue = theCurrentNode->GetValue();
			}
			else
			{
				theCurrentNode = theCurrentNode->GetLeftNode();
			}
			ReadNode(theCurrentNode, intLastValue);
		}
	}
}

