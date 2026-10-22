#pragma once

#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class LinkedList {
private:
	Node* head;

public:
	LinkedList() {
		head = nullptr;
	}

private:
	bool isEmpty() {
		return (head == nullptr);
	}

public:
	void Traverse() {
		if (isEmpty()) {
			cout << "\n--> LinkedList is empty.\n";
		}

		Node* current = head;

		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}

		cout << "\n";
	}

	void insertAtBegin(int data) {

		Node* newNode = new Node{ data };
		if (isEmpty()) {
			head = newNode;
			newNode->next = nullptr;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	void insertAtEnd(int data) {
		Node* current = head;
		Node* newNode = new Node{ data };

		while (current->next != nullptr) {
			current = current->next;
		}

		current->next = newNode;
		newNode->next = nullptr;
	}

	bool isFound(int data) {
		Node* current = head;

		while (current != nullptr) {
			if (current->data = data) {
				return true;
			}
		}

		return false;
	}

	int count() {
		int count = 0;

		Node* current = head;

		while (current != nullptr) {
			++count;
			current = current->next;
		}

		return count;
	}

	int countOfItem(int item) {

		if (!isFound(item)) {
			return 0;
		}

		int count = 0;

		Node* current = head;

		while (current != nullptr) {
			if (current->data == item) {
				++count;
			}

			current = current->next;
		}

		return count;
	}
};