#ifndef STUDY_PLANNER_H
#define STUDY_PLANNER_H

#include <string>

class StudyPlanner
{
private:
	struct Node
	{
		std::string title;
		std::string dueDate;
		bool completed;

		Node* left;
		Node* right;
	};

	Node* root;

	void insertHelper(Node*& root, std::string title, std::string dueDate);
	bool searchHelper(Node* root, std::string title) const;
	void removeHelper(Node*& root, std::string title);
	void markCompleteHelper(Node* root, std::string title);

	void inorderHelper(Node* root) const;
	void preorderHelper(Node* root) const;
	void postorderHelper(Node* root) const;

	void destroyTree(Node*& root);
	void printPlannerHelper(Node* root) const;

public:
	StudyPlanner();
	~StudyPlanner();

	void addTask(std::string title, std::string dueDate);
	bool searchTask(std::string title) const;
	void markComplete(std::string title);
	void remove(std::string title);

	void displayInorder() const;
	void displayPreorder() const;
	void displayPostorder() const;

	void printPlanner() const;

};
#endif