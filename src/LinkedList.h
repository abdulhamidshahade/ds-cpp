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
	void traverse() {
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

		if (isEmpty()) {
			insertAtBegin(data);
			return;
		}

		while (current->next != nullptr) {
			current = current->next;
		}

		current->next = newNode;
		newNode->next = nullptr;
	}

	bool isFound(int data) {
		Node* current = head;

		while (current != nullptr) {
			if (current->data == data) {
				return true;
			}

			current = current->next;
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

		if (isEmpty()) {
			return 0;
		}

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

	void insertBeforeItem(int data, int item) {
		if (!isFound(item)) {
			cout << "\n-->The item is not found!\n";
		}
		if (count() == 1) {
			insertAtBegin(data);
			return;
		}
		Node* newNode = new Node{ data };
		Node* current = head;

		while (current->next->data != item) {
			current = current->next;
		}

		newNode->next = current->next;
		current->next = newNode;
	}

	void deleteAtBegin() {
		Node* current = head;

		if (isEmpty()) {
			cout << "\nThe linkedlist is empty!\n";
		}

		head = current->next;

		delete current;
	}
};