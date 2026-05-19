#include "StudyPlanner.h"
#include <string>
#include <iostream>

StudyPlanner::StudyPlanner()
{
	root = nullptr;
}
StudyPlanner::~StudyPlanner()
{
	destroyTree(root);
}
void StudyPlanner::insertHelper(Node*& root, std::string title, std::string dueDate)
{
    if (root == nullptr)
    {
        root = new Node;
        root->title = title;
        root->dueDate = dueDate;
        root->completed = false;
        root->left = nullptr;
        root->right = nullptr;
    }
    else if (title < root->title)
    {
        insertHelper(root->left,title,dueDate);
    }
    else if (title > root->title)
    {
        insertHelper(root->right,title,dueDate);
    }
    else
    {
        std::cout << "Duplicate task ignored." << std::endl;
    }
}
bool StudyPlanner::searchHelper(Node* root, std::string title) const
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->title == title)
    {
        return true;
    }
    else if ( title < root->title)
    {
        return searchHelper(root->left,title);
    }
    else
    {
        return searchHelper(root->right, title);
    }
}
void StudyPlanner::removeHelper(Node*& root, std::string title)
{
    if (root == nullptr)
    {
        return;
    }

    if (title < root->title)
    {
        removeHelper(root->left,title);
    }
    else if (title > root->title)
    {
        removeHelper(root->right, title);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            Node* successor = root->right;

            while (successor->left != nullptr)
            {
                successor = successor->left;
            }

            root->title = successor->title;
            root->dueDate = successor->dueDate;
            root->completed = successor->completed;

            removeHelper(root->right, successor->title);
        }
    }
}
void StudyPlanner::inorderHelper(Node* root) const
{

}
void StudyPlanner::preorderHelper(Node* root) const
{

}
void StudyPlanner::postorderHelper(Node* root) const
{

}
void StudyPlanner::destroyTree(Node*& root)
{

}
void StudyPlanner::printPlannerHelper(Node* root) const
{

}
void StudyPlanner::markCompleteHelper(Node* root, std::string title)
{

}
void StudyPlanner::addTask(std::string title, std::string dueDate)
{

}
bool StudyPlanner::searchTask(std::string title) const
{

}
void StudyPlanner::remove(std::string title)
{

}
void StudyPlanner::displayInorder() const
{
	inorderHelper(root);
}
void StudyPlanner::displayPreorder() const
{
	preorderHelper(root);
}
void StudyPlanner::displayPostorder() const
{
	postorderHelper(root);
}
void StudyPlanner::printPlanner() const
{
	printPlannerHelper(root);
}