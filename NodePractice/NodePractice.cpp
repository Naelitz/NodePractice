// NodePractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	int intRandomNumber = rand();
	Node theFirstNode;
	theFirstNode.SetValue(intRandomNumber);
	Node* pntCurrentNode;
	void AddRandomNumber(Node* theCurrentNode, int intRandomNumber);

	for (int intCounter = 0; intCounter < 100000; intCounter++)
	{
		pntCurrentNode = &theFirstNode;
		intRandomNumber = rand();
		AddRandomNumber(pntCurrentNode, intRandomNumber);

	}

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

