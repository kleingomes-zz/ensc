// ENSC482 - Homework 2
// Created by Klein Gomes on 2018-05-20.
// Copyright © 2018 Klein Gomes. All rights reserved.
//
// Problem 2(20)  
// Write a sorting algorithm using the provided tutorial. Show the result of the algorithm using two examples. 
// For one of the examples, sort the letters of your full name given that you associated numerical values to the 
// alphabets (i.e. A=1, B=2, C=3, …). The other example is to sort and stack 4 graphical blocks according to their 
// R value in their RGB color deceleration. The initial screen is the user specified colors of the random stack of 
// block and the final screen is the sorted stack. Supply the source code and sample results.


/*Problem 3 (20) –
Write a sorting algorithm using the provided tutorial. Show the result of the algorithm using two examples.
For one of the examples, sort the letters of your full name given that you associated numerical values to the
alphabets (i.e. A=1, B=2, C=3, …). Supply the source code and sample results.
*/

#include "stdafx.h"
#include <GL/glew.h>
#include <gl/freeglut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

using namespace std;


// Provided tutorial: This function was taken from the Introduction to Decision Theory PDF
void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
	// partition
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	// recursion
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}


//Quick Sort Implementation
void quickSort(int arr[], int low, int high);
char alphabet[27] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

int main()
{
	int chars[26], n, low, high, i, j;
	n = 0;
	char a[26];
	std::system("cls");
	cout << "**************************Quick Sort Algorithm Implementation*****************";
	cout << "Enter your name uncapitalized and without spaces: " << endl;
	cin.getline(a, sizeof(a));
	for (i = 0; a[i] != '\0'; i++)
	{
		cout << a[i] << " ";
	}
	cout << "" << endl;
	for (i = 0; a[i] != '\0'; i++)
	{
		for (j = 0; j < 26; j++)
		{
			if (a[i] == alphabet[j])
			{
				chars[n] = j;
				n++;
				break;
			}
		}
	}

	cout << "Initial Array:" << endl;
	for (i = 0; i < n; i++) 
	{
		cout << chars[i] << " ";
	}
	cout << "" << endl;
	high = n - 1;
	low = 0;
	std::system("cls");
	quickSort(chars, low, high);
	cout << "Sorted Array: " << endl;
	for (i = 0; i < n; i++)
	{
		cout << alphabet[chars[i]] << " ";
	}
	cout << endl;
	int wait;
	cin >> wait;
}