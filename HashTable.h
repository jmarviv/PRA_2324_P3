#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "PRA_2324_P1/ListLinked.h"  // he hecho una copia de la practica 1 dentro de esta
using namespace std;
template <typename V>
class HashTable: public Dict<V> {

	    private:
		    int n;
		    int max;
		    ListLinked<TableEntry<V>>* table;
		    int h(std::string key){
			    int aux=0;
			    int total=0;
			    for(char c:key){
				    aux+=int(c);
				    total++;
			    }
			    return (aux%total);
		    };
	    public:
		    HashTable(int size){
			    table = new ListLinked<TableEntry<V>>[size];
			    n = 0;
			    max = size;
		    };
		    ~HashTable(){
			    delete[] table;
		    };
		    int capacity(){
			    return max;
		    };
		    friend std::ostream& operator<<(std::ostream &out, HashTable<V>& th){
			    int i;
			    int max = th.capacity();
			    for (i=0;i<=max ;i++){
				    out << th.table.get(i)<<" ";
				    return out;
				};
		    };
		    V operator[](std::string key){
			    int i;
			    int max = this->capacity();
			    for (i=0;i<=max;i++){
				TableEntry<V> aux = table->get(i);    
				if (aux=!nullptr){
					return aux.value;
				}
			    }
			    throw std::invalid_argument("no existe dicha clave");
		    };
		    void insert (std::string key, V value){
			    int i;
			    int max = this->capacity();
			    int nfinal;
			    for(i=0;i<=max;i++){
				    TableEntry<V> aux = table->get(i);	
				    if(aux.key == key){
					    throw invalid_argument("esa clave ya existe");
				    };
				    if(aux == nullptr){
					    nfinal=i;
					    break;
				    };
			    };
			    TableEntry<V> newtableentry = new TableEntry<V>(key,value);
			    if (nfinal==i){
			    	this->table.insert(nfinal,newtableentry);
			    }
			    else{
				    throw invalid_argument("tabla llena");
			    };
		    };
		    V search (std::string key){
			    int i;
			    int max = this->capacity();
			    for(i=0;i<=max;i++){
				    TableEntry<V> aux = table.get(i);
				    if(aux.key == key){
					    return aux.data;
				    }
			    }
			    throw invalid_argument("no existe un valor con dicha clave");
		    };
		    V remove (std::string key){
			    int i;
			    int max = this->capacity();
			    for(i=0;i<=max;i++){
				    TableEntry<V> aux = table.get(i);
				    if(aux.key == key){
					    table.remove(i);
					    return aux.data;
				    }
			    }
			    throw invalid_argument("no existe un valor con dicha clave");
		    };
		    int entries(){
			    int i=0;
			    int max = this->capacity();
			    TableEntry<V> aux = table.get(i);
			    while (i!=max || aux!=nullptr){
				    i++;
				    TableEntry<V> aux = table.get(i); 
			    }
			    return i;
		    };

			    

};
#endif
