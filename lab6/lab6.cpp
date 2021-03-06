#include <iostream>
#include <sys/time.h>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <chrono>
#include "tree.h"
using namespace std;

int main (){
	struct timeval start,finish;
	// ======Test for single functions======
/*
	Tree t;
	int brr[] = {5,2,8,6,60,42,37,65,61,70,63,64};
	for (int i = 0; i<12; i++){
		t.insert(brr[i]);
	}

	int count = 0;
	for (int i =0; i<100; i++){
		if (t.find(i)!=NULL){
			count ++ ;
		}
	}
	cout << "Count: " << count << endl;

	if(t.remove(60)){
		cout << "Success" << endl;
	}

	count = 0;
	for (int i =0; i<100; i++){
		if (t.find(i)!=NULL){
			cout << i << endl;
			count ++ ;
		}
	}
	cout << "Count: " << count << endl;

	count = 0;
	t.remove(61);
	for (int i =0; i<100; i++){
		if(t.find(i)!=NULL) {
			count ++;
			cout << i << endl;
		}
	}
	cout << "Count: " << count << endl;
	*/

	int arr[100000];
	for (int i = 0; i<100000; i++){
		 arr[i] = i+1;
	}

	//Generate in-order 
	Tree t1;
	for (int i = 0; i<100000; i++){
		t1.insert(arr[i]);
	}

	//Generate random
	random_shuffle (&arr[0], &arr[99999]);
	Tree t2;
	for (int i=0; i<100000; i++){
		t2.insert(arr[i]);
	}

	//Tests:
	//10,000 node tree, in-order insertion=====================================
	gettimeofday(&start,NULL);
 	for(int i=0;i<100000;i++){
		if (i%10000 ==0){
			t1.find(i)!=0;
		}
 	}

	gettimeofday(&finish,NULL);
	double totalTime =  (double)((double)(finish.tv_sec - start.tv_sec) *  1000000  + (double)(finish.tv_usec - start.tv_usec)) / (double)1000000;
	cout << "in-order insertion: " << endl << "Each find() call on a 100000 node BST takes " << totalTime/10 << " seconds." << endl;

	//10,000 node tree, random insertion=====================================
	gettimeofday(&start,NULL);
 	for(int i=0;i<100000;i++){
		if (i%10000 ==0){
			t2.find(i)!=0;
		}
 	}

	gettimeofday(&finish,NULL);
	totalTime =  (double)((double)(finish.tv_sec - start.tv_sec) *  1000000 + (double)(finish.tv_usec - start.tv_usec)) / (double)1000000;
	cout << "random insertion: " << endl << "Each find() call on a 100000 node BST takes " << totalTime/10 << " seconds." << endl;



	//Remove all the multiples of 4 from both trees
	for (int i = 1; i <=100000; i++){
		if (i%4==0){
			t1.remove(i);
			t2.remove(i);
		}
	}


	//75,000 node tree, in-order insertion=====================================
	gettimeofday(&start,NULL);

 	for(int i=0;i<100000;i++){
		if (i%10000 ==0){
			t1.find(i)!=0;
		}
 	}

	
	gettimeofday(&finish,NULL);
	totalTime =  (double)((double)(finish.tv_sec - start.tv_sec) *  1000000 + (double)(finish.tv_usec - start.tv_usec)) / (double)1000000;
	cout << "in-order insertion: " << endl << "Each find() call on a 75000 node BST takes " << totalTime/10 << " seconds." << endl;



	//75,000 node tree, random insertion=====================================
	gettimeofday(&start,NULL);
 	for(int i=0;i<100000;i++){
		if (i%10000 ==0){
			t2.find(i)!=0;
		}
 	}

	gettimeofday(&finish,NULL);
	totalTime =  (double)((double)(finish.tv_sec - start.tv_sec) *  1000000 + (double)(finish.tv_usec - start.tv_usec)) / (double)1000000;
	cout << "random insertion: " << endl << "Each find() call on a 75000 node BST takes " << totalTime/10 << " seconds." << endl;



	//Remove all the multiples of 2 from both trees
	for (int i = 1; i<=100000; i++){
		if (i%2==0){
			t1.remove(i);
			t2.remove(i);
		}
	}


	//50,000 node tree, in-order insertion=====================================
	gettimeofday(&start,NULL);
 	for(int i=0;i<100000;i++){
		if (i%10000 ==0){
			t1.find(i)!=0;
		}
 	}
	gettimeofday(&finish,NULL);
	totalTime =  (double)((double)(finish.tv_sec - start.tv_sec) *  1000000 + (double)(finish.tv_usec - start.tv_usec)) / (double)1000000;
	cout << "in-order insertion: " << endl << "Each find() call on a 50000 node BST takes " << totalTime/10 << " seconds." << endl;

	//50,000 node tree, random insertion=====================================
	gettimeofday(&start,NULL);
 	for(int i=0;i<100000;i++){
		if (i%10000 ==0){
			t2.find(i)!=0;
		}
 	}

	gettimeofday(&finish,NULL);
	totalTime =  (double)((double)(finish.tv_sec - start.tv_sec) *  1000000 + (double)(finish.tv_usec - start.tv_usec)) / (double)1000000;
	cout << "random insertion: " << endl << "Each find() call on a 50000 node BST takes " << totalTime/10 << " seconds." << endl;


	int count = 0;
	for (int i=0; i<100000; i++){
		if (t2.find(i)) count ++;
	}
	
	cout <<"Count :  " << count << endl;
}
