/*
@Lab: Lab 5 BST
@Authors: Casey Merritt, Revanth Cherukuri
@Purpose: Show our Knowledge of a BST
@Contributions:We both worked together equally on all files; Partner: Casey Merritt; Effort: HIGH

@PseudoCode:
	int main(){
		ofstream ofile
		open(Output.txt)

		string x
		getline(x)

		ifstream ifile
		open(x)

		Bst<currency>* b = new Bst<currency>
		currency y

		while(ifile >> y){
			b.insert(y)
		}

		bool mainLoop = true
		while(mainLoop){
			cout << "1. add"
			cout << "2. remove"
			cout << "3. search"
			cout << "4. print"
			cout << "5. traverse"
			cout << "6. exit"

			int input = 0
			cin >> input

			if(input == 1){
				currency x
				cin >> x
				b.insert(x)
			}else if(input == 2){
				currency x
				cin >> x
				b.remove(x)
			}else if(input == 3){
				currency x
				cin >> x
				b.search(x)
			}else if(input == 4){
				b.print()
			}else if(input == 5){
				bool innerLoop = true
				while(innerLoop){
					cout << "1. Breadth First"
					cout << "2. In Order"
					cout << "3. Pre Order"
					cout << "4. Post Order"

					int input = 0;
					cin >> input

					if(input == 1){
						b.breadth()
						innerLoop = false
					}else if(input == 2){
						b.inorder()
						innerLoop = false
					}else if(input == 3){
						b.preorder()
						innerLoop = false
					}else if(input == 4){
						b.postorder()
						innerLoop = false
					}else{
						cout << "Incorrect value try again"
					}
			}else if(input == 6){
					mainLoop = false
				}
			}else{
				cout << "Wrong Value Try Again"
			}
		}

		b.print()
		delete b
		return 0
	}
*/


//#include "pch.h"//Needed for vis studio comment out if not on vis
#include "currency.h"
#include "Bst.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void DualWrite(ofstream&, string);

int main()
{
	ofstream ofile;
	ofile.open("Output.txt");
	DualWrite(ofile, "Please Enter Full Path For Input File: ");
	string x;
	getline(cin, x);

	ofile << x << endl;

	ifstream myFile;
	myFile.open(x);
	int count = 0;
	string line;

	while (getline(myFile, line)) {
		count++;
	}

	myFile.close();

	Bst<currency> *b = new Bst<currency>;
	currency* yeet = new currency;
	ifstream ifile;
	ifile.open(x);

	for (int i = 0; i < count; i++) {
		ifile >> yeet;
		b->insert(*yeet, b->root, ofile);
	}

	DualWrite(ofile, "");
	b->GetRoot(ofile);
	cout << "Current Count:  " << b->getCount() << endl;
	ofile << "Current Count: " << b->getCount() << endl;

	DualWrite(ofile, "");
	DualWrite(ofile, "Files Imported From: ");
	DualWrite(ofile, x);
	DualWrite(ofile, "");

	bool mainLoop = true;
	while (mainLoop) {
		DualWrite(ofile, "");
		DualWrite(ofile, "------- Welcome To Your Personal Bst Helper -------");
		DualWrite(ofile, "");

		bool innerLoop = true;
		while (innerLoop) {
			DualWrite(ofile, "");
			DualWrite(ofile, "What Would You Like To Do?: ");
			DualWrite(ofile, "1. Add");
			DualWrite(ofile, "2. Remove");
			DualWrite(ofile, "3. Search");
			DualWrite(ofile, "4. Print");
			DualWrite(ofile, "5. Traverse");
			DualWrite(ofile, "6. Exit");

			int x = 0;
			cin >> x;
			ofile << x << endl;

			if (x == 1) {
				DualWrite(ofile, "");
				DualWrite(ofile, "Enter Value You Want To Add: ");
				currency* y = new currency;
				cin >> y;
				ofile << *y << endl;
				b->insert(*y, b->root, ofile);
			}
			else if (x == 2) {
				DualWrite(ofile, "");
				DualWrite(ofile, "Enter Value You Want To Remove: ");
				currency* y = new currency;
				cin >> y;
				ofile << *y << endl;
				b->remove(*y, b->root, ofile);
			}
			else if (x == 3) {
				DualWrite(ofile, "");
				DualWrite(ofile, "Enter Value You Want To Search For: ");
				currency* y = new currency;
				cin >> y;
				ofile << *y << endl;
                if (b->search(*y, ofile) == 1) {
                    DualWrite(ofile, "This value exists in the tree ");
                }
                else {
                    DualWrite(ofile, "This value does not exist in the tree");
                }
			}
			else if (x == 4) {
				DualWrite(ofile, "");
				b->printBst(b->root, ofile);
				DualWrite(ofile, "");
			}
			else if (x == 5) {
				bool smallLoop = true;
				while (smallLoop) {
					DualWrite(ofile, "");
					DualWrite(ofile, "Select a traversal: ");
					DualWrite(ofile, "1. Breadth First\n2. In Order\n3. Pre Order\n4. Post Order");
					int input = 0;
					cin >> input;
					ofile << input << endl;
					if (input == 1) {
						DualWrite(ofile, "");
						DualWrite(ofile, "Breadth First Print:");
						b->breadthFirst(b->root, ofile);
						DualWrite(ofile, "");
						smallLoop = false;
					}
					else if (input == 2) {
						DualWrite(ofile, "");
						DualWrite(ofile, "In Order Print:");
						b->inOrder(b->root, ofile);
						DualWrite(ofile, "");
						smallLoop = false;
					}
					else if (input == 3) {
						DualWrite(ofile, "");
						DualWrite(ofile, "Pre Order Print:");
						b->preOrder(b->root, ofile);
						DualWrite(ofile, "");
						smallLoop = false;
					}
					else if (input == 4) {
						DualWrite(ofile, "");
						DualWrite(ofile, "Post Order Print:");
						b->postOrder(b->root, ofile);
						DualWrite(ofile, "");
						smallLoop = false;
					}
					else {
						DualWrite(ofile, "");
						DualWrite(ofile, "Sorry, that value isn't correct try again!");
					}
				}
			}
			else if (x == 6) {
				DualWrite(ofile, "");
				DualWrite(ofile, "Thank You Please Come Again!");
				DualWrite(ofile, "");

				mainLoop = false;
				innerLoop = false;
			}

			else {
				DualWrite(ofile, "");
				DualWrite(ofile, "Sorry that Value isn't correct try again!");
				DualWrite(ofile, "");
			}
		}


	}

	DualWrite(ofile, "");
	DualWrite(ofile, "Final Bst: ");
	DualWrite(ofile, "");
	b->printBst(b->root, ofile);

	DualWrite(ofile, "");
	DualWrite(ofile, "");
	DualWrite(ofile, "");
	DualWrite(ofile, "Exiting Program...");

	delete b;
	DualWrite(ofile, "");
	DualWrite(ofile, "Successfully deleted bst");
	DualWrite(ofile, "");


	ifile.close();
	ofile.close();

	system("pause");
	return 0;
}

/*
-- Writes to both an output file and screen
*/
void DualWrite(ofstream& out, string s) {
	out << s << endl;
	cout << s << endl;
}
