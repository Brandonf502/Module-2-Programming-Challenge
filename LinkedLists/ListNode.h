#pragma once
// Declare listNode object 

template <typename T> struct listNode {
	T data;
	listNode* next = nullptr;
};