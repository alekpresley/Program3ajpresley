/*
    author Alek Presley
    filename: Driver.cpp
    purpose: Main file 
*/
#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "Pokemon.h"
#include <fstream>
using namespace std;
int main(){

    BinaryTree<Pokemon> Pokedex; //binary tree object that can contain Pokemon objects in each tree node
    int count = 0;
    string tempstring;
    string Pname;
    ifstream inFile;
    string inName = "pokedex.txt";
    inFile.open(inName);
    if(inFile.is_open()){ //if file can open
        while(getline(inFile, tempstring, '#')){ //while the file is able to grab a string
            int pokemonID = stoi(tempstring); // converts string to int for the opkemon id read from the file
            Pokemon pokemonObject;
            pokemonObject.setID(pokemonID); //sets the pokemon id
            getline(inFile, Pname, '#');
            pokemonObject.setName(Pname); //sets the name

            if(Pokedex.searchNode(pokemonObject) == false){ //if the search finds that its false to find 2 of the same then it will insert
                Pokedex.insertNode(pokemonObject);
                count++; //keeps up with pokemon
                cout << "\nInserting Pokemon with index " << pokemonObject.getID()  << " into the Pokedex.";
            }
            else{
                cout << "\n Oops!  The Pokemon with index "<< pokemonObject.getID() <<" is already in the Pokedex.";
            }


        }
    }
	inFile.close(); //closes file
    cout << endl << endl << endl << count << " Pokemon have been added to the Pokedex!\n\n\n\n\n"; //prints how many 
    cout << "********************POKEDEX:********************\n\n";
    Pokedex.displayInOrder(); //prints the display in order formate

    return 0;
}