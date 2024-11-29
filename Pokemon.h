/*
    author Alek Presley
    filename: Pokemon.h
    purpose: data class/overload operators
*/
#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <string>
#include <iomanip> 
#include "BinaryTree.h"
#include "Pokemon.h"
using namespace std;

class Pokemon{
    private:
        int PokemonIndex;
        string PokemonName;
    
    public:
    //constructer
        Pokemon(){
            PokemonIndex = 0;
            PokemonName = "None";
        }
        //getters and setters
        void setID(int ID){
            PokemonIndex = ID;
        }
        void setName(string Pname){
            PokemonName = Pname;
        }
        int getID(){
            return PokemonIndex;
        }
        string getName(){
            return PokemonName;
        }
        //overload for the insert in the binary treee
        bool operator<(const Pokemon& pokemon){
            if(getID() < pokemon.PokemonIndex){ //getting id to comapre
                return true;
            }
            else{
                return false;
            }
        }
        //overload for the search
        bool operator==(const Pokemon& pokemon){
            if(getID() == pokemon.PokemonIndex){ //getting id to compare
                return true;
            }
            else{
                return false;
            }
        }
        //ostream overload that prints the lot details when the object is attempted to be printed as a node.
        friend ostream& operator<<(ostream& os, const Pokemon& pokemon){
            os << "\nPokemon Index Number: " << setw(2)<<pokemon.PokemonIndex << "\t\tName: " << pokemon.PokemonName;
            return os;
        }  



};
#endif